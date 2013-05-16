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

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// verb type
#define _ichidan 1
#define _godan 5
#define _zuruVerb 10


//dictionary Verb ending
#define _endChars QString::fromUtf8("うくぐすつぬぶむる")
#define _uEnd 0
#define _kuEnd 1
#define _guEnd 2
#define _suEnd 3
#define _tuEnd 4
#define _nuEnd 5
#define _buEnd 6
#define _muEnd 7
#define _ruEnd 8

//Conjugation time (form)
#define _TeForm             0 // no polite form
#define _Present            1 // る、　ます
#define _Past               2 // た、ました
#define _Provision          3 // ば
#define _Condition          4 // ta＋ら
#define _Imperative         5 // え、ろ
#define _Lets               6 // おう、ましょう
#define _PresentContinuous  7 // te + いる
#define _PastContinuous     8 // te + いる
#define _Desire             9 // i + たい
#define _WhileDoing         10 // ながら
#define _WayOfDoing         11 // かた・方
#define _Passive            12 // a＋れる a＋られる
#define _Causative          13 // a＋せる a＋させる
#define _CausativePassive   14 // a＋せられる a＋させられる
#define _Potential          15 // e＋る e＋られる
#define _Raison             16 // ta＋から




#endif // TYPEDEFS_H
