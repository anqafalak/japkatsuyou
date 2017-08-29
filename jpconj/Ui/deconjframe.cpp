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
#include "deconjframe.h"
#include "ui_deconjframe.h"

DeconjFrame::DeconjFrame(QWidget *parent) :
    FuncFrame(parent),
    ui(new Ui::DeconjFrame)
{
    initialize();
}

DeconjFrame::~DeconjFrame()
{
    delete ui;
}


void DeconjFrame::initUI()
{

    ui->setupUi(this);
    QPalette palette;

    //hasContent = false;
    palette.setBrush(QPalette::Base, Qt::transparent);

    ui->verbInfo->page()->setPalette(palette);
    ui->verbInfo->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->verbList->page()->setPalette(palette);
    ui->verbList->setAttribute(Qt::WA_OpaquePaintEvent, false);


    changeStyle(Style::getCurrentStyle());

}


void DeconjFrame::initExporter(Export *exporter)
{

    exporter->setRTL(rtl);
    exporter->addContent("<p><h1>" + jaVerb.kanji + "</h1></p><hr>\n");


}

void DeconjFrame::changeFont(QString font, QString jpfont, int size, int jpsize)
{

    QString style = ".lan {font-family:" + font;
    style += "; font-size :" + QString::number(size) + "pt;}\n";

    style += ".jp {font-family:" + jpfont;
    style += "; font-size :" + QString::number(jpsize) + "pt;}";

    QWebElement infoEl = ui->verbInfo->page()->mainFrame()->findFirstElement("style");
    infoEl.setInnerXml(style);

    QWebElement basicEl = ui->verbList->page()->mainFrame()->findFirstElement("style");
    basicEl.setInnerXml(style);

    //qDebug()<< "font changed" << ui->basicConj->page()->mainFrame()->toHtml();

}



/*!
 * \brief ConjFrame::deConj This function is used to find different verbs from a conjugation form
 *
 */

void DeconjFrame::deConj()
{

    QString verb = ui->inputConjVerb->text();

    if (verb == jaVerb.kanji)
        return;

    Edict2 edict2;

    QList<VerbInfo> verbinfos;



    if (verbinfos.size() < 1){
        //TODO show a message that the verb is not found
        //ui->verbType->setText(Msg::getVerbTypeDesc(type));
        close();
        hasContent = false;
        ui->verbInfo->setHtml("");
        ui->verbList->setHtml("");

        return;
    }

    //ui->verbType->setText(Msg::getVerbTypeDesc(type));

    hasContent = true;

    refreshLanguage(rtl);

    open();

}


/*!
 * \brief jpconjmain::readHtmlFile Reads an HTML file and return a QString
 * \param URL URL of the HTML file, we want to read.
 * \return A QString which is the content of this HTML file.
 */
QString DeconjFrame::readHtmlFile(QString URL)
{

    QString result = "<!doctype html>\n";
    result += "<html>\n";
    result += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" />\n";
    result += "<style>\n";
    result += ".lan {font-family:" + Style::getCurrentFont(false) + ";";
    result += "font-size:" + QString::number(Style::getCurrentFontSize(false)) + "pt;}\n";
    result += ".jp {font-family:" + Style::getCurrentFont(true);
    result += "; font-size :" + QString::number(Style::getCurrentFontSize(true)) + "pt;}\n";
    result += "\n</style>\n";
    result += "<body>\n";

    QFile HtmlFile(URL);

    if (HtmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream htmlStream(&HtmlFile);
        result += htmlStream.readAll();
    }

    result += "</body>\n</html>";

    return result;
}

QString DeconjFrame::readCSSFile(QString URL)
{
    QString result="";
    QFile HtmlFile(URL);

    if (HtmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream htmlStream(&HtmlFile);
        result = htmlStream.readAll();
    }

    return result;
}


void DeconjFrame::refreshLanguage(bool rtl)
{

    this->rtl = rtl;
    ui->retranslateUi(this);

    if (!hasContent)
        return;

    QString jsScript = "var body = document.getElementsByTagName('body')[0]; \n";
    QString dir = (rtl)?"rtl":"ltr";
    jsScript += "body.dir = \"" + dir + "\";";

    ui->verbList->page()->mainFrame()->evaluateJavaScript(jsScript);
    ui->verbInfo->page()->mainFrame()->evaluateJavaScript(jsScript);

}



void DeconjFrame::zoom(signed char sign)
{
    if (sign < 0){
        ui->verbInfo->setTextSizeMultiplier(qMax(0.5, ui->verbInfo->textSizeMultiplier() - 1.0 / 10.0));
        ui->verbList->setTextSizeMultiplier(qMax(0.5, ui->verbList->textSizeMultiplier() - 1.0 / 10.0));

        return;
    }

    if (sign > 0){
        ui->verbInfo->setTextSizeMultiplier(qMin(2.5,ui->verbInfo->textSizeMultiplier() + 1.0 / 10.0));
        ui->verbList->setTextSizeMultiplier(qMin(2.5, ui->verbList->textSizeMultiplier() + 1.0 / 10.0));

        return;
    }

    ui->verbInfo->setTextSizeMultiplier(1.0);
    ui->verbList->setTextSizeMultiplier(1.0);

}


void DeconjFrame::changeStyle(QString styleID)
{
    stylesheet = styleID + ".css";
    //qDebug() << "style changed" << styleID;
    setCSS(ui->verbInfo, stylesheet);
    setCSS(ui->verbList, stylesheet);

}

