/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2017  AnqaFalak group

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
#ifndef DECONJFRAME_H
#define DECONJFRAME_H

#include "UiHelper/export.h"
#include "Func/edict2.h"
#include "UiHelper/msg.h"
#include "UiHelper/funcframe.h"
#include "Ui/preference.h"
#include "Func/jtrans.h"
#include "jpconj.h"
#include <QWebElement>
#include <QWebFrame>


namespace Ui {
class DeconjFrame;
}

class DeconjFrame : public FuncFrame
{
    Q_OBJECT
    
public:
    explicit DeconjFrame(QWidget *parent = 0);
    ~DeconjFrame();

    void deConj();
    virtual void zoom(signed char sign);
    virtual void refreshLanguage(bool rtl);
    virtual void changeStyle(QString styleID);
    virtual void initExporter(Export  * exporter);
    virtual void changeFont(QString font, QString jpfont, int size, int jpsize);


protected:
    virtual void initUI();
    

private:

    Ui::DeconjFrame *ui;

    //bool languageChanged;
    Edict2::JaVerb jaVerb;
    //QString currentVerb;

    QString readHtmlFile(QString URL);
    QString readCSSFile(QString URL);

signals:
    void close();
    void open();
    void newVerb(QString verb);
};

#endif // DECONJFRAME_H
