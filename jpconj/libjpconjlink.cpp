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

#include "libjpconjlink.h"

/*!
 * \class libjpconjlink
 * This class is used as an interface between the shared library libjpconj
 * and the application.
 */

sharedConjugate libjpconjlink::libConjugate = 0;
sharedKatsuyou libjpconjlink::libKatsuyou = 0;



/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief libjpconjlink::Init Initialize the module variables.
 *
 * This function is used to initialize the functions which point on
 * the library's extern functions.
 *
 * \return Returns:
 * - True: if the library is loaded
 * - False: otherwise
 */
bool libjpconjlink::Init()
{
    QLibrary library(QString(_LIB) + "libjpconj");
    if (!library.load()){
        qDebug() << "library 'libjpconj' doesn't exist";
        return false;
    }

    libConjugate = (sharedConjugate)library.resolve("Conjugate");
    if (!libConjugate)
        qDebug() << "Function 'Conjugate' doesn't exist";

    libKatsuyou = (sharedKatsuyou)library.resolve("Katsuyou");
    if (!libKatsuyou)
        qDebug() << "Function 'Katsuyou' doesn't exist";

    return true;
}



/*!
 * \brief libjpconjlink::conjugate Gives complicated conjugation forms, such as polite positive past form (tense)
 *
 * It uses a static function in libjpconj to do its work. \n
 * It gives complex conjugation forms, using the basic stems, and adding suffixes according to parameters:
 * \b type \b, \b form \b, \b polite \b, and \b affirmative \b.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. (See VerbType::EdictType)
 * \param form Complex form (tense) which we want to conjugate to, such as: present, past, conditional, etc.
 * (See VConjugate::CForm)
 * \param polite The language can be polite or plain, ans thus verb conjugation variate according to these two.
 * (See VConjugate::Politeness)
 * \param affirmative The sentence can be affirmative (positive) or negative.
 * (See VConjugate::Polarity)
 * \return The complex verb conjugation
 */
QString libjpconjlink::conjugate(QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    if (!libConjugate)
        return "";

    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

    return QString::fromUtf8(libConjugate(charVerb, type, form, polite, affirmative));
}



/*!
 * \brief libjpconjlink::katsuyou Gives basic conjugation forms, as thought in Japanese schools
 *
 * It uses a static function in libjpconj to do its work. \n
 * It gives basic conjugation forms (or basic stems), those basic forms can be used to form
 * complex conjugation forms by adding suffixes and auxilary verbs.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type Type of the verb: v1, v5u, etc. (See VerbType::EdictType)
 * \param form Basic forms: imperfective, conjuntive, etc. (See VKatsuyou::KForm)
 * \return Basic forms conjugation
 */
QString libjpconjlink::katsuyou(QString verb, EdictType type, KForm form)
{
    if (!libKatsuyou)
        return "";

    QByteArray verbArray = verb.toUtf8();
    const char* charVerb = verbArray.constData();

    return QString::fromUtf8(libKatsuyou(charVerb, type, form));
}
