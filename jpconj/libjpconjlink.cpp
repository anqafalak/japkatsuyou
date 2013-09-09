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


QString libjpconjlink::conjugate(QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{

     QLibrary library(QString(_LIB) + "libjpconj");
     if (!library.load()){
         qDebug() << "library doesn't exist";
         return "";
     }

     typedef const char* (*sharedfunc)(const char*, EdictType, CForm, Politeness, Polarity);
     sharedfunc libConjugate = (sharedfunc)library.resolve("Conjugate");
     if (!libConjugate){
         qDebug() << "Function doesn't exist";
         return "";
     }

     QByteArray verbArray = verb.toUtf8();
     const char* charVerb = verbArray.constData();

     return QString::fromUtf8(libConjugate(charVerb, type, form, polite, affirmative));


}
