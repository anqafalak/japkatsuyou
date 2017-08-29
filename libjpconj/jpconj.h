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

#ifndef LIBJPCONJ_H
#define LIBJPCONJ_H

#include "jpconj_global.h"
#include "typeDefs.h"
#include "inflection.h"
#include "lemmatization.h"

#include <QString>
#include <QList>

class LIBJPCONJSHARED_EXPORT JpConj
{

public:
    static QString Conjugate (QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative);
    static QString Katsuyou (QString verb, EdictType type, KForm form);
    static QList<VerbInfo> deConjugate(QString conjVerb);

};

#endif // LIBJPCONJ_H

