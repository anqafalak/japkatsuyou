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
#include "QString"
#include <QMap>
#include <QPair>
#include <QVector>

typedef QPair<QString, QString> pairs; //to join two strings, the second is the description of the first

typedef QObject verbFormNames; //used just to beautify i18n files: name of verb form
typedef QObject verbFormDesc; //used just to beautify i18n files: description of verb form
static QMap<CForm, pairs> setVerbFormsMsg() {
    QMap<CForm, pairs> mapVerbForms;

    mapVerbForms.insert(VConjugate::_Present,
                        pairs(verbFormNames::tr("Present"),
                                 verbFormDesc::tr("This is the present tense")));

    mapVerbForms.insert(VConjugate::_Past,
                        pairs(verbFormNames::tr("Past"),
                                 verbFormDesc::tr("This is the past tense")));

    mapVerbForms.insert(VConjugate::_Provision,
                        pairs(verbFormNames::tr("Provisional Condition"),
                                 verbFormDesc::tr("The provisional conditional form is used: \n - In conditionals where the emphasis rests more on the condition than the result. \n - Expressing obligations.")));

    mapVerbForms.insert(VConjugate::_Condition,
                        pairs(verbFormNames::tr("Conditional"),
                                 verbFormDesc::tr("It can be used in the same way as the provisional condition form.\n However, it implies more certainty about the condition.")));

    mapVerbForms.insert(VConjugate::_Imperative,
                        pairs(verbFormNames::tr("Imperative"),
                                 verbFormDesc::tr("The imperative form is used to order someone")));

    mapVerbForms.insert(VConjugate::_Volitional,
                        pairs(verbFormNames::tr("Volitional"),
                                 verbFormDesc::tr("In general, the volitional form expresses intention, eg. Let's... or Shall we...")));

    mapVerbForms.insert(VConjugate::_PresentContinuous,
                        pairs(verbFormNames::tr("Present Continuous"),
                                 verbFormDesc::tr("This is the present continuous tense.")));

    mapVerbForms.insert(VConjugate::_PastContinuous,
                        pairs(verbFormNames::tr("Past Continuous"),
                                 verbFormDesc::tr("This is the past continuous tense.")));

    mapVerbForms.insert(VConjugate::_Passive,
                        pairs(verbFormNames::tr("Passive"),
                                 verbFormDesc::tr("This is the passive voice of the verb.")));

    mapVerbForms.insert(VConjugate::_Causative,
                        pairs(verbFormNames::tr("Causative"),
                                 verbFormDesc::tr("The causative is used for: \n - Making someone do something \n - Letting someone do something.")));

    mapVerbForms.insert(VConjugate::_CausativePassive,
                        pairs(verbFormNames::tr("Causative Passive"),
                                 verbFormDesc::tr("It is used to express causation passively.")));

    mapVerbForms.insert(VConjugate::_Potential,
                        pairs(verbFormNames::tr("Potential"),
                                 verbFormDesc::tr("The potential is used to express that \n one has the ability to do something.")));

    return mapVerbForms;
}
static const QMap<CForm, pairs> verbFormsMsg = setVerbFormsMsg();

typedef QObject verbTypeDesc; //used just to beautify i18n files: description of verb form
static QVector<QString> setVerbTypesMsg() {
    QVector<QString> vectorVerbTypes;

    vectorVerbTypes.append(verbTypeDesc::tr("This verb doesn't exist in the database.")); //_v0
    vectorVerbTypes.append(verbTypeDesc::tr("Ichidan verb.")); //_v1
    vectorVerbTypes.append(verbTypeDesc::tr("Nidan verb with 'u' ending (archaic).")); //_v2a_s
    vectorVerbTypes.append(verbTypeDesc::tr("Yondan verb with 'hu/fu' ending (archaic)")); //_v4h
    vectorVerbTypes.append(verbTypeDesc::tr("Yondan verb with 'ru' ending (archaic).")); //_v4r
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb (not completely classified).")); //_v5
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb -aru special class.")); //_v5aru
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'bu' ending.")); //_v5b
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'gu' ending.")); //_v5g
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'ku' ending.")); //_v5k
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb - iku/yuku special class.")); //_v5k_s
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'mu' ending.")); //_v5m
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'nu' ending.")); //_v5n
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'ru' ending.")); //_v5r
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'ru' ending (irregular verb).")); //_v5r_i
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'su' ending.")); //_v5s
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'tsu' ending.")); //_v5t
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'u' ending.")); //_v5u
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'u' ending (special class).")); //_v5u_s
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb - uru old class verb (old form of Eru).")); //_v5uru
    vectorVerbTypes.append(verbTypeDesc::tr("Godan verb with 'zu' ending.")); //_v5z
    vectorVerbTypes.append(verbTypeDesc::tr("Ichidan verb - zuru verb - (alternative form of -jiru verbs).")); //_vz
    vectorVerbTypes.append(verbTypeDesc::tr("kuru verb - special class.")); //_vk
    vectorVerbTypes.append(verbTypeDesc::tr("irregular nu verb.")); //_vn
    vectorVerbTypes.append(verbTypeDesc::tr("noun or participle which takes the aux. verb suru.")); //_vs
    vectorVerbTypes.append(verbTypeDesc::tr("su verb - precursor to the modern suru.")); //_vs_c
    vectorVerbTypes.append(verbTypeDesc::tr("suru verb - irregular.")); //_vs_i
    vectorVerbTypes.append(verbTypeDesc::tr("suru verb - special class.")); //_vs_s

    return vectorVerbTypes;
}
static const QVector<QString> verbTypesMsg = setVerbTypesMsg();

typedef QObject verbPolitenessDesc; //used just to beautify i18n files: description of verb form
static QVector<pairs> setVerbPolitenessMsg() {
    QVector<pairs> mapVerbPoliteness;

    mapVerbPoliteness.append(pairs(verbPolitenessDesc::tr("Plain"),
                              verbPolitenessDesc::tr("Plain form of a sentence; it is used with friends")));

    mapVerbPoliteness.append(pairs(verbPolitenessDesc::tr("Polite"),
                              verbPolitenessDesc::tr("Polite form of a sentence; it is used in official discussion.")));

    return mapVerbPoliteness;
}
static const QVector<pairs> verbPolitenessMsg = setVerbPolitenessMsg();

typedef QObject verbPolarityDesc; //used just to beautify i18n files: description of verb form
static QVector<pairs> setVerbPolarityMsg() {
    QVector<pairs> mapVerbPolarity;

    mapVerbPolarity.append(pairs(verbPolarityDesc::tr("Negative"),
                            verbPolarityDesc::tr("Form used in negative sentences.")));

    mapVerbPolarity.append(pairs(verbPolarityDesc::tr("Affirmative"),
                            verbPolarityDesc::tr("Form used in affirmative sentences.")));

    return mapVerbPolarity;
}
static const QVector<pairs> verbPolarityMsg = setVerbPolarityMsg();

#endif // MSG_H
