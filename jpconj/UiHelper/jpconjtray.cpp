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
#include "jpconjtray.h"

JpconjTray::JpconjTray(QMainWindow* parent):
    QSystemTrayIcon(parent)
{
    mainWindow = parent;
    this->setIcon(QIcon(":/img/icon.png"));

    trayMenu = new QMenu();
    this->setContextMenu(trayMenu);

    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(showMain(QSystemTrayIcon::ActivationReason)) );
}



JpconjTray::~JpconjTray()
{
}


void JpconjTray::addAction(QAction* action)
{
    trayMenu->addAction(action);
}



void JpconjTray::setConfigTraySettings(QMap<QString, bool> traySettings)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("SysTray");
    foreach (QString settingName, traySettings.keys())
        settings.setValue(settingName, traySettings.value(settingName));
    settings.endGroup();

}



bool JpconjTray::getConfigTraySetting(QString traySetting)
{
    bool result;
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("SysTray");
    result = settings.value(traySetting, true).toBool();
    settings.endGroup();

    return result;
}



void JpconjTray::hideMain()
{
    mainWindow->hide();
    this->show();
}



void JpconjTray::showMain()
{
    mainWindow->show();
    this->hide();
}



void JpconjTray::addSeparator()
{

    trayMenu->addSeparator();

}


void JpconjTray::showMain(QSystemTrayIcon::ActivationReason reason )
{
    if( reason )
        if( reason != QSystemTrayIcon::Trigger )
            return;

    showMain();
}
