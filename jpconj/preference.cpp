/*
    This file is part of JapKatsyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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

Preference::Preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preference)
{
    ui->setupUi(this);
    doInit();

}

Preference::~Preference()
{
    delete ui;
}



void Preference::doInit()
{
    QSettings settings;

    int index = settings.value("langidx",0).toInt();

    //Initialize interface language
    ui->lang->addItem(tr("Default"), QVariant("def"));
    ui->lang->addItem(tr("Arabic"), QVariant("ar"));
    ui->lang->addItem(tr("English"), QVariant("en"));

    ui->lang->setCurrentIndex(index);
}

void Preference::doSave()
{
    QSettings settings;

    int index = ui->lang->currentIndex();
    QVariant langacro = ui->lang->itemData(index);

    settings.setValue("langidx", index);
    settings.setValue("langacro", langacro);
}


void Preference::on_prefOK_accepted()
{
    doSave();
}
