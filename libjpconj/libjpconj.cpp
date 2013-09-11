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

#include "libjpconj.h"

Libjpconj::Libjpconj()
{

}

//extern function

const char* Conjugate(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    const char* result = Libjpconj::conjugateC(verb, type, form, polite, affirmative);
    return result;
}

/*const char* Katsuyou(const char* verb, int type, int time, bool polite, bool affirmative)
{
    const char* result = Libjpconj::katsuyouC(verb, type, time, polite, affirmative);
    return result;
}*/


const char* Libjpconj::conjugateC(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    QString Qverb = QString::fromUtf8(verb);
    Qverb = Inflection::conjugate(Qverb, type, form, polite, affirmative);

    return Qverb.toUtf8().constData();
}

/*const char* Libjpconj::katsuyouC(const char* verb, int type, int time, bool polite, bool affirmative)
{
    QString Qverb = QString::fromUtf8(verb);
    Qverb = katsuyou(Qverb, type, time, polite, affirmative);

    return Qverb.toUtf8().constData();
}*/


// public functions

