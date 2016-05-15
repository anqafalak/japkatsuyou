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
#include "about.h"
#include "ui_about.h"

/*!
 * \class About
 * This class is used to manage "About" dialog box.
 * It initialize the dialog components,
 * and charge information in the current language
 */



/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief About::About The constructor of the Dialog box "About"
 * \param parent
 */
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    Init();
}



/*!
 * \brief About::~About The destructor of the Dialog box "About"
 */
About::~About()
{
    delete ui;
}



/*******************************************************
 *                    PRIVATE
 *******************************************************/

/*!
 * \brief About::Init Initialize the components of the "About" Box
 *
 * This function sets the components' features to a ddefault state, for example modifying colors, etc.
 */
void About::Init()
{
    ui->verl->setText(tr("Version") + " " + VERSION);

    ui->aboutText->viewport()->setAutoFillBackground(false);
    ui->aboutText->setSource(loadLocalizePath("about"));
    connect(ui->aboutText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));

    ui->licenceText->viewport()->setAutoFillBackground(false);
    ui->licenceText->setSource(loadLocalizePath("license"));
    connect(ui->licenceText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));

    ui->authorsText->viewport()->setAutoFillBackground(false);
    ui->authorsText->setSource(loadLocalizePath("authors"));
    connect(ui->authorsText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));

    ui->thanksText->viewport()->setAutoFillBackground(false);
    ui->thanksText->setSource(loadLocalizePath("thanks"));
    connect(ui->thanksText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));
}



/*!
 * \brief About::loadLocalizePath Gives the url of an embeded "about" file
 *
 * This function used to verify if a file exists with the current language.
 * If not, it gives the English version of this file.
 * The files are HTML files used to describe the about section, they are:
 * - "about": which gives a description of the software.
 * - "license": Contains the license information  of the software.
 * - "authors": Contains the names and Emails of the contributors.
 * - "Thanks": Contains the names of the persons that helped our project to move forward.
 *
 * These files are appened using a ".qrc" file
 * \param fileName The name of the file you want to get the URL
 * \return The URL of the embeded file, if not available, it returns the English version of it
 */
QUrl About::loadLocalizePath(QString fileName)
{
    QString currentLanguage = Language::getCurrentLanguage();
    QString LocalizedFilePath = ":/about/" + fileName + "_" + currentLanguage;

    QResource fileRessource(LocalizedFilePath);
    if(!fileRessource.isValid())
        LocalizedFilePath = ":/about/" + fileName + "_en";

    return QUrl("qrc" + LocalizedFilePath);
}



/*******************************************************
 *                   PRIVATE SLOTS
 *******************************************************/

/*!
 * \brief About::externUrl This function is used to open URL in a browser
 *
 * Giving a URL, this function call the system to get the default browser or mail box application
 * (in case of mailto: )
 * \param url The URL you want to browse
 */
void About::externUrl(const QUrl &url)
{
    QDesktopServices::openUrl(url);
}



