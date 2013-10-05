/**************************************************************************
**
** Adapted: 2013 Aries Abdelkrime (kariminfo0@gmail.com)
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact:  Qt Software Information (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
**************************************************************************/

#include "helpviewer.h"


QT_BEGIN_NAMESPACE

class HelpNetworkReply : public QNetworkReply
{
public:
    HelpNetworkReply(const QNetworkRequest &request, const QByteArray &fileData,
        const QString &mimeType);

    virtual void abort();

    virtual qint64 bytesAvailable() const
        { return data.length() + QNetworkReply::bytesAvailable(); }

protected:
    virtual qint64 readData(char *data, qint64 maxlen);

private:
    QByteArray data;
    qint64 origLen;
};

HelpNetworkReply::HelpNetworkReply(const QNetworkRequest &request,
        const QByteArray &fileData, const QString &mimeType)
    : data(fileData), origLen(fileData.length())
{
    setRequest(request);
    setOpenMode(QIODevice::ReadOnly);

    setHeader(QNetworkRequest::ContentTypeHeader, mimeType);
    setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(origLen));
    QTimer::singleShot(0, this, SIGNAL(metaDataChanged()));
    QTimer::singleShot(0, this, SIGNAL(readyRead()));
}

void HelpNetworkReply::abort()
{
    // nothing to do
}

qint64 HelpNetworkReply::readData(char *buffer, qint64 maxlen)
{
    qint64 len = qMin(qint64(data.length()), maxlen);
    if (len) {
        qMemCopy(buffer, data.constData(), len);
        data.remove(0, len);
    }
    if (!data.length())
        QTimer::singleShot(0, this, SIGNAL(finished()));
    return len;
}

class HelpNetworkAccessManager : public QNetworkAccessManager
{
public:
    HelpNetworkAccessManager(QHelpEngine *engine, QObject *parent);

protected:
    virtual QNetworkReply *createRequest(Operation op,
        const QNetworkRequest &request, QIODevice *outgoingData = 0);

private:
    QHelpEngine *helpEngine;
};

HelpNetworkAccessManager::HelpNetworkAccessManager(QHelpEngine *engine,
        QObject *parent)
    : QNetworkAccessManager(parent), helpEngine(engine)
{
}

QNetworkReply *HelpNetworkAccessManager::createRequest(Operation op,
    const QNetworkRequest &request, QIODevice *outgoingData)
{
    const QString& scheme = request.url().scheme();
    if (scheme == QLatin1String("qthelp") || scheme == QLatin1String("about")) {
        const QUrl& url = request.url();
        QString mimeType = url.toString();
        if (mimeType.endsWith(QLatin1String(".svg"))
            || mimeType.endsWith(QLatin1String(".svgz"))) {
           mimeType = QLatin1String("image/svg+xml");
        }
        else if (mimeType.endsWith(QLatin1String(".css"))) {
           mimeType = QLatin1String("text/css");
        }
        else if (mimeType.endsWith(QLatin1String(".js"))) {
           mimeType = QLatin1String("text/javascript");
        } else {
            mimeType = QLatin1String("text/html");
        }
        return new HelpNetworkReply(request, helpEngine->fileData(url), mimeType);
    }
    return QNetworkAccessManager::createRequest(op, request, outgoingData);
}

class HelpPage : public QWebPage
{
public:
    HelpPage(QWidget *central, QHelpEngine *engine, QObject *parent);

protected:
    virtual QWebPage *createWindow(QWebPage::WebWindowType);

    virtual bool acceptNavigationRequest(QWebFrame *frame,
        const QNetworkRequest &request, NavigationType type);

private:
    QWidget *centralWidget;
    QHelpEngine *helpEngine;
};

HelpPage::HelpPage(QWidget *central, QHelpEngine *engine, QObject *parent)
    : QWebPage(parent), centralWidget(central), helpEngine(engine)
{    
}

QWebPage *HelpPage::createWindow(QWebPage::WebWindowType)
{
    return new QWebPage();
}

static bool isLocalUrl(const QUrl &url)
{
    const QString scheme = url.scheme();
    if (scheme.isEmpty()
        || scheme == QLatin1String("file")
        || scheme == QLatin1String("qrc")
        || scheme == QLatin1String("data")
        || scheme == QLatin1String("qthelp")
        || scheme == QLatin1String("about"))
        return true;
    return false;
}

bool HelpPage::acceptNavigationRequest(QWebFrame *,
    const QNetworkRequest &request, QWebPage::NavigationType)
{
    const QUrl &url = request.url();
    if (isLocalUrl(url)) {
        if (url.path().endsWith(QLatin1String("pdf"))) {
            QString fileName = url.toString();
            fileName = QDir::tempPath() + QDir::separator() + fileName.right
                (fileName.length() - fileName.lastIndexOf(QChar('/')));

            QFile tmpFile(QDir::cleanPath(fileName));
            if (tmpFile.open(QIODevice::ReadWrite)) {
                tmpFile.write(helpEngine->fileData(url));
                tmpFile.close();
            }
            QDesktopServices::openUrl(QUrl(tmpFile.fileName()));
            return false;
        }
        return true;
    }

    QDesktopServices::openUrl(url);
    return false;
}

HelpViewer::HelpViewer(QHelpEngine *engine, QWidget *parent)
    : QWebView(parent), helpEngine(engine)
{    
    settings()->setAttribute(QWebSettings::PluginsEnabled, false);
    settings()->setAttribute(QWebSettings::JavaEnabled, false);
    setPage(new HelpPage(parent, helpEngine, this));

    page()->setNetworkAccessManager(new HelpNetworkAccessManager(engine, this));

    QAction* action = pageAction(QWebPage::OpenLinkInNewWindow);
    action->setText(tr("Open Link in New Tab"));
    if (!parent)
        action->setVisible(false);

    pageAction(QWebPage::DownloadLinkToDisk)->setVisible(false);
    pageAction(QWebPage::DownloadImageToDisk)->setVisible(false);
    pageAction(QWebPage::OpenImageInNewWindow)->setVisible(false);

    connect(pageAction(QWebPage::Copy), SIGNAL(changed()), this,
        SLOT(actionChanged()));
    connect(pageAction(QWebPage::Back), SIGNAL(changed()), this,
        SLOT(actionChanged()));
    connect(pageAction(QWebPage::Forward), SIGNAL(changed()), this,
        SLOT(actionChanged()));
    connect(page(), SIGNAL(linkHovered(QString, QString, QString)), this,
        SIGNAL(highlighted(QString)));
    connect(this, SIGNAL(urlChanged(QUrl)), this, SIGNAL(sourceChanged(QUrl)));
    setAcceptDrops(false);
}

void HelpViewer::setSource(const QUrl &url)
{
    if (!homeUrl.isValid())
        homeUrl = url;
    load(url);
}

void HelpViewer::resetZoom()
{
    setTextSizeMultiplier(1.0);
}

void HelpViewer::zoomIn(qreal range)
{
    setTextSizeMultiplier(textSizeMultiplier() + range / 10.0);
}

void HelpViewer::zoomOut(qreal range)
{
    setTextSizeMultiplier(qMax(0.0, textSizeMultiplier() - range / 10.0));
}

void HelpViewer::home()
{
    if (homeUrl.isValid())
        setSource(homeUrl);
}

void HelpViewer::wheelEvent(QWheelEvent *e)
{
    if (e->modifiers() & Qt::ControlModifier) {
        const int delta = e->delta();
        if (delta > 0)
            zoomIn(delta / 120);
        else if (delta < 0)
            zoomOut(-delta / 120);
        e->accept();
        return;
    }
    QWebView::wheelEvent(e);
}

void HelpViewer::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::XButton1) {
        triggerPageAction(QWebPage::Back);
        return;
    }

    if (e->button() == Qt::XButton2) {
        triggerPageAction(QWebPage::Forward);
        return;
    }

    QWebView::mouseReleaseEvent(e);
}

void HelpViewer::actionChanged()
{
    QAction *a = qobject_cast<QAction *>(sender());
    if (a == pageAction(QWebPage::Copy))
        emit copyAvailable(a->isEnabled());
    else if (a == pageAction(QWebPage::Back))
        emit backwardAvailable(a->isEnabled());
    else if (a == pageAction(QWebPage::Forward))
        emit forwardAvailable(a->isEnabled());
}

QT_END_NAMESPACE
