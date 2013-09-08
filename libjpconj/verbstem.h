/*
    This file is part of libjpconj project; a library that provide
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

#ifndef VERBSTEM_H
#define VERBSTEM_H
#include "libjpconj_global.h"
#include "QString"
#include "typeDefs.h"

class Verbstem
{

public:
    Verbstem();
    static QString aForm(QString radical, VerbType type);
    static QString eForm(QString radical, VerbType type);
    static QString eImpForm(QString radical, VerbType type);
    static QString tForm(QString radical, VerbType type);
    static QString uForm(QString radical, VerbType type);
    static QString iForm(QString radical, VerbType type);
    static QString oForm(QString radical, VerbType type);
};

#endif //VERBSTEM_H
