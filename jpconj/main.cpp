/*
    This file is part of JapKatsyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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

#include <QApplication>
#include "jpconjmain.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QSettings>
#include <QDesktopWidget>
#include"paths.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("DzCoding");
    a.setOrganizationDomain("https://github.com/DzCoding/");

    QSettings settings;

    QString langacro = settings.value("langacro", "def").toString();

    QTranslator myappTranslator;
    myappTranslator.load("jpconj_" + langacro, QString(dataFolder) + "i18n");
    a.installTranslator(&myappTranslator);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + langacro, QString(dataFolder) + "i18n");//QLibraryInfo::location(QLibraryInfo::TranslationsPath)
    a.installTranslator(&qtTranslator);

    jpconjmain w;

    if (langacro == "ar")
        w.setLayoutDirection(Qt::RightToLeft);

    //w.move(500, 500);
    w.show();

    return a.exec();
}
