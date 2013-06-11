/*
    This file is part of libjpconj project; a library that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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

Libjpconj::Libjpconj()
{

}

//extern function

QString conj(QString verb, int type, int time, bool polite, bool positive)
{
    Libjpconj jpconj;
    QString result = jpconj.conjugate(verb, type, time, polite, positive);
    return result;
}

QString conjEnd(QString verb, int type, int end, int time, bool polite, bool positive)
{
    Libjpconj jpconj;
    QString result = jpconj.conjugate(verb, type, end, time, polite, positive);
    return result;
}


QString Libjpconj::conjugate(QString verb, int type, int time, bool polite, bool positive)
{
    int end = getEnd(verb);
    return conjugate(verb, type, end, time, polite, positive);
}

QString Libjpconj::conjugate(QString verb, int type, int end, int time, bool polite, bool positive)
{
    if(verb.length()<2)
        return verb;

    QString radical = verb;
    radical.chop(1);

    if (type == _ssuruVerb)
    {
        radical.chop(1);
        end = _suEnd;
        type = _godan;
    }

    switch (time)
    {
    case _TeForm:
        if (positive)
            return Verbform::teForm(radical, type, end);
        else
            return Verbform::aForm(radical, type, end) + QString::fromUtf8("なくて");
    case _Present:
        if (polite)

            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ます");
            else
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ません");
        else
            if (positive)
                return verb;
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("ない");
    case _Past:
        if (polite)

            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ました");
            else
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ませんでした");
        else
            if (positive)
                return Verbform::taForm(radical, type, end);
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("なかった");

    case _Provision:   
        if (polite)

            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ませば");
            else
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ませんならば");
        else
            if (positive)
            {
                if (type == _godan || type == _zuruVerb)
                    return Verbform::eForm(radical, type, end)+ QString::fromUtf8("ば");

                return Verbform::eForm(radical, type, end)+ QString::fromUtf8("れば");
            }
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("なければ");

    case _Condition:
        if (polite)
            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ましたら");
            else
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ませんでしたら");
        else
            if (positive)
                return Verbform::taForm(radical, type, end) + QString::fromUtf8("ら");
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("なかったら");

    case _Reason:
        if (polite)
            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ますから");
            else
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ませんから");
        else
            if (positive)
                return Verbform::taForm(radical, type, end) + QString::fromUtf8("から");
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("なかったから");

    case _Imperative:
        if (polite)
            if (positive)
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("下さい");
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("ないで下さい");
        else
            if (positive)
            {

                switch (type)
                {
                case _ichidan:
                    return verb + QString::fromUtf8("ろ");
                case _suruVerb:
                    verb.chop(1);
                    return verb + QString::fromUtf8("しろ");
                case _godan:
                    return Verbform::eForm(radical, type, end);
                }
                return Verbform::eForm(radical, type, end);
            }
            else //negative
                return verb + QString::fromUtf8("な");

    case _Volitional:
        if (polite)
            if (positive)
                return Verbform::iForm(radical, type, end) + QString::fromUtf8("ましょう");
            else
                return verb + QString::fromUtf8("のをやめましょう");
        else
            if (positive)
                return Verbform::oForm(radical, type, end) + QString::fromUtf8("う");
            else //negative
                return verb + QString::fromUtf8("のをやめよう");

    case _PresentContinuous:
        if (polite)
            if (positive)
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("います");
            else
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いません");
        else
            if (positive)
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いる");
            else
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いない");

    case _PastContinuous:
        if (polite)
            if (positive)
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いました");
            else
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いませんでした");
        else
            if (positive)
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いた");
            else
                return Verbform::teForm(radical, type, end) + QString::fromUtf8("いなかった");

    case _Potential:
        if (type == _ichidan)
            verb += QString::fromUtf8("られ");
        if (type == _suruVerb)
        {
            verb.chop(1);
            verb += QString::fromUtf8("でき");
            type = _ichidan;
        }

        if (polite)
            if (positive)
                return Verbform::eForm(radical, type, end) + QString::fromUtf8("ます");
            else
                return Verbform::eForm(radical, type, end) + QString::fromUtf8("ません");
        else
            if (positive)
                return Verbform::eForm(radical, type, end) + QString::fromUtf8("る");
            else //negative
                return Verbform::eForm(radical, type, end) + QString::fromUtf8("ない");

    case _Passive:
        if (type == _ichidan)
            verb += QString::fromUtf8("ら");
        if (type == _suruVerb)
        {
            verb.chop(1);
            verb += QString::fromUtf8("さ");
            type = _ichidan;
        }

        if (polite)
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("れます");
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("れません");
        else
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("れる");
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("れない");

    case _Causative:
        if (type == _ichidan)
            verb += QString::fromUtf8("さ");
        if (type == _suruVerb)
        {
            verb.chop(1);
            verb += QString::fromUtf8("さ");
            type = _ichidan;
        }

        if (polite)
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せます");
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せません");
        else
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せる");
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せない");

    case _CausativePassive:
        if (type == _ichidan)
            verb += QString::fromUtf8("さ");
        if (type == _suruVerb)
        {
            verb.chop(1);
            verb += QString::fromUtf8("さ");
            type = _ichidan;
        }

        if (polite)
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せられます");
            else
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せられません");
        else
            if (positive)
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せられる");
            else //negative
                return Verbform::aForm(radical, type, end) + QString::fromUtf8("せられない");

    }

    return Verbform::uForm(radical, end);
}

/*

 */

int Libjpconj::getEnd(QString verb)
{
    int lastpos = verb.length() -1;

    if (lastpos >0)
    {
        QChar lastchar = verb.at(lastpos);
        return _endChars.indexOf(lastchar);
    }
    return -1;
}
