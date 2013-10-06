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
#include "export.h"
#include "jpconjhelp.h"
#include "language.h"
#include "msg.h"
#include "preference.h"

#include "typeDefs.h"
#include "jpconj.h"

#include <QDebug>
#include <QFileDialog>
#include <QHash>
#include <QMainWindow>
#include <QMap>
#include <QWebElement>
#include <QWebFrame>
#include <QWebView>
#include <QMessageBox>



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
    static bool rtl;
    static bool hasContent;
    static bool languageChanged;
    static QString currentVerb;

    void doInit();

    //Functions related to actions slots
    void openAbout();
    void openPref();
    void doConj();
    void doExport();
    void openHelp();

    //Functions related to conjugation
    void basicConjugation(QString verb, EdictType type);
    void complexConjugation(QString verb, EdictType type);

    //HTML-related functions
    QString readHtmlFile(QString URL);
    void setCSS(QWebView * webView, QString nameCSS);
    void setHTMLTranslation ();

protected:
    void changeEvent(QEvent* event);

private slots:
    void on_actionClose_triggered();
    void on_conjugateButton_clicked();
    void on_actionAbout_triggered();
    void on_actionPreference_triggered();
    void on_actionHelpContent_triggered();
    void on_inputConjVerb_returnPressed();
    void on_actionExportResult_triggered();
};

#endif // JPCONJMAIN_H
