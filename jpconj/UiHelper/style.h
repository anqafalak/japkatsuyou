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
    void signalFontChanged(QString font, QString jpfont, int size, int jpsize);

    static void loadStyles();
    static QHash<QString, Styleinfo *> getStyleInfo();
    static void setStyle();
    static void setFont();
    static QString getConfigStyle();
    static QString getCurrentStyle();
    static void setConfigStyle(QString styleID);
    static void addReceiver(const QObject * receiver, const char * receiverSlot);
    static void addFontReceiver(const QObject * receiver, const char * receiverSlot);

    static QString getConfigFont(bool jap);
    static QString getCurrentFont(bool jap);
    static void setConfigFont(QString font, bool jap);
    static int getConfigFontSize(bool jap);
    static int getCurrentFontSize(bool jap);
    static void setConfigFontSize(int fontSize, bool jap);

private:
    static QHash<QString, Styleinfo*> styles;
    static QString currentstyle;
    static QString currentFont;
    static QString currentJpFont;
    static int currentFontSize;
    static int currentJpFontSize;
    //static Style* getInstance();
    static Style* _instance;


signals:
    void styleChanged(QString styleID);
    void fontChanged(QString font, QString jpfont, int size, int jpsize);

};

#endif // STYLE_H
