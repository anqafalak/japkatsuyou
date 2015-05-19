#include "funcframe.h"

FuncFrame::FuncFrame(QWidget *parent) :
    QFrame(parent)
{
    hasContent = false;
}

void FuncFrame::initialize()
{
    initUI();
    initExporter();
}


/*!
 * \brief jpconjmain::setCSS Set a user defined CSS to the QWebView
 * \param webView The QWebView we want to set the content CSS.
 * \param nameCSS The name of the CSS located in <dataFolder>/styles/ with the extension ".css"
 */
void FuncFrame::setCSS(QWebView * webView, QString nameCSS)
{
    QString cssfile = "file:" + QDir(QString(dataFolder)).absolutePath() + "/styles/" + nameCSS;
    //qDebug()<< "css: " << cssfile;
    QWebSettings * settings = webView->settings();
    settings->setUserStyleSheetUrl(QUrl(cssfile));
}
