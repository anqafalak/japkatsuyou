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

#include "jpconj.h"

/*!
 * \brief JpConj::Conjugate
 * \param verb
 * \param type
 * \param form
 * \param polite
 * \param affirmative
 * \return
 */
QString JpConj::Conjugate (QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    return Inflection::conjugate(verb, type, form, polite, affirmative);
}



/*!
 * \brief JpConj::Katsuyou
 * \param verb
 * \param type
 * \param form
 * \return
 */
QString JpConj::Katsuyou (QString verb, EdictType type, KForm form)
{
    return Inflection::katsuyou(verb, type, form);
}


/*!
 * \brief deConjugate
 * \param conjVerb
 * \return
 */
QList<VerbInfo> deConjugate(QString conjVerb)
{
    return NULL;
}
