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

#ifndef JPCONJMAIN_H
#define JPCONJMAIN_H

#include "about.h"
#include "edict2.h"
#include "language.h"
#include "libjpconjlink.h"
#include "msg.h"
#include "preference.h"
#include "typeDefs.h"

#include <QDebug>
#include <QMainWindow>
#include <QMap>
#include <QWebView>


namespace Ui {
class jpconjmain;
}

class jpconjmain : public QMainWindow
{
    Q_OBJECT

public:
    explicit jpconjmain(QWidget *parent = 0);
    ~jpconjmain();

private:
    Ui::jpconjmain *ui;
    About     *winAbout;
    Preference *winPref;

    void doInit();

    //Functions related to actions slots
    void openAbout();
    void openPref();
    void doConj();

    //Functions related to conjugation
    void basicConjugation(QString verb, EdictType type);
    void complexConjugation(QString verb, EdictType type);

    QString readHtmlFile(QString URL);
    void setCSS(QWebView * webView, QString nameCSS);

protected:
    void changeEvent(QEvent* event);

private slots:
    void on_action_Close_triggered();

    void on_btn_conj_clicked();

    void on_action_About_triggered();

    void on_action_Preference_triggered();

    void on_actionHelp_Content_triggered();
};

#endif // JPCONJMAIN_H
