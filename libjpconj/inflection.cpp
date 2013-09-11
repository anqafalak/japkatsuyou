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

#include "inflection.h"

Inflection::Inflection()
{
}

QString Inflection::conjugate(QString verb, EdictType type, CForm form, Politeness polite, Polarity affirmative)
{
    if(verb.length()<2)
        return verb;

    QString radical = verb;
    QString end = verb.right(1);
    radical.chop(1);

    switch (form){
    case VConjugate::_TeForm:
        if (affirmative)
            return Verbstem::tForm(radical, type) + tEnd(end, true);
        else
            return Verbstem::aForm(radical, type) + QString::fromUtf8("なくて");
    case VConjugate::_Present:
        if (polite)

            if (affirmative)
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ます");
            else
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ません");
        else
            if (affirmative)
                return verb;
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("ない");
    case VConjugate::_Past:
        if (polite)

            if (affirmative)
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ました");
            else
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ませんでした");
        else
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, false);
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("なかった");

    case VConjugate::_Provision:
        if (polite)
            if (affirmative)
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ますれば");
            else
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ませんならば");
        else
            if (affirmative)
                return Verbstem::eForm(radical, type)+ QString::fromUtf8("ば");
            else //negative
                return Verbstem::aForm(radical, type) + QString::fromUtf8("なければ");

    case VConjugate::_Condition:
        if (polite)
            if (affirmative)
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ましたら");
            else
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ませんでしたら");
        else
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, false) + QString::fromUtf8("ら");
            else //negative
                return Verbstem::aForm(radical, type) + QString::fromUtf8("なかったら");

    case VConjugate::_Imperative:
        if (polite)
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("下さい");
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("ないで下さい");
        else
            if (affirmative)
                return Verbstem::eImpForm(radical, type);
            else //negative
                return verb + QString::fromUtf8("な");

    case VConjugate::_Volitional:
        if (polite)
            if (affirmative)
                return Verbstem::iForm(radical, type) + QString::fromUtf8("ましょう");
            else
                return verb + QString::fromUtf8("のをやめましょう");
        else
            if (affirmative)
                return Verbstem::oForm(radical, type) + QString::fromUtf8("う");
            else //negative
                return verb + QString::fromUtf8("のをやめよう");

    case VConjugate::_PresentContinuous:
        if (polite)
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("います");
            else
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いません");
        else
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いる");
            else
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いない");

    case VConjugate::_PastContinuous:
        if (polite)
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いました");
            else
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いませんでした");
        else
            if (affirmative)
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いた");
            else
                return Verbstem::tForm(radical, type) + tEnd(end, true) + QString::fromUtf8("いなかった");

    case VConjugate::_Potential:
        if (type == VerbType::_v1)
            radical += QString::fromUtf8("ら"); // radical + られ but since eForm = radical + れ we used it like this

        if (type >= VerbType::_vs){ //suru verbs numbers are 27 26 25 24
            if (type < VerbType::_vs_s) // suru verb number 27 ends with su,  no need to chop it
                radical.chop(1);
            radical += QString::fromUtf8("でき");
            type = VerbType::_v0; //to prevent changing the radical when using eForm
        }

        if (polite)
            if (affirmative)
                return Verbstem::eForm(radical, type) + QString::fromUtf8("ます");
            else
                return Verbstem::eForm(radical, type) + QString::fromUtf8("ません");
        else
            if (affirmative)
                return Verbstem::eForm(radical, type) + QString::fromUtf8("る");
            else //negative
                return Verbstem::eForm(radical, type) + QString::fromUtf8("ない");

    case VConjugate::_Passive:
        if (type == VerbType::_v1)
            verb += QString::fromUtf8("ら");

        if (type >= VerbType::_vs){ //suru verbs numbers are 27 26 25 24
            if (type < VerbType::_vs_s) // suru verb number 27 ends with su,  no need to chop it
                radical.chop(1);
            radical += QString::fromUtf8("さ");
            type = VerbType::_v0; //to prevent changing the radical when using eForm
        }

        if (polite)
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("れます");
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("れません");
        else
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("れる");
            else //negative
                return Verbstem::aForm(radical, type) + QString::fromUtf8("れない");

    case VConjugate::_Causative:
        if (type == VerbType::_v1)
            verb += QString::fromUtf8("さ");

        if (type >= VerbType::_vs){ //suru verbs numbers are 27 26 25 24
            if (type < VerbType::_vs_s) // suru verb number 27 ends with su,  no need to chop it
                radical.chop(1);
            radical += QString::fromUtf8("さ");
            type = VerbType::_v0; //to prevent changing the radical when using eForm
        }

        if (polite)
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せます");
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せません");
        else
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せる");
            else //negative
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せない");

    case VConjugate::_CausativePassive:
        if (type == VerbType::_v1)
            verb += QString::fromUtf8("さ");

        if (type >= VerbType::_vs){ //suru verbs numbers are 27 26 25 24
            if (type < VerbType::_vs_s) // suru verb number 27 ends with su,  no need to chop it
                radical.chop(1);
            radical += QString::fromUtf8("さ");
            type = VerbType::_v0; //to prevent changing the radical when using eForm
        }


        if (polite)
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せられます");
            else
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せられません");
        else
            if (affirmative)
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せられる");
            else //negative
                return Verbstem::aForm(radical, type) + QString::fromUtf8("せられない");

    }

    return verb;
}

//Not used, it's just for future reference, if it appears some _v5 verbs (unknown end)
int Inflection::getEnd(QString verb)
{
    int lastpos = verb.length() -1;

    if (lastpos >0)
    {
        QChar lastchar = verb.at(lastpos);
        return _endChars.indexOf(lastchar);
    }
    return -1;
}

/*!
 * \brief Inflection::tEnd Used to get te or ta forms
 *
 * There are verbs which take de (da) in the end, in te (ta) forms,
 * those verbs are ending with ぬ, む, ぶ, and ぐ
 * \param end give the end of the verb in dictionary form (u-form)
 * \param te when it is True (te-form), when False (ta-form)
 * \return te, ta, de, da
 */
QString Inflection::tEnd(QString end, bool te)
{

    if (QString::fromUtf8("ぬむぶぐ").contains(end))
    {
        if (te)
            return QString::fromUtf8("で");
        return QString::fromUtf8("だ");
    }

    if (te)
        return QString::fromUtf8("て");
    return QString::fromUtf8("た");
}
