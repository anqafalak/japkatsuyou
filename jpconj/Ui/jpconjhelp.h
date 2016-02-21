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
#ifndef HELP_H
#define HELP_H

#include "helpviewer.h"
#include "UiHelper/language.h"

//#include <QCloseEvent>
#include <QDebug>
#include <QEventLoop>
#include <QMainWindow>
#include <QHelpEngine>
#include <QHelpContentWidget>
#include <QHelpIndexWidget>
#include <QFile>
#include <QStringList>
#include <QWebFrame>

namespace Ui {
class jpconjhelp;
}

class jpconjhelp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit jpconjhelp(QWidget *parent = 0);
    ~jpconjhelp();

    static bool exists();
    
private slots:
    void on_actionClose_triggered();
    void loadPage(const QUrl &url);
    void loadPage(const QUrl &url, const QString & keyword);

    void on_indexInput_textEdited(const QString &arg1);

private:
    Ui::jpconjhelp *ui;

    QHelpEngine *helpEngine;
    HelpViewer *helpViewer;
    static bool showed;

    void Init();

signals:
    void indexInputChanged( const QString & filter, const QString & wildcard = QString());

protected:
     void closeEvent(QCloseEvent *event);

};

#endif // HELP_H
