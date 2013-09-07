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

#include "jpconjmain.h"
#include "qdialog.h"
#include "QStringList"


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

    ui->menu_View->addAction(ui->mainTool->toggleViewAction());
    ui->menu_View->addAction(ui->search->toggleViewAction());

}

void jpconjmain::doConj()
{



    ui->showt->setRowCount(0);

    /*
    QString conjTimeStr[] = {
        tr("Present"),
        tr("Past"),
        tr("Provisional Condition"),
        tr("Condition"),
        tr("Imperative"),
        tr("Volitional"),
        tr("Present Continuous"),
        tr("Past Continuous"),
        tr("Passive"),
        tr("Causative"),
        tr("Causative Passive"),
        tr("Potential"),
        tr("Reason")
    };

    int conjTimeInt[13] = {
        _Present,
        _Past,
        _Provision,
        _Condition,
        _Imperative,
        _Volitional,
        _PresentContinuous,
        _PastContinuous,
        _Passive,
        _Causative,
        _CausativePassive,
        _Potential,
        _Reason
    };*/

    QMap <int, QString> conjTime = initConjTime();


    QString verb = ui->inputt->text();
    int type = 0;
    int end = 0;

    QStringList vlist;

    Edict2 edict2;

    int edict2type = edict2.find(verb);

    Edict2::getType(edict2type, type, end);

    if (end < 0)
    {
        ui->msgt->setText(tr("This verb doesn't exist in the database."));
        ui->showt->setColumnCount(0);
    }
    else
    {
        ui->showt->setColumnCount(4);
        QStringList hlist;
        hlist << tr("Polite Postive") << tr("Polite Negative") << tr("Informal Positive") << tr("Informal Negative");
        ui->showt->setHorizontalHeaderLabels(hlist);

        ui->msgt->setText(tr("This verb is found"));

        foreach (int time, conjTime.keys())
        {
            vlist << conjTime.value(time);
            tenseConj(verb, time, type, end);
        }

    }

    ui->showt->setVerticalHeaderLabels(vlist);
}

QMap <int, QString> jpconjmain::initConjTime(){
    QMap <int, QString> result;
    result.insert(_Present,tr("Present"));
    result.insert(_Past,tr("Past"));
    result.insert(_Provision,tr("Provisional Condition"));
    result.insert(_Condition,tr("Condition"));
    result.insert(_Imperative,tr("Imperative"));
    result.insert(_Volitional,tr("Volitional"));
    result.insert(_PresentContinuous,tr("Present Continuous"));
    result.insert(_PastContinuous,tr("Past Continuous"));
    result.insert(_Passive,tr("Passive"));
    result.insert(_Causative,tr("Causative"));
    result.insert(_CausativePassive,tr("Causative Passive"));
    result.insert(_Potential,tr("Potential"));
    result.insert(_Reason,tr("Reason"));

    return result;
}

void jpconjmain::tenseConj(const QString verb, const int time, const int type, const int end)
{

    QString result = "";
    int rownum = ui->showt->rowCount();

    ui->showt->insertRow(rownum);
    QTableWidgetItem* item;

    // Polite, Positive
    result = libjpconjlink::conjugate(verb, type, end, time, true, true);
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,0,item);

    // Polite, Negative
    result = libjpconjlink::conjugate(verb, type, end, time, true, false);
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,1,item);

    //Common, Positive
    result = libjpconjlink::conjugate(verb, type, end, time, false, true);
    item = new QTableWidgetItem(result);
    item->setTextAlignment(Qt::AlignAbsolute + Qt::AlignLeft);
    ui->showt->setItem(rownum,2,item);

    //common, Negative
    result = libjpconjlink::conjugate(verb, type, end, time, false, false);
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

void jpconjmain::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}
