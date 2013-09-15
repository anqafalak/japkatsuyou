/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>
            Zakaria Smahi <zakaria08esi@gmail.com>

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

#include "jpconjmain.h"
#include "ui_jpconjmain.h"

jpconjmain::jpconjmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jpconjmain)
{
    ui->setupUi(this);
    doInit();
}

jpconjmain::~jpconjmain()
{
    delete ui;
}

void jpconjmain::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        //Msg::updateMsg();
        ui->retranslateUi(this);
        Language::mainWindowDirection(this);

    }
    QMainWindow::changeEvent(event);
}


//private functions

void jpconjmain::openAbout()
{
    winAbout = new About(this);
    winAbout->setLayoutDirection(this->layoutDirection());
    winAbout->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    winAbout->show();

}

void jpconjmain::openPref()
{
    winPref = new Preference(this);
    winPref->setLayoutDirection(this->layoutDirection());
    winPref->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    winPref->show();
}

void jpconjmain::doInit()
{
    qDebug()<< QString(VERSION);
    libjpconjlink::Init();
    Language::loadTranslations();
    Language::mainWindowDirection(this);
    ui->menu_View->addAction(ui->mainTool->toggleViewAction());
    ui->menu_View->addAction(ui->search->toggleViewAction());
    //ui->showt->setLayoutDirection(Qt::LeftToRight);
}

void jpconjmain::basicConjugation()
{
    QString resultHTML ="<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" />";

}

void jpconjmain::doConj()
{
    ui->showt->setRowCount(0);

    QString verb = ui->inputt->text();

    QStringList vlist;

    Edict2 edict2;

    EdictType type = edict2.find(verb);

    if (type < 1)
    {
        ui->msgt->setText(Msg::getVerbTypeDesc(type));
        ui->showt->setColumnCount(0);
    }
    else
    {
        ui->showt->setColumnCount(4);
        QStringList hlist;

        hlist << Msg::getVerbPolitenessName(VConjugate::_Polite) + " " + Msg::getVerbPolarityName(VConjugate::_Affirmative);
        hlist << Msg::getVerbPolitenessName(VConjugate::_Polite) + " " + Msg::getVerbPolarityName(VConjugate::_Negative);
        hlist << Msg::getVerbPolitenessName(VConjugate::_Plain) + " " + Msg::getVerbPolarityName(VConjugate::_Affirmative);
        hlist << Msg::getVerbPolitenessName(VConjugate::_Plain) + " " + Msg::getVerbPolarityName(VConjugate::_Negative);

        ui->showt->setHorizontalHeaderLabels(hlist);

        ui->msgt->setText(Msg::getVerbTypeDesc(type));

        //foreach (CForm form, formsMsg.keys())
        foreach (CForm form, Msg::verbFormsList())
        {
            vlist << Msg::getVerbFormName(form);
            tenseConj(verb, type, form);
        }

        ui->showt->setVerticalHeaderLabels(vlist);

        int i=0;
        foreach(CForm form, Msg::verbFormsList()){
            ui->showt->verticalHeaderItem(i)->setToolTip(Msg::getVerbFormDesc(form));
            i++;
        }

    }

}


void jpconjmain::tenseConj(const QString verb, EdictType type, CForm form)
{

    QString result = "";
    int rownum = ui->showt->rowCount();

    ui->showt->insertRow(rownum);
    QTableWidgetItem* item;

    // Polite, Positive
    result = libjpconjlink::conjugate(verb, type, form, _Polite, _Affirmative).remove("|");
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft );
    ui->showt->setItem(rownum,0,item);

    // Polite, Negative
    result = libjpconjlink::conjugate(verb, type, form, _Polite, _Negative).remove("|");
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,1,item);

    //Common, Positive
    result = libjpconjlink::conjugate(verb, type, form, _Plain, _Affirmative).remove("|");
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,2,item);

    //common, Negative
    result = libjpconjlink::conjugate(verb, type, form, _Plain, _Negative).remove("|");
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,3,item);
}


// Private Slots

void jpconjmain::on_action_Close_triggered()
{
    this->close();
}

void jpconjmain::on_btn_conj_clicked()
{
    doConj();
}

void jpconjmain::on_action_About_triggered()
{
    openAbout();
}

void jpconjmain::on_action_Preference_triggered()
{
    openPref();
}

void jpconjmain::on_actionHelp_Content_triggered()
{

}
