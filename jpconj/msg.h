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

typedef QPair<QString, QString> formDesc;
typedef QObject verbFormNames; //used just to butify i18n files: name of verb form
typedef QObject verbFormDesc; //used just to butify i18n files: description of verb form
static QMap<CForm, formDesc> setVerbForms() {
    QMap<CForm, formDesc> mapVerbForms;

    mapVerbForms.insert(VConjugate::_Present,
                        formDesc(verbFormNames::tr("Present"),
                                 verbFormDesc::tr("This is the present tense")));

    mapVerbForms.insert(VConjugate::_Past,
                        formDesc(verbFormNames::tr("Past"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Provision,
                        formDesc(verbFormNames::tr("Provisional Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Condition,
                        formDesc(verbFormNames::tr("Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Imperative,
                        formDesc(verbFormNames::tr("Imperative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Volitional,
                        formDesc(verbFormNames::tr("Volitional"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_PresentContinuous,
                        formDesc(verbFormNames::tr("Present Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_PastContinuous,
                        formDesc(verbFormNames::tr("Past Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Passive,
                        formDesc(verbFormNames::tr("Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Causative,
                        formDesc(verbFormNames::tr("Causative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_CausativePassive,
                        formDesc(verbFormNames::tr("Causative Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Potential,
                        formDesc(verbFormNames::tr("Potential"),
                                 verbFormDesc::tr("")));

    return mapVerbForms;
}
static const QMap<CForm, formDesc> verbForms = setVerbForms();


#endif // MSG_H
