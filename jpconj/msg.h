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
#include <QList>
#include <QString>

#ifdef __GNUC__
#define NO_USE_FUNC __attribute__ ((unused))
#else
#define NO_USE_FUNC
#endif

namespace Msg {

static QList<CForm> NO_USE_FUNC verbFormsList()
{
    QList<CForm> resultList;
    resultList << VConjugate::_Present;
    resultList << VConjugate::_Past;
    resultList << VConjugate::_Provision;
    resultList << VConjugate::_Condition;
    resultList << VConjugate::_Imperative;
    resultList << VConjugate::_Volitional;
    resultList << VConjugate::_PresentContinuous;
    resultList << VConjugate::_PastContinuous;
    resultList << VConjugate::_Passive;
    resultList << VConjugate::_Causative;
    resultList << VConjugate::_CausativePassive;
    resultList << VConjugate::_Potential;

    return resultList;
}


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
        return qApp->translate("verbFormDesc", "The provisional conditional form is used: \n - In conditionals where the emphasis rests more on the condition than the result. \n - Expressing obligations.");
    case VConjugate::_Condition:
        return qApp->translate("verbFormDesc", "It can be used in the same way as the provisional condition form.\n However, it implies more certainty about the condition.");
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
        return qApp->translate("verbFormDesc", "The causative is used for: \n - Making someone do something \n - Letting someone do something.");
    case VConjugate::_CausativePassive:
        return qApp->translate("verbFormDesc", "It is used to express causation passively.");
    case VConjugate::_Potential:
        return qApp->translate("verbFormDesc", "The potential is used to express that \n one has the ability to do something.");
    default:
        break;
    }

    return "";
}


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


}

#endif // MSG_H
