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
#ifndef STYLE_H
#define STYLE_H

#include <QCustomEvent>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QHash>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QStringList>

class Styleinfo
{
public:
    Styleinfo();
    QString name;
    QString author;
    QString date;
    QString desc;
};


class Style : public QObject
{
    Q_OBJECT

public:
    Style();
    void emitSignal(QString styleID);
    static void loadStyles();
    static QHash<QString, Styleinfo *> getStyleInfo();
    static void setStyle();
    static QString getConfigStyle();
    static QString getCurrentStyle();
    static void setConfigStyle(QString styleID);
    static void addReceiver(const QObject * receiver, const char * receiverSlot);

private:
    static QHash<QString, Styleinfo*> styles;
    static QString currentstyle;
    //static Style* getInstance();
    static Style* _instance;


signals:
    void styleChanged(QString styleID);
};

#endif // STYLE_H
