/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

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

#ifndef JPCONJMAIN_H
#define JPCONJMAIN_H

#include "about.h"
#include "conjframe.h"
#include "Func/edict2.h"
#include "UiHelper/export.h"
#include "jpconjhelp.h"
#include "UiHelper/jpconjtray.h"
#include "UiHelper/language.h"
#include "UiHelper/msg.h"
#include "preference.h"
#include "UiHelper/style.h"
#include "Func/tatoeba.h"

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

    void doExamples();

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
    void newVerb(QString verb);

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
