/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

    QString confLangId = Language::getConfigLanguage();

    int index = ui->lang->findData(QVariant(confLangId));

    ui->lang->setCurrentIndex(index);
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
}



/*******************************************************
 *                   PRIVATE SLOTS
 *******************************************************/

void Preference::on_prefOK_accepted()
{
    doSave();
}
