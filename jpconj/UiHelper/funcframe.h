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
#ifndef FUNCFRAME_H
#define FUNCFRAME_H

#include <QFrame>
#include <QWebView>
#include <QDir>

#include "UiHelper/export.h"

class FuncFrame: public QFrame
{

public:
    explicit FuncFrame(QWidget *parent = 0);
    //~FuncFrame();

    virtual void changeStyle(QString styleID) = 0;
    virtual void zoom(signed char sign) = 0;
    virtual void refreshLanguage(bool rtl) = 0;
    virtual void initExporter(Export * exporter) = 0;

protected:

    bool rtl;
    bool hasContent;
    QString stylesheet;

    void initialize();

    void setCSS(QWebView * webView, QString nameCSS);

    virtual void initUI() = 0;

signals:
    void close();
    void open();
    void newVerb(QString verb);

};

#endif // FUNCFRAME_H
