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

#define _endChars QString::fromUtf8("うくぐすつぬぶむるふ")

// verb types
typedef int VerbType;
namespace verbType {
const int _v1       = 1; //Ichidan verb
const int _v2a_s    = 2; //Nidan verb with 'u' ending (archaic)
const int _v4h      = 3; //Yondan verb with 'hu/fu' ending (archaic)
const int _v4r      = 4; //Yondan verb with 'ru' ending (archaic)
const int _v5       = 5; //Godan verb (not completely classified)
const int _v5aru	= 6; //Godan verb - -aru special class
const int _v5b      = 7; //Godan verb with 'bu' ending
const int _v5g      = 8; //Godan verb with 'gu' ending
const int _v5k      = 9; //Godan verb with 'ku' ending
const int _v5k_s    = 10; //Godan verb - iku/yuku special class
const int _v5m      = 11; //Godan verb with 'mu' ending
const int _v5n      = 12; //Godan verb with 'nu' ending
const int _v5r      = 13; //Godan verb with 'ru' ending
const int _v5r_i    = 14; //Godan verb with 'ru' ending (irregular verb)
const int _v5s      = 15; //Godan verb with 'su' ending
const int _v5t      = 16; //Godan verb with 'tsu' ending
const int _v5u      = 17; //Godan verb with 'u' ending
const int _v5u_s	= 18; //Godan verb with 'u' ending (special class)
const int _v5uru	= 19; //Godan verb - uru old class verb (old form of Eru)
const int _v5z      = 20; //Godan verb with 'zu' ending
const int _vz       = 21; //Ichidan verb - zuru verb - (alternative form of -jiru verbs)
const int _vk       = 22; //kuru verb - special class
const int _vn       = 23; //irregular nu verb
const int _vs       = 24; //noun or participle which takes the aux. verb suru
const int _vs_c     = 25; //su verb - precursor to the modern suru
const int _vs_i     = 26; //suru verb - irregular
const int _vs_s     = 27; //suru verb - special class
}

typedef bool Polarity;
namespace polarity {
const bool _affirmative  = true; //affirmative sentence
const bool _negative     = false; //negative sentence
}

typedef bool Politeness;
namespace politeness {
const bool _plain       = false; //plain sentence
const bool _polite      = true; //polite sentence
}

//Conjugation time (form)
typedef int VerbForm;
namespace verbForm {
const int  _TeForm             = 0; // no polite form
const int  _Present            = 1; // る、　ます
const int  _Past               = 2; // た、ました
const int  _Provision          = 3; // ば
const int  _Condition          = 4; // ta＋ら
const int  _Imperative         = 5; // え、ろ
const int  _Volitional         = 6; // おう、ましょう
const int  _PresentContinuous  = 7; // te + いる
const int  _PastContinuous     = 8; // te + いた
const int  _Passive            = 9; // a＋れる a＋られる
const int  _Causative          = 10; // a＋せる a＋させる
const int  _CausativePassive   = 11; // a＋せられる a＋させられる
const int  _Potential          = 12; // e＋る e＋られる
//const int  _Desire             = 14; // i + たい
//const int  _WhileDoing         = 15; // ながら
//const int  _WayOfDoing         = 16; // かた・方
}

#endif // TYPEDEFS_H
