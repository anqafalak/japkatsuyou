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

#ifndef LIBJPCONJ_H
#define LIBJPCONJ_H

#include "libjpconj_global.h"
//#include "string"
#include "QString"
#include "QChar"
#include "typeDefs.h"
#include "verbform.h"

class LIBJPCONJSHARED_EXPORT Libjpconj
{

public:
    Libjpconj();
    QString conjugate(QString verb, int type, int time, bool polite, bool positive);

private:
    static int getEnd(QString verb);
};

extern "C"
{
   // #include "libjpconj.h"
    QString conj(QString verb, int type, int time, bool polite, bool positive);
}

#endif // LIBJPCONJ_H
