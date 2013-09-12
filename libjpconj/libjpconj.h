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

#ifndef LIBJPCONJ_H
#define LIBJPCONJ_H

#include "libjpconj_global.h"
#include "inflection.h"

#include <QString>


class LIBJPCONJSHARED_EXPORT Libjpconj
{

public:
    static const char* conjugateC(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative);
    static const char* katsuyouC(const char* verb, EdictType type, KForm form);
};

extern "C" WIN_EXPORT const char* Conjugate(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative);
extern "C" WIN_EXPORT const char* Katsuyou(const char* verb, EdictType type, KForm form);

#endif // LIBJPCONJ_H
