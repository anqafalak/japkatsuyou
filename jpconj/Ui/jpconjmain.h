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
#include "conjframe.h"
#include "Conj/edict2.h"
#include "UiHelper/export.h"
#include "jpconjhelp.h"
#include "UiHelper/jpconjtray.h"
#include "UiHelper/language.h"
#include "UiHelper/msg.h"
#include "preference.h"
#include "UiHelper/style.h"

#include "typeDefs.h"
#include "jpconj.h"

#include <QApplication>
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QFileDialog>
#include <QHash>
#include <QMainWindow>
#include <QMap>
#include <QObject>
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
    FuncFrame *workfrm;
    bool hasContent;
    bool languageChanged;
    EdictType verbType;
    QString currentVerb;
    JpconjTray* trayIconSys;
    QString stylesheet;

    QAction *actionShow;

    void doInit();

    //Functions related to actions slots
    void openAbout();
    void openPref();
    void doExport();
    void doPrint();
    void openHelp();
    void zoom(signed char sign);
    void createTryIcon();

    //HTML-related functions
    void setCSS(QWebView * webView, QString nameCSS);
    void setHTMLTranslation (bool rtl);

protected:
    void changeEvent(QEvent* event);
    void closeEvent(QCloseEvent *event);

private slots:
    void changeStyle(QString styleID);

    void workfrmOpen();
    void workfrmClose();

    void on_actionClose_triggered();
    void on_actionAbout_triggered();
    void on_actionPreference_triggered();
    void on_actionHelpContent_triggered();
    void on_actionExportResult_triggered();
    void on_actionPrint_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionNormalSize_triggered();
    void on_actionHide_triggered();
    void on_actionContactUs_triggered();
    void on_actionHomePage_triggered();
};

#endif // JPCONJMAIN_H
