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
    typedef QString (*pf)(QString, int, int, bool, bool);

     pf conj =(pf)QLibrary::resolve("liblibjpconj","conj");

     return  conj(verb, type, time, polite, positive);
}

QString libjpconjlink::conjugate(QString verb, int type, int end, int time, bool polite, bool positive)
{
    typedef QString (*pf)(QString, int, int, int, bool, bool);

     pf conjEnd =(pf)QLibrary::resolve("liblibjpconj","conjEnd");

     return  conjEnd(verb, type, end, time, polite, positive);
}
