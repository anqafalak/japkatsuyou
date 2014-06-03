#ifndef EXPORT_H
#define EXPORT_H

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QPrinter>
#include <QSettings>
#include <QTextStream>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QWebView>

class Export
{
public:
    Export();
    void addContent(QString content);
    void setStyle(QString styleFile);
    void setRTL(bool RTL);
    void exportPdf(QString filename);
    void exportOdf(QString filename);
    void exportHtml(QString filename);
    void print(QPrinter *printer);
    void resetContent();

    static void setConfigExportParts(QMap<QString, bool> exportParts);
    static bool getConfigExportPart(QString exportPart);

private:
    QString htmlContent;
    QString styleFile;
    bool isRTL;
    void addStyle(QString filename);
};
#endif // EXPORT_H
