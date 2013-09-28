#ifndef EXPORT_H
#define EXPORT_H

#include <QDebug>
#include <QFile>
#include <QPrinter>
#include <QSettings>
#include <QTextStream>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QWebView>

class Export
{
public:
    Export(QString content = "");

    QString htmlContent;
    QString styleFile;

    void addContent(QString content);
    void setStyle(QString styleFile);
    void exportPdf(QString filename);
    void exportOdf(QString filename);
    void resetContent();

    static void setConfigExportParts(QMap<QString, bool> exportParts);
    static bool getConfigExportPart(QString exportPart);
};
#endif // EXPORT_H
