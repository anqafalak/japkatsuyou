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
    void addStyle(QString styleContent);
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

};
#endif // EXPORT_H
