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

#ifndef VERBSTEM_H
#define VERBSTEM_H

#include "typeDefs.h"

#include <QString>


class Verbstem
{

public:

    static QString aForm(QString radical, EdictType type);
    static QString eForm(QString radical, EdictType type);
    static QString eImpForm(QString radical, EdictType type);
    static QString tForm(QString radical, EdictType type);
    static QString uForm(QString radical, EdictType type);
    static QString iForm(QString radical, EdictType type);
    static QString oForm(QString radical, EdictType type);
};

#endif //VERBSTEM_H
