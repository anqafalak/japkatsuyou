/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013-2016  AnqaFalak group
    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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
#ifndef JPCONJTRAY_H
#define JPCONJTRAY_H

#include <QApplication>
#include <QIcon>
#include <QInputContext>
#include <QObject>
#include <QPoint>
#include <QMenu>
#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>


class JpconjTray: public QSystemTrayIcon
{
    Q_OBJECT

public:
    JpconjTray(QMainWindow *parent);
    ~JpconjTray();
    void hideMain();

    static void setConfigTraySettings(QMap<QString, bool> traySettings);
    static bool getConfigTraySetting(QString traySetting);
    void addSeparator();
    void addAction(QAction* action);


private:
    QMenu *trayMenu;
    QMainWindow* mainWindow;

private slots:
    void showMain();
    void showMain(QSystemTrayIcon::ActivationReason reason);
};

#endif // JPCONJTRAY_H
