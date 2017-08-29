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
