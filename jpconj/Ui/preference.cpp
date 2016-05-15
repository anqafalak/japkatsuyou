/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013-2016  AnqaFalak group
    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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

#include "preference.h"
#include "ui_preference.h"

/*!
 * \class Preference
 * This class is used to manage "Preference" dialog box.
 * It initialize the dialog components,
 * and save the user's settings to config file
 */



/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief Preference::Preference The constructor of the Dialog box "Preference"
 * \param parent
 */
Preference::Preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    doInit();

}



/*!
 * \brief Preference::~Preference The destructor of the Dialog box "Preference"
 */
Preference::~Preference()
{
    delete ui;
}



/*!
 * \brief Preference::doInit Initialize the components of the "Preference" Box
 *
 * It Initializes the components.
 * For example, it look for available languages using Language::getLanguagesInfo
 * then it initialize a list of languages that user can select from.
 */
void Preference::doInit()
{

    QHash<QString, QString> languageInfo = Language::getLanguagesInfo();

    foreach (QString langId, languageInfo.keys())
        ui->lang->addItem(languageInfo.value(langId), QVariant(langId));

    QString currentLangId = Language::getCurrentLanguage();

    int index = ui->lang->findData(QVariant(currentLangId));

    ui->lang->setCurrentIndex(index);

    ui->info_check->setText(qApp->translate("ConjFrame", "Information"));
    ui->info_check->setChecked(Export::getConfigExportPart("info"));
    ui->standard_check->setText(qApp->translate("ConjFrame", "Standard Conjugation"));
    ui->standard_check->setChecked(Export::getConfigExportPart("standard"));
    ui->basic_check->setText(qApp->translate("ConjFrame", "Basic Conjugation"));
    ui->basic_check->setChecked(Export::getConfigExportPart("basic"));
    ui->complex_check->setText(qApp->translate("ConjFrame", "Complex Conjugation"));
    ui->complex_check->setChecked(Export::getConfigExportPart("complex"));
    ui->exp_check->setText(qApp->translate("jpconjmain", "Examples"));
    ui->exp_check->setChecked(Export::getConfigExportPart("examples"));

    ui->styleUse_check->setChecked(Export::getConfigExportPart("styled"));


    //------------------------
    QHash<QString, Styleinfo*> styleInfo = Style::getStyleInfo();

    foreach(QString styleID, styleInfo.keys()){
        QIcon icon = QIcon(QString(dataFolder) + "styles/" + styleID + ".jpg");
        QString name = styleInfo.value(styleID)->name;
        ui->style->addItem(icon, name, QVariant(styleID));
        //qDebug() << styleID;
    }

    QString currentStyleId = Style::getCurrentStyle();
    index = ui->style->findData(QVariant(currentStyleId));
    ui->style->setCurrentIndex(index);

    QString currentFont = Style::getCurrentFont(false);
    index = ui->font->findText(currentFont);
    ui->font->setCurrentIndex(index);

    currentFont = Style::getCurrentFont(true);
    index = ui->jpfont->findText(currentFont);
    ui->jpfont->setCurrentIndex(index);

    ui->size->setValue(Style::getCurrentFontSize(false));
    ui->jpsize->setValue(Style::getCurrentFontSize(true));

    //=================
    QMap<QString, QIcon> icons = Icona::getAvailableIcons();

    foreach(QString icon, icons.keys()){
        ui->icons->addItem(icons.value(icon), icon);
        //qDebug() << styleID;
    }

    QString currentIconId = Icona::getCurrentIcons();
    index = ui->icons->findText(currentIconId);
    ui->icons->setCurrentIndex(index);
}



/*!
 * \brief Preference::doSave Save user settings
 *
 * When the user push the "OK" button, this function is called to save his settings.
 */
void Preference::doSave()
{

    int index = ui->lang->currentIndex();
    QString langID = ui->lang->itemData(index).toString();

    Language::setConfigLanguage(langID);
    Language::setLanguage();

    //Export preferences
    QMap<QString, bool> exportParts;
    exportParts.insert("info", ui->info_check->isChecked());
    exportParts.insert("standard", ui->standard_check->isChecked());
    exportParts.insert("basic", ui->basic_check->isChecked());
    exportParts.insert("complex", ui->complex_check->isChecked());
    exportParts.insert("examples", ui->exp_check->isChecked());
    exportParts.insert("styled", ui->styleUse_check->isChecked());

    Export::setConfigExportParts(exportParts);

    //style
    index = ui->style->currentIndex();
    QString styleID = ui->style->itemData(index).toString();
    Style::setConfigStyle(styleID);
    Style::setStyle();

    //Font
    QString font = ui->font->currentFont().family();
    Style::setConfigFont(font, false);
    font = ui->jpfont->currentFont().family();
    Style::setConfigFont(font, true);
    int size = ui->size->value();
    Style::setConfigFontSize(size, false);
    size = ui->jpsize->value();
    Style::setConfigFontSize(size, true);
    Style::setFont();

    //Icons
    QString iconsID = ui->icons->currentText();
    Icona::setConfigIcons(iconsID);
    Icona::setIcons();
}



/*******************************************************
 *                   PRIVATE SLOTS
 *******************************************************/

void Preference::on_prefOK_accepted()
{
    doSave();
}
