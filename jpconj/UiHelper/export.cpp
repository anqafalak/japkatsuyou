/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */
#include "export.h"


/*******************************************************
 *                    PUBLIC
 *******************************************************/


Export::Export()
{
    resetContent();
    isRTL = false;
}

void Export::addContent(QString content)
{
    htmlContent.replace("<!--CONTENT-->",
                        content + "\n<!--CONTENT-->");
}

void Export::setStyle(QString styleFile)
{
    this->styleFile = styleFile;
}

void Export::setRTL(bool RTL)
{
    isRTL = RTL;
    if (RTL)
        htmlContent.replace("<body><!--DIR-->", "<body dir=\"rtl\">");
    else
        htmlContent.replace("<body><!--DIR-->", "<body dir=\"ltr\">");
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


void Export::exportHtml(QString filename)
{
    QFile outputFile(filename);
    if(!outputFile.open(QIODevice::WriteOnly)){
        qDebug() << "- Error, unable to open the file for output";
        return;
    }

    QTextStream outStream(&outputFile);
    outStream.setCodec("UTF-8");

    if(styleFile.length()>0){
        QFileInfo styleInfo(styleFile);
        QString stylename = styleInfo.fileName();

        QFileInfo destInfo(filename);
        QString stylefolder = destInfo.fileName() + "_files";
        QString styleto = destInfo.absolutePath() + "/" + stylefolder + "/" + stylename;

        QDir(destInfo.absolutePath()).mkdir(stylefolder);
        qDebug() << styleFile << " to " << styleto;
        QFile::copy(styleFile, styleto);

        addStyle("./" + stylefolder + "/" + stylename);
    }

    outStream << htmlContent;

    outputFile.close();
}



void Export::print(QPrinter *printer)
{
    QWebView webview;
    webview.setHtml(htmlContent);

    if(styleFile.length()>0){
        QWebSettings * settings = webview.settings();
        settings->setUserStyleSheetUrl(QUrl("file://" + styleFile));
    }

    webview.print(printer);
}



void Export::resetContent()
{
    htmlContent = "";
    htmlContent += "<html>\n";
    htmlContent += "<head>\n";
    htmlContent += "<title>JapKatsuyou</title>\n";
    htmlContent += "<meta charset=\"UTF-8\">\n"; //<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n";
    htmlContent += "<!--STYLESHEETS-->\n";
    htmlContent += "<body><!--DIR-->\n";
    htmlContent += "<!--CONTENT-->\n";
    htmlContent += "</body>\n";
    htmlContent += "</html>\n";
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


void Export::addStyle(QString filename)
{
    htmlContent.replace("<!--STYLESHEETS-->",
                        "<link rel=\"stylesheet\" type=\"text/css\" href=\"" +
                        filename + "\">\n<!--STYLESHEETS-->");
}
