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

#ifndef JPCONJMAIN_H
#define JPCONJMAIN_H

#include <QMainWindow>
#include <QTextEdit>
#include "ui_jpconjmain.h"
#include "QDebug"
#include "libjpconjlink.h"
#include "about.h"
#include "preference.h"
#include "edict2.h"
#include <QMap>
#include "paths.h"

namespace Ui {
class jpconjmain;
}

class jpconjmain : public QMainWindow
{
    Q_OBJECT

public slots:


public:
    explicit jpconjmain(QWidget *parent = 0);
    ~jpconjmain();
    
private slots:
    void on_action_Close_triggered();

    void on_btn_conj_clicked();

    void on_action_About_triggered();

    void on_action_Preference_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::jpconjmain *ui;
    About     *winAbout;
    Preference *winPref;

    void doInit();
    void doConj();
    void openPref();
    void openAbout();

    void tenseConj(const QString verb, const int time, const int type, const int end);


    static QMap <int, QString> initConjTime();
};

#endif // JPCONJMAIN_H
