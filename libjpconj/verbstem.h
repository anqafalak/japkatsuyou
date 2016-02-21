/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
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
