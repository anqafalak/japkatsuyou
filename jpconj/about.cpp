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

#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    Init();
}

About::~About()
{
    delete ui;
}

void About::Init()
{
    ui->verl->setText(tr("Version") + " " + VERSION);

    ui->licenceText->viewport()->setAutoFillBackground(false);
    ui->licenceText->setSource(loadLocalizePath("licence"));
    connect(ui->licenceText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));

    ui->authorsText->viewport()->setAutoFillBackground(false);
    ui->authorsText->setSource(loadLocalizePath("authors"));
    connect(ui->authorsText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));

    ui->thanksText->viewport()->setAutoFillBackground(false);
    ui->thanksText->setSource(loadLocalizePath("thanks"));
    connect(ui->thanksText, SIGNAL(anchorClicked(QUrl)), this, SLOT(externUrl(QUrl)));
}


void About::externUrl(const QUrl &url)
{
    QDesktopServices::openUrl(url);
}

QUrl About::loadLocalizePath(QString fileName)
{
    QString currentLanguage = Language::getConfigLanguage();
    QString LocalizedFilePath = ":/about/" + fileName + "_" + currentLanguage;

    QResource fileRessource(LocalizedFilePath);
    //QFile LocalizedFile(LocalizedFilePath);
    if(!fileRessource.isValid()){
        LocalizedFilePath = ":/about/" + fileName + "_en";
    }


    return QUrl("qrc" + LocalizedFilePath);
}
