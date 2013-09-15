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

#include "libjpconjlink.h"

sharedConjugate libjpconjlink::libConjugate = 0;
sharedKatsuyou libjpconjlink::libKatsuyou = 0;

bool libjpconjlink::Init()
{
    QLibrary library(QString(_LIB) + "libjpconj");
    if (!library.load()){
        qDebug() << "library 'libjpconj' doesn't exist";
        return false;
    }

    libConjugate = (sharedConjugate)library.resolve("Conjugate");
    if (!libConjugate)
        qDebug() << "Function 'Conjugate' doesn't exist";

    libKatsuyou = (sharedKatsuyou)library.resolve("Katsuyou");
    if (!libKatsuyou)
        qDebug() << "Function 'Katsuyou' doesn't exist";

    return true;
}

QString libjpconjlink::conjugate(QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    if (!libConjugate)
        return "";

    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

    return QString::fromUtf8(libConjugate(charVerb, type, form, polite, affirmative));
}

QString libjpconjlink::katsuyou(QString verb, EdictType type, KForm form)
{
    if (!libKatsuyou)
        return "";

    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

    return QString::fromUtf8(libKatsuyou(charVerb, type, form));
}
