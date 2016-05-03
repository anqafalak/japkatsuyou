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
#include "conjframe.h"
#include "ui_conjframe.h"

ConjFrame::ConjFrame(QWidget *parent) :
    FuncFrame(parent),
    ui(new Ui::ConjFrame)
{
    initialize();
}

ConjFrame::~ConjFrame()
{
    delete ui;
}


void ConjFrame::initUI()
{
    ui->setupUi(this);
    QPalette palette;

    //hasContent = false;
    palette.setBrush(QPalette::Base, Qt::transparent);

    ui->verbInfo->page()->setPalette(palette);
    ui->verbInfo->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->basicConj->page()->setPalette(palette);
    ui->basicConj->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->standardConj->page()->setPalette(palette);
    ui->standardConj->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->complexConj->page()->setPalette(palette);
    ui->complexConj->setAttribute(Qt::WA_OpaquePaintEvent, false);

    changeStyle(Style::getCurrentStyle());
}


void ConjFrame::initExporter(Export *exporter)
{
    exporter->setRTL(rtl);
    exporter->addContent("<p><h1>" + jaVerb.kanji + "</h1></p><hr>\n");
    //TODO add verb info here
    //exporter->addContent("<p><h3>" + ui->verbType->text() + "</h3></p>\n");
    if(Export::getConfigExportPart("info")){
        exporter->addContent("<p><h2>" + ui->ConjgTab->tabText(0) + "</h2></p>\n");
        QString data = ui->verbInfo->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter->addContent(data);
    }
    if(Export::getConfigExportPart("standard")){
        exporter->addContent("<p><h2>" + ui->ConjgTab->tabText(1) + "</h2></p>\n");
        QString data = ui->standardConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter->addContent(data);
    }
    if(Export::getConfigExportPart("basic")){
        exporter->addContent("<p><h2>" + ui->ConjgTab->tabText(2) + "</h2></p>\n");
        QString data = ui->basicConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter->addContent(data);
    }
    if(Export::getConfigExportPart("complex")){
        exporter->addContent("<p><h2>" + ui->ConjgTab->tabText(3) + "</h2></p>\n");
        QString data = ui->complexConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter->addContent(data);
    }

    if(Export::getConfigExportPart("styled")){
        QString styleCSS = readHtmlFile(QDir(QString(dataFolder) + "styles/" + stylesheet).absolutePath());
        exporter->addStyle(styleCSS);
    }
}



/*!
 * \brief ConjFrame::doConj This function is used to show different conjugation forms
 *
 * This function search for the existance of the verb, using Edict2 module.
 * Then, it calls for:
 * - ConjFrame::basicConjugation To show the standard and basic conjugation forms.
 * - ConjFrame::complexConjugation To show the complex conjugation forms.
 */

void ConjFrame::doConj()
{

    QString verb = ui->inputConjVerb->text();

    if (verb == jaVerb.kanji)
        return;

    Edict2 edict2;

    Edict2::JaVerb javerb = edict2.find(verb);



    if (javerb.type < 1){
        //TODO show a message that the verb is not found
        //ui->verbType->setText(Msg::getVerbTypeDesc(type));
        close();
        javerb.kanji = "";
        javerb.hiragana = "";
        javerb.type = (EdictType) 0;
        hasContent = false;
        ui->verbInfo->setHtml("");
        ui->standardConj->setHtml("");
        ui->basicConj->setHtml("");
        ui->complexConj->setHtml("");

        return;
    }

    //ui->verbType->setText(Msg::getVerbTypeDesc(type));
    complexConjugation(javerb);
    basicConjugation(javerb);
    verbInformation(javerb);
    hasContent = true;
    jaVerb = javerb;
    refreshLanguage(rtl);

    open();
}




/*!
 * \brief jpconjmain::basicConjugation Used to show the standard and basic conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
void ConjFrame::basicConjugation(Edict2::JaVerb javerb)
{

    if (!hasContent){
        QString basicConjHTML = readHtmlFile(":/output/basicConj");
        QString standardConjHTML = readHtmlFile(":/output/standardConj");

        ui->standardConj->setHtml(standardConjHTML);
        ui->basicConj->setHtml(basicConjHTML);
    }

    QString verb = javerb.kanji;
    EdictType type = javerb.type;

    //! [Doxygen: basicFormsMap example]
    QMap<KForm, QString> basicForms = Msg::basicFormsMap();
    QWebElement element_stem;
    QWebElement element_suffix;
    QWebElement element_basic;
    foreach (KForm form, basicForms.keys()){
        QStringList conj = JpConj::Katsuyou(verb, type, form).split("|");
        QString elementId = basicForms.value(form);

        element_stem = ui->standardConj->page()->mainFrame()->findFirstElement("#stem_" + elementId);
        element_suffix = ui->standardConj->page()->mainFrame()->findFirstElement("#suffix_" + elementId);
        element_stem.setInnerXml(conj[0]);
        element_suffix.setInnerXml(conj[1]);

        element_basic = ui->basicConj->page()->mainFrame()->findFirstElement("#basic_" + elementId);
        element_basic.setInnerXml(conj[0] + conj[1]);

    }
    //! [Doxygen: basicFormsMap example]

}



/*!
 * \brief jpconjmain::complexConjugation Used to show the complex conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
void ConjFrame::complexConjugation(Edict2::JaVerb javerb)
{
    if (!hasContent){
        QString complexConjHTML = readHtmlFile(":/output/complexConj");
        ui->complexConj->setHtml(complexConjHTML);
    }

    QString verb = javerb.kanji;
    EdictType type = javerb.type;

    QString jsScript="";
    QMap<CForm, QString> complexForms = Msg::complexFormsMap();
    foreach (CForm form, complexForms.keys()){

        QString elementId = complexForms.value(form);

        jsScript += "document.getElementById(\"PoA_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Polite, _Affirmative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PoN_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Polite, _Negative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PlA_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Plain, _Affirmative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PlN_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Plain, _Negative).remove("|") + "\";\n";
        //complexConjHTML.replace("&_Form_" + str, Msg::getVerbFormName(form));
        //complexConjHTML.replace("&_Tip_" + str, Msg::getVerbFormDesc(form));
    }

    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);

}

void ConjFrame::verbInformation(Edict2::JaVerb javerb)
{
    if (!hasContent){
        QString verbInfoHTML = readHtmlFile(":/output/verbInfo");
        ui->verbInfo->setHtml(verbInfoHTML);
    }

    QString verb = javerb.kanji;
    EdictType type = javerb.type;

    QString jsScript="";

    jsScript += "document.getElementById(\"_Verb\").innerHTML = \"";
    jsScript += Msg::getTranslatedString("_Verb") + "\";\n";

    jsScript += "document.getElementById(\"furigana\").innerHTML = \"";
    jsScript += "<ruby>" + verb + "<rt>" + javerb.hiragana + "</rt></ruby>\";\n";

    jsScript += "document.getElementById(\"_Romaji\").innerHTML = \"";
    jsScript += Msg::getTranslatedString("_Romaji") + "\";\n";

    jsScript += "document.getElementById(\"romaji\").innerHTML = \"";
    jsScript += JTrans::hiragana2romaji(javerb.hiragana) + "\";\n";

    jsScript += "document.getElementById(\"_Type\").innerHTML = \"";
    jsScript += Msg::getTranslatedString("_Type") + "\";\n";

    jsScript += "document.getElementById(\"type\").innerHTML = \"";
    jsScript += Msg::getVerbTypeDesc(type) + "\";\n";

    ui->verbInfo->page()->mainFrame()->evaluateJavaScript(jsScript);
}

/*!
 * \brief jpconjmain::readHtmlFile Reads an HTML file and return a QString
 * \param URL URL of the HTML file, we want to read.
 * \return A QString which is the content of this HTML file.
 */
QString ConjFrame::readHtmlFile(QString URL)
{
    QString result="<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" /><body>";
    QFile HtmlFile(URL);

    if (HtmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream htmlStream(&HtmlFile);
        result = htmlStream.readAll();
    }

    result += "</body>";

    return result;
}



void ConjFrame::refreshLanguage(bool rtl)
{

    this->rtl = rtl;

    ui->retranslateUi(this);

    if (!hasContent)
        return;

    //TODO Refresh verbInfo instead
    //ui->verbType->setText(Msg::getVerbTypeDesc(verbType));

    QString jsScript = "var body = document.getElementsByTagName('body')[0]; \n";
    QString dir = (rtl)?"rtl":"ltr";
    jsScript += "body.dir = \"" + dir + "\";";

    ui->standardConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    //it is better for standard conjugation to stay ltr
    ui->basicConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    ui->verbInfo->page()->mainFrame()->evaluateJavaScript(jsScript);
    //qDebug()<< jsScript;

    //Retranslate strings

    {//Information
        jsScript += "document.getElementById(\"_Verb\").innerHTML = \"";
        jsScript += Msg::getTranslatedString("_Verb") + "\";\n";
        jsScript += "document.getElementById(\"_Romaji\").innerHTML = \"";
        jsScript += Msg::getTranslatedString("_Romaji") + "\";\n";
        jsScript += "document.getElementById(\"_Type\").innerHTML = \"";
        jsScript += Msg::getTranslatedString("_Type") + "\";\n";
        ui->verbInfo->page()->mainFrame()->evaluateJavaScript(jsScript);
        jsScript += "document.getElementById(\"type\").innerHTML = \"";
        jsScript += Msg::getVerbTypeDesc(jaVerb.type) + "\";\n";
        ui->verbInfo->page()->mainFrame()->evaluateJavaScript(jsScript);
    }

    {//standard
        QWebElementCollection standardConjConst = ui->standardConj->page()->mainFrame()->findAllElements(".Const");

        for(int i = 0; i < standardConjConst.count(); i++){
            QWebElement element = standardConjConst.at(i);
            QString elementName = element.attribute("name", "");
            element.setInnerXml(Msg::getTranslatedString(elementName));
        }
    }

    {//basic
        QWebElementCollection basicConjConst = ui->basicConj->page()->mainFrame()->findAllElements(".Const");

        for(int i = 0; i < basicConjConst.count(); i++){
            QWebElement element = basicConjConst.at(i);
            QString elementName = element.attribute("name", "");
            element.setInnerXml(Msg::getTranslatedString(elementName));
        }

        QMap<KForm, QString> basicForms = Msg::basicFormsMap();
        QWebElement element_basic;
        foreach (KForm form, basicForms.keys()){
            QString elementId = basicForms.value(form);
            element_basic = ui->basicConj->page()->mainFrame()->findFirstElement("#_Name_" + elementId);
            element_basic.setInnerXml(Msg::getBasicFormName(form));
        }
    }

    //complexConj

    QWebElementCollection complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Form\"]");
    for(int i = 0; i < complexConjConst.count(); i++)
        complexConjConst.at(i).setInnerXml(Msg::getTranslatedString("_Form"));

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Polite\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolitenessName(_Polite));
        element.setAttribute("title", Msg::getVerbPolitenessDesc(_Polite));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Plain\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolitenessName(_Plain));
        element.setAttribute("title", Msg::getVerbPolitenessDesc(_Plain));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Affirmative\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolarityName(_Affirmative));
        element.setAttribute("title", Msg::getVerbPolarityDesc(_Affirmative));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Negative\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolarityName(_Negative));
        element.setAttribute("title", Msg::getVerbPolarityDesc(_Negative));
    }

    QMap<CForm, QString> complexForms = Msg::complexFormsMap();
    QWebElement element_complex;
    foreach (CForm form, complexForms.keys()){
        QString elementId = complexForms.value(form);

        element_complex = ui->complexConj->page()->mainFrame()->findFirstElement("#_Form_" + elementId);
        element_complex.setInnerXml(Msg::getVerbFormName(form));
        element_complex.setAttribute("title", Msg::getVerbFormDesc(form));
    }
    //qDebug()<< jsScript;
    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);

    //qDebug()<< "Strings translation";

}



void ConjFrame::zoom(signed char sign)
{
    if (sign < 0){
        ui->standardConj->setTextSizeMultiplier(qMax(0.5, ui->standardConj->textSizeMultiplier() - 1.0 / 10.0));
        ui->basicConj->setTextSizeMultiplier(qMax(0.5, ui->basicConj->textSizeMultiplier() - 1.0 / 10.0));
        ui->complexConj->setTextSizeMultiplier(qMax(0.5, ui->complexConj->textSizeMultiplier() - 1.0 / 10.0));

        return;
    }

    if (sign > 0){
        ui->standardConj->setTextSizeMultiplier(qMin(2.5,ui->standardConj->textSizeMultiplier() + 1.0 / 10.0));
        ui->basicConj->setTextSizeMultiplier(qMin(2.5, ui->basicConj->textSizeMultiplier() + 1.0 / 10.0));
        ui->complexConj->setTextSizeMultiplier(qMin(2.5, ui->complexConj->textSizeMultiplier() + 1.0 / 10.0));

        return;
    }

    ui->standardConj->setTextSizeMultiplier(1.0);
    ui->basicConj->setTextSizeMultiplier(1.0);
    ui->complexConj->setTextSizeMultiplier(1.0);
}


void ConjFrame::changeStyle(QString styleID)
{
    stylesheet = styleID + ".css";
    //qDebug() << "style changed" << styleID;
    setCSS(ui->basicConj, stylesheet);
    setCSS(ui->standardConj, stylesheet);
    setCSS(ui->complexConj, stylesheet);
    setCSS(ui->verbInfo, stylesheet);
}


void ConjFrame::on_conjugateButton_clicked()
{
    doConj();
}


void ConjFrame::on_inputConjVerb_returnPressed()
{
    doConj();
}
