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

#include "libjpconj.h"

/*!
 * \class Libjpconj
 * This class is the interface between Library-inside functions and the outside of the library
 */


/*!
 * \brief Conjugate Extern function that Gives complicated conjugation forms, such as polite positive past form (tense)
 *
 * It gives complex conjugation forms, using the basic stems, and adding suffixes according to parameters:
 * \b type \b, \b form \b, \b polite \b, and \b affirmative \b.
 * It can be called from an application that use this library.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. See typeDefs.h
 * \param form Complex form (tense) which we want to conjugate to, such as: present, past, conditional, etc.
 * \param polite The language can be polite or plain, ans thus verb conjugation variate according to these two.
 * \param affirmative The sentence can be affirmative (positive) or negative
 * \return The complex verb conjugation
 */
const char* Conjugate(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    const char* result = Libjpconj::conjugateC(verb, type, form, polite, affirmative);
    return result;
}

/*!
 * \brief Katsuyou Extern function that Gives basic conjugation forms, as thought in Japanese schools
 *
 * It gives basic conjugation forms (or basic stems), those basic forms can be used to form
 * complex conjugation forms by adding suffixes and auxilary verbs.
 * It can be called from an application that use this library.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. See typeDefs.h
 * \param form Basic forms: imperfective, conjuntive, etc.
 * \return Basic forms conjugation
 */
const char* Katsuyou(const char* verb, EdictType type, KForm form)
{
    const char* result = Libjpconj::katsuyouC(verb, type, form);
    return result;
}



/*!
 * \brief Libjpconj::conjugateC Intermediate function that Gives complicated conjugation forms,
 * such as polite positive past form (tense)
 *
 * It gives complex conjugation forms, using the basic stems, and adding suffixes according to parameters:
 * \b type \b, \b form \b, \b polite \b, and \b affirmative \b.
 * This is an intermediate function between Extern function and Inflection::Conjugate .
 * Its role is to convert between C and Qt/C++ variables.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. See typeDefs.h
 * \param form Complex form (tense) which we want to conjugate to, such as: present, past, conditional, etc.
 * \param polite The language can be polite or plain, ans thus verb conjugation variate according to these two.
 * \param affirmative The sentence can be affirmative (positive) or negative
 * \return The complex verb conjugation
 */
const char* Libjpconj::conjugateC(const char* verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    QString Qverb = QString::fromUtf8(verb);
    Qverb = Inflection::conjugate(Qverb, type, form, polite, affirmative);

    return Qverb.toUtf8().constData();
}



/*!
 * \brief Libjpconj::katsuyouC Intermediate function that Gives basic conjugation forms, as thought in Japanese schools
 *
 * It gives basic conjugation forms (or basic stems), those basic forms can be used to form
 * complex conjugation forms by adding suffixes and auxilary verbs.
 * This is an intermediate function between Extern function and Inflection::Katsuyou().
 * Its role is to convert between C and Qt/C++ variables.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. See typeDefs.h
 * \param form Basic forms: imperfective, conjuntive, etc.
 * \return Basic forms conjugation
 */
const char* Libjpconj::katsuyouC(const char* verb, EdictType type, KForm form)
{
    QString Qverb = QString::fromUtf8(verb);
    Qverb = Inflection::katsuyou(Qverb, type, form);

    return Qverb.toUtf8().constData();
}
