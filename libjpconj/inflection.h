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

#ifndef INFLECTION_H
#define INFLECTION_H

#include "typeDefs.h"
#include "verbstem.h"

#include <QString>


class Inflection
{
public:
    static QString conjugate(QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative);
    static QString katsuyou(QString verb, EdictType type, KForm form);

private:
    static QString tEnd(QString end, bool te);
    static int getEnd(QString verb); //Not used, it's just for future reference, if it appears some _v5 verbs (unknown end)
};

#endif // INFLECTION_H
