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

QString Libjpconj::conjugate(QString verb, int type, int time, bool polite, bool positive)
{

    int end = getEnd(verb);
    verb.chop(1);

    switch (time)
    {
    case _TeForm:
        if (positive)
            return Verbform::teForm(verb, type, end);
        else
            return Verbform::aForm(verb, type, end) + QString::fromUtf8("なくて");
    case _Present:
        if (polite)

            if (positive)
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ます");
            else
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ません");
        else
            if (positive)
                return Verbform::uForm(verb, end);
            else
                return Verbform::aForm(verb, type, end) + QString::fromUtf8("ない");
    case _Past:
        if (polite)

            if (positive)
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ました");
            else
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ませんでした");
        else
            if (positive)
                return Verbform::taForm(verb, type, end);
            else
                return Verbform::aForm(verb, type, end) + QString::fromUtf8("なかった");

    case _Provision:   
        if (polite)

            if (positive)
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ませば");
            else
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ませんならば");
        else
            if (positive)
            {
                if (type == _godan || type == _zuruVerb)
                    return Verbform::eForm(verb, type, end)+ QString::fromUtf8("ば");
                return Verbform::eForm(verb, type, end)+ QString::fromUtf8("れば");
            }
            else //negative
                return Verbform::aForm(verb, type, end) + QString::fromUtf8("なければ");

    case _Condition:
        if (polite)
            if (positive)
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ましたら");
            else
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ませんでしたら");
        else
            if (positive)
                return Verbform::taForm(verb, type, end) + QString::fromUtf8("ら");
            else //negative
                return Verbform::aForm(verb, type, end) + QString::fromUtf8("なかったら");

    case _Raison:
        if (polite)
            if (positive)
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ますから");
            else
                return Verbform::iForm(verb, type, end) + QString::fromUtf8("ませんから");
        else
            if (positive)
                return Verbform::taForm(verb, type, end) + QString::fromUtf8("から");
            else //negative
                return Verbform::aForm(verb, type, end) + QString::fromUtf8("なかったから");
    }

    return Verbform::uForm(verb, end);
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
