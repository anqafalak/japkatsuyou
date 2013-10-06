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
