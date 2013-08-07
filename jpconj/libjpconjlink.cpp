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

#include "libjpconjlink.h"

libjpconjlink::libjpconjlink()
{
}


QString libjpconjlink::conjugate(QString verb, int type, int time, bool polite, bool positive)
{
    typedef const char* (*pf)(const char*, int, int, bool, bool);

    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

     pf conj =(pf)QLibrary::resolve("liblibjpconj","conj");

     return  QString::fromUtf8(conj(charVerb, type, time, polite, positive));
}

QString libjpconjlink::conjugate(QString verb, int type, int end, int time, bool polite, bool positive)
{
    typedef const char* (*pf)(const char*, int, int, int, bool, bool);

    //const char* charVerb = verb.toUtf8().constData();
    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

     pf conjEnd =(pf)QLibrary::resolve("liblibjpconj","conjEnd");

     return  QString::fromUtf8(conjEnd(charVerb, type, end, time, polite, positive));
}
