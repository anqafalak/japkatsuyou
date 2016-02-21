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
#include "funcframe.h"

FuncFrame::FuncFrame(QWidget *parent) :
    QFrame(parent)
{
    hasContent = false;
}

void FuncFrame::initialize()
{
    initUI();
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
