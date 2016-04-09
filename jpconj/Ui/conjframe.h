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
#ifndef CONJFRAME_H
#define CONJFRAME_H

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
class ConjFrame;
}

class ConjFrame : public FuncFrame
{
    Q_OBJECT
    
public:
    explicit ConjFrame(QWidget *parent = 0);
    ~ConjFrame();

    void doConj();
    virtual void zoom(signed char sign);
    virtual void refreshLanguage(bool rtl);
    virtual void changeStyle(QString styleID);
    virtual void initExporter(Export  * exporter);


protected:
    virtual void initUI();
    
private slots:
    void on_conjugateButton_clicked();
    void on_inputConjVerb_returnPressed();

private:
    Ui::ConjFrame *ui;


    //bool languageChanged;
    Edict2::JaVerb jaVerb;
    //QString currentVerb;

    void basicConjugation(Edict2::JaVerb javerb);
    void complexConjugation(Edict2::JaVerb javerb);
    void verbInformation(Edict2::JaVerb javerb);

    QString readHtmlFile(QString URL);

signals:
    void close();
    void open();
};

#endif // CONJFRAME_H
