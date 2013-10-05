/**************************************************************************
**
** This file is part of Qt Creator
**
** Adapted: 2013 Aries Abdelkrime (kariminfo0@gmail.com)
** To be used in JapKatsuyou project
**      - Remaining just code that use webkit
**      - Delete some libraries call
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

#ifndef HELPVIEWER_H
#define HELPVIEWER_H

#include <QAction>
#include <QByteArray>
#include <QDesktopServices>
#include <QDir>
#include <QEvent>
#include <QHelpEngine>
#include <QKeyEvent>
//#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QUrl>
#include <QVariant>
#include <QWebView>


QT_BEGIN_NAMESPACE

//class QHelpEngine;
//class CentralWidget;

//class QPoint;
//class QString;
//class QKeyEvent;
//class QMouseEvent;
//class QContextMenuEvent;


class HelpViewer : public QWebView
{
    Q_OBJECT

public:
    HelpViewer(QHelpEngine *helpEngine, QWidget *parent);
    void setSource(const QUrl &url);

    inline QUrl source() const
    { return url(); }

    inline QString documentTitle() const
    { return title(); }

    inline bool hasSelection() const
    { return !selectedText().isEmpty(); } // ### this is suboptimal

    void resetZoom();
    void zoomIn(qreal range = 1);
    void zoomOut(qreal range = 1);

    inline void copy()
    { return triggerPageAction(QWebPage::Copy); }

    inline bool isForwardAvailable() const
    { return pageAction(QWebPage::Forward)->isEnabled(); }
    inline bool isBackwardAvailable() const
    { return pageAction(QWebPage::Back)->isEnabled(); }

public Q_SLOTS:
    void home();
    void backward() { back(); }

Q_SIGNALS:
    void copyAvailable(bool enabled);
    void forwardAvailable(bool enabled);
    void backwardAvailable(bool enabled);
    void highlighted(const QString &);
    void sourceChanged(const QUrl &);

protected:
    virtual void wheelEvent(QWheelEvent *);
    void mouseReleaseEvent(QMouseEvent *e);

private Q_SLOTS:
    void actionChanged();

private:
    QHelpEngine *helpEngine;
//    CentralWidget* parentWidget;
    QUrl homeUrl;
};

QT_END_NAMESPACE

#endif
