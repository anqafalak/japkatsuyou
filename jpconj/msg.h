/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

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

#ifndef MSG_H
#define MSG_H

#include "typeDefs.h"

#include <QApplication>
#include <QHash>
#include <QMap>
#include <QString>


#ifdef __GNUC__
#define NO_USE_FUNC __attribute__ ((unused))
#else
#define NO_USE_FUNC
#endif

/*! Msg namespace (abbr. Messages) is used to store all strings used to internationalize the application.
 * It contains also, some lists which help speeding things up.
 *
 * In all functions we used NO_USE_FUNC to stop "function-not-used" warnings in case of GCC compiler.
 * This is its definition: \n
 * #ifdef \_\_GNUC\_\_ \n
 * #define NO_USE_FUNC \_\_attribute\_\_ ((unused)) \n
 * #else \n
 * #define NO_USE_FUNC \n
 * #endif \n
 */
namespace Msg {

/*! Gives the list of extensions used to export the resulted conjugation tables, and their descriptions
 */
static QHash<QString, QString> NO_USE_FUNC getExportExtensions()
{
    QHash<QString, QString> resultHash;
    resultHash.insert(".pdf",
                     qApp->translate("ExportResult", "Pdf file"));
    resultHash.insert(".odt",
                     qApp->translate("ExportResult", "OpenDocument file"));

    return resultHash;
}



/*! Strings used in Message box: file already exists
 */
static QString NO_USE_FUNC fileExists(bool title)
{
    if (title)
        return qApp->translate("ExportResult", "File already exists");

    return qApp->translate("ExportResult", "This file exists, do you want to overwrite it?");
}



/*! Gives a list of complex conjugation forms (See: VConjugate::CForm).\n
 * This list makes it easier to loop over the different complex conjugation forms.
 */
static QMap<CForm, QString> NO_USE_FUNC complexFormsMap()
{
    QMap<CForm, QString> resultMap;
    resultMap.insert(VConjugate::_Present, "present");
    resultMap.insert(VConjugate::_Past, "past");
    resultMap.insert(VConjugate::_Provision, "provision");
    resultMap.insert(VConjugate::_Condition, "condition");
    resultMap.insert(VConjugate::_Imperative, "imperative");
    resultMap.insert(VConjugate::_Volitional, "volutional");
    resultMap.insert(VConjugate::_PresentContinuous, "presentcontinuous");
    resultMap.insert(VConjugate::_PastContinuous, "pastcontinuous");
    resultMap.insert(VConjugate::_Passive, "passive");
    resultMap.insert(VConjugate::_Causative, "causative");
    resultMap.insert(VConjugate::_CausativePassive, "causativepassive");
    resultMap.insert(VConjugate::_Potential, "potential");

    return resultMap;
}



/*! Gives the verb complex form name in the current language.\n
 * For example, for VConjugate::_Present we get "present" in English
 */
static QString NO_USE_FUNC getVerbFormName(CForm form)
{
    switch (form){
    case VConjugate::_TeForm:
        return qApp->translate("verbFormNames", "Te form");
    case VConjugate::_Present:
        return qApp->translate("verbFormNames", "Present");
    case VConjugate::_Past:
        return qApp->translate("verbFormNames", "Past");
    case VConjugate::_Provision:
        return qApp->translate("verbFormNames", "Provisional Condition");
    case VConjugate::_Condition:
        return qApp->translate("verbFormNames", "Conditional");
    case VConjugate::_Imperative:
        return qApp->translate("verbFormNames", "Imperative");
    case VConjugate::_Volitional:
        return qApp->translate("verbFormNames", "Volitional");
    case VConjugate::_PresentContinuous:
        return qApp->translate("verbFormNames", "Present Continuous");
    case VConjugate::_PastContinuous:
        return qApp->translate("verbFormNames", "Past Continuous");
    case VConjugate::_Passive:
        return qApp->translate("verbFormNames", "Passive");
    case VConjugate::_Causative:
        return qApp->translate("verbFormNames", "Causative");
    case VConjugate::_CausativePassive:
        return qApp->translate("verbFormNames", "Causative Passive");
    case VConjugate::_Potential:
        return qApp->translate("verbFormNames", "Potential");
    default:
        break;
    }

    return "";
}



/*! Gives the verb complex form description in the current language.\n
 * For example, for VConjugate::_Present we get "This is the present tense." in English
 */
static QString NO_USE_FUNC getVerbFormDesc(CForm form)
{
    switch (form){
    case VConjugate::_TeForm:
        return qApp->translate("verbFormDesc", "It's a form used for many purposes, like successive actions.");
    case VConjugate::_Present:
        return qApp->translate("verbFormDesc", "This is the present tense.");
    case VConjugate::_Past:
        return qApp->translate("verbFormDesc", "This is the past tense.");
    case VConjugate::_Provision:
        return qApp->translate("verbFormDesc", "The provisional conditional form is used: - In conditionals where the emphasis rests more on the condition than the result;  - Expressing obligations.");
    case VConjugate::_Condition:
        return qApp->translate("verbFormDesc", "It can be used in the same way as the provisional condition form. However, it implies more certainty about the condition.");
    case VConjugate::_Imperative:
        return qApp->translate("verbFormDesc", "The imperative form is used to give an order to someone.");
    case VConjugate::_Volitional:
        return qApp->translate("verbFormDesc", "In general, the volitional form expresses intention, eg. Let's... or Shall we...");
    case VConjugate::_PresentContinuous:
        return qApp->translate("verbFormDesc", "This is the present continuous tense.");
    case VConjugate::_PastContinuous:
        return qApp->translate("verbFormDesc", "This is the past continuous tense.");
    case VConjugate::_Passive:
        return qApp->translate("verbFormDesc", "This is the passive voice of the verb.");
    case VConjugate::_Causative:
        return qApp->translate("verbFormDesc", "The causative is used for: - Making someone do something; - Letting someone do something.");
    case VConjugate::_CausativePassive:
        return qApp->translate("verbFormDesc", "It is used to express causation passively.");
    case VConjugate::_Potential:
        return qApp->translate("verbFormDesc", "The potential is used to express that one has the ability to do something.");
    default:
        break;
    }

    return "";
}



/*! Gives the verb type description in the current language.\n
 * For example, for VerbType::_v1 we get "Ichidan verb." in English
 */
static QString NO_USE_FUNC getVerbTypeDesc(EdictType type)
{
    switch (type){
    case VerbType::_v0:
        return qApp->translate("verbTypeDesc", "This verb doesn't exist in the database.");
    case VerbType::_v1:
        return qApp->translate("verbTypeDesc", "Ichidan verb.");
    case VerbType::_v2a_s:
        return qApp->translate("verbTypeDesc", "Nidan verb with 'u' ending (archaic).");
    case VerbType::_v4h:
        return qApp->translate("verbTypeDesc", "Yondan verb with 'hu/fu' ending (archaic).");
    case VerbType::_v4r:
        return qApp->translate("verbTypeDesc", "Yondan verb with 'ru' ending (archaic).");
    case VerbType::_v5:
        return qApp->translate("verbTypeDesc", "Godan verb (not completely classified).");
    case VerbType::_v5aru:
        return qApp->translate("verbTypeDesc", "Godan verb -aru special class.");
    case VerbType::_v5b:
        return qApp->translate("verbTypeDesc", "Godan verb with 'bu' ending.");
    case VerbType::_v5g:
        return qApp->translate("verbTypeDesc", "Godan verb with 'gu' ending.");
    case VerbType::_v5k:
        return qApp->translate("verbTypeDesc", "Godan verb with 'ku' ending.");
    case VerbType::_v5k_s:
        return qApp->translate("verbTypeDesc", "Godan verb - iku/yuku special class.");
    case VerbType::_v5m:
        return qApp->translate("verbTypeDesc", "Godan verb with 'mu' ending.");
    case VerbType::_v5n:
        return qApp->translate("verbTypeDesc", "Godan verb with 'nu' ending.");
    case VerbType::_v5r:
        return qApp->translate("verbTypeDesc", "Godan verb with 'ru' ending.");
    case VerbType::_v5r_i:
        return qApp->translate("verbTypeDesc", "Godan verb with 'ru' ending (irregular verb).");
    case VerbType::_v5s:
        return qApp->translate("verbTypeDesc", "Godan verb with 'su' ending.");
    case VerbType::_v5t:
        return qApp->translate("verbTypeDesc", "Godan verb with 'tsu' ending.");
    case VerbType::_v5u:
        return qApp->translate("verbTypeDesc", "Godan verb with 'u' ending.");
    case VerbType::_v5u_s:
        return qApp->translate("verbTypeDesc", "Godan verb with 'u' ending (special class).");
    case VerbType::_v5uru:
        return qApp->translate("verbTypeDesc", "Godan verb - uru old class verb (old form of Eru).");
    case VerbType::_v5z:
        return qApp->translate("verbTypeDesc", "Godan verb with 'zu' ending.");
    case VerbType::_vz:
        return qApp->translate("verbTypeDesc", "Ichidan verb - zuru verb - (alternative form of -jiru verbs).");
    case VerbType::_vk:
        return qApp->translate("verbTypeDesc", "Kuru verb - special class.");
    case VerbType::_vn:
        return qApp->translate("verbTypeDesc", "Irregular nu verb.");
    case VerbType::_vs:
        return qApp->translate("verbTypeDesc", "Noun or participle which takes the aux. verb suru.");
    case VerbType::_vs_c:
        return qApp->translate("verbTypeDesc", "Su verb - precursor to the modern suru.");
    case VerbType::_vs_i:
        return qApp->translate("verbTypeDesc", "Suru verb - irregular.");
    case VerbType::_vs_s:
        return qApp->translate("verbTypeDesc", "Suru verb - special class.");

    }

    return "";
}



/*! Gives the conjugation politness name in the current language.\n
 * For example, for VConjugate::_Plain we get "Plain" in English
 */
static QString NO_USE_FUNC getVerbPolitenessName(Politeness polite)
{
    switch (polite) {
    case VConjugate::_Plain:
        return qApp->translate("verbPolitenessDesc", "Plain");
    case VConjugate::_Polite:
        return qApp->translate("verbPolitenessDesc", "Polite");
    default:
        break;
    }

    return "";
}



/*! Gives the conjugation politness description in the current language.\n
 * For example, for VConjugate::_Plain we get "Plain form of a sentence; it is used with friends." in English
 */
static QString NO_USE_FUNC getVerbPolitenessDesc(Politeness polite)
{
    switch (polite) {
    case VConjugate::_Plain:
        return qApp->translate("verbPolitenessDesc", "Plain form of a sentence; it is used with friends.");
    case VConjugate::_Polite:
        return qApp->translate("verbPolitenessDesc", "Polite form of a sentence; it is used in official discussion.");
    default:
        break;
    }

    return "";
}



/*! Gives the conjugation polarity name in the current language.\n
 * For example, for VConjugate::_Negative we get "Negative" in English
 */
static QString NO_USE_FUNC getVerbPolarityName(Polarity affirmative)
{
    switch (affirmative) {
    case VConjugate::_Negative:
        return qApp->translate("verbPolarityDesc", "Negative");
    case VConjugate::_Affirmative:
        return qApp->translate("verbPolarityDesc", "Affirmative");
    default:
        break;
    }

    return "";
}



/*! Gives the conjugation polarity description in the current language. \n
 * For example, for VConjugate::_Negative we get "Form used in negative sentences." in English
 */
static QString NO_USE_FUNC getVerbPolarityDesc(Polarity affirmative)
{
    switch (affirmative) {
    case VConjugate::_Negative:
        return qApp->translate("verbPolarityDesc", "Form used in negative sentences.");
    case VConjugate::_Affirmative:
        return qApp->translate("verbPolarityDesc", "Form used in affirmative sentences.");
    default:
        break;
    }

    return "";
}



/*! Gives a QMap containing KForm as key and QString as value. \n
 * It is used to make it easier to replace HTML variables with results of basic conjugation. \n
 * For example, if we have a variable called "&stem\_a&" in an HTML file. \n
 * Supposing the HTML content is stored in a QString htmlContent. \n
 * Then we can replace the string "&stem\_a&" with the value of
 * libjpconjlink::katsuyou(verb, type, VKatsuyou::_Imperfective_a);\n
 * \n
 * Using this QMap, we can loop over all the existant KForm and replace the contents \n
 * Example (Assuming basicConjHTML is a QString containing HTML content) \n
 * \snippet jpconjmain.cpp Doxygen: basicFormsMap example
 */
static QMap<KForm, QString> NO_USE_FUNC basicFormsMap()
{
    QMap<KForm, QString> resultMap;
    resultMap.insert(VKatsuyou::_Imperfective_a, "a");
    resultMap.insert(VKatsuyou::_Imperfective_o, "o");
    resultMap.insert(VKatsuyou::_Conjunctive_i, "i");
    resultMap.insert(VKatsuyou::_Conjunctive_t, "t");
    resultMap.insert(VKatsuyou::_Terminal_u, "u");
    resultMap.insert(VKatsuyou::_Attributive_u, "uAtt");
    resultMap.insert(VKatsuyou::_Hypothetical_e, "e");
    resultMap.insert(VKatsuyou::_Imperative_e, "eImp");

    return resultMap;
}



/*! Gives the replacement of HTML variables in Msg::verbStringsList in the current language
 * Giving its number in the QList afforded by this function.
 */
static QString NO_USE_FUNC getTranslatedString(QString elementId)
{

    if (elementId == "_Stem")
        return qApp->translate("conjugationStrings", "Stem");

    if (elementId == "_Verb")
        return qApp->translate("conjugationStrings", "Verb");

    if (elementId == "_Suffix")
        return qApp->translate("conjugationStrings", "Suffix");

    if (elementId == "_WordsAfter")
        return qApp->translate("conjugationStrings", "Words that come after");

    if (elementId == "_Form")
        return qApp->translate("conjugationStrings", "Form name");

    if (elementId == "_BasicConj")
        return qApp->translate("conjugationStrings", "Basic Conjugation");

    return "";
}



/* Gives a list of predefined QStrings used as reeplacement variables in HTML.
 */
/*static QList<QString> NO_USE_FUNC verbStringsList()
{
    QList<QString> resultList;
    resultList << "&_Stem&";
    resultList << "&_Verb&";
    resultList << "&_Suffix&";
    resultList << "&_WordsAfter&";
    resultList << "&_Form&";
    resultList << "&_BasicConj&";
    return resultList;
}*/



/*! Gives the verb basic form name in the current language.\n
 * For example, for VKatsuyou::_Imperfective_a we get "Imperfective (general)" in English
 */
static QString NO_USE_FUNC getBasicFormName(KForm form)
{
    switch (form){
    case VKatsuyou::_Imperfective_a:
        return qApp->translate("basicFormName", "Imperfective (general)");

    case VKatsuyou::_Hypothetical_e:
        return qApp->translate("basicFormName", "Hypothetical");

    case VKatsuyou::_Imperative_e:
        return qApp->translate("basicFormName", "Imperative");

    case VKatsuyou::_Conjunctive_t:
        return qApp->translate("basicFormName", "Conjunctive (other)");

    case VKatsuyou::_Terminal_u:
        return qApp->translate("basicFormName", "Terminal");

    case VKatsuyou::_Attributive_u:
        return qApp->translate("basicFormName", "Attributive");

    case VKatsuyou::_Conjunctive_i:
        return qApp->translate("basicFormName", "Conjunctive (_i)");

    case VKatsuyou::_Imperfective_o:
        return qApp->translate("basicFormName", "Imperfective (volitional)");

    default:
        break;
    }

    return "";
}

}

#endif // MSG_H
