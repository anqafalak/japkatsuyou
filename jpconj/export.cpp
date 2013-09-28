#include "export.h"


/*******************************************************
 *                    PUBLIC
 *******************************************************/


Export::Export(QString content)
{
    htmlContent = content;
}

void Export::addContent(QString content)
{
    htmlContent += content;
}

void Export::setStyle(QString styleFile)
{
    this->styleFile = styleFile;
}

void Export::exportPdf(QString filename)
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);

    QWebView webview;
    webview.setHtml(htmlContent);

    if(styleFile.length()>0){
        QWebSettings * settings = webview.settings();
        settings->setUserStyleSheetUrl(QUrl("file://" + styleFile));
    }

    webview.print(&printer);
}

void Export::exportOdf(QString filename)
{
    QTextDocument * doc = new QTextDocument();
    doc->setHtml(htmlContent);

    //reading style file
    /*QFile cssFile(styleFile);
    QString styleSheet = "";
    if (cssFile.open(QFile::ReadOnly | QFile::Text)){
        QTextStream cssStream(&cssFile);
        styleSheet = cssStream.readAll();
        cssFile.close();
    }
    //end reading
    doc->setDefaultStyleSheet(styleSheet);*/
    QTextDocumentWriter writer(filename);
    writer.setFormat("odf");
    writer.write(doc);
}

void Export::resetContent()
{
    htmlContent = "";
}



void Export::setConfigExportParts(QMap<QString, bool> exportParts)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("Export");
    foreach (QString part, exportParts.keys())
        settings.setValue(part, exportParts.value(part));
    settings.endGroup();

}

bool Export::getConfigExportPart(QString exportPart)
{
    bool result;
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("Export");
    result = settings.value(exportPart, true).toBool();
    settings.endGroup();
    //qDebug() << exportPart << " = " << result;
    return result;
}

