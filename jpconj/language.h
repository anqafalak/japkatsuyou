/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

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

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "paths.h"

#include <QApplication>
#include <QDebug>
#include <QDomElement>
#include <QDomDocument>
#include <QFile>
#include <QHash>
#include <QMainWindow>
#include <QPair>
#include <QSettings>
#include <QString>
#include <QTranslator>

typedef QPair<QTranslator*, QTranslator*> PairTrans;
class Language
{
public:
    static void loadTranslations();
    static void mainWindowDirection (QMainWindow *w);
    static QString getConfigLanguage();
    static QString getCurrentLanguage();
    static void setConfigLanguage(QString langID);
    static QHash<QString, QString> getLanguagesInfo();

private:
    static QTranslator* currentQtTranslator;
    static QTranslator* currentJpconjTranslator;
    static QString currentLanguageID;
    static QHash<QString, PairTrans> translators;
    static QHash<QString, QString> languagesInfo;

    static void addTranslation(QString langId, QString dir);

public slots:
    static void setLanguage();
};

#endif // LANGUAGE_H
