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
namespace VerbType {
enum EdictType {
    _v0         = 0, //This means no type at all
    _v1         = 1, //Ichidan verb
    _v2a_s      = 2, //Nidan verb with 'u' ending (archaic)
    _v4h        = 3, //Yondan verb with 'hu/fu' ending (archaic)
    _v4r        = 4, //Yondan verb with 'ru' ending (archaic)
    _v5         = 5, //Godan verb (not completely classified)
    _v5aru      = 6, //Godan verb - -aru special class
    _v5b        = 7, //Godan verb with 'bu' ending
    _v5g        = 8, //Godan verb with 'gu' ending
    _v5k        = 9, //Godan verb with 'ku' ending
    _v5k_s      = 10, //Godan verb - iku/yuku special class
    _v5m        = 11, //Godan verb with 'mu' ending
    _v5n        = 12, //Godan verb with 'nu' ending
    _v5r        = 13, //Godan verb with 'ru' ending
    _v5r_i      = 14, //Godan verb with 'ru' ending (irregular verb)
    _v5s        = 15, //Godan verb with 'su' ending
    _v5t        = 16, //Godan verb with 'tsu' ending
    _v5u        = 17, //Godan verb with 'u' ending
    _v5u_s      = 18, //Godan verb with 'u' ending (special class)
    _v5uru      = 19, //Godan verb - uru old class verb (old form of Eru)
    _v5z        = 20, //Godan verb with 'zu' ending
    _vz         = 21, //Ichidan verb - zuru verb - (alternative form of -jiru verbs)
    _vk         = 22, //kuru verb - special class
    _vn         = 23, //irregular nu verb
    _vs         = 24, //noun or participle which takes the aux. verb suru
    _vs_c       = 25, //su verb - precursor to the modern suru
    _vs_i       = 26, //suru verb - irregular
    _vs_s       = 27 //suru verb - special class
};
}

//Conjugation time (form)
namespace VConjugate{
using namespace VerbType;
enum CForm {
    _TeForm                 = 1,// no polite form
    _Present                = 2,// る、　ます
    _Past                   = 3,// た、ました
    _Provision              = 4,// ば
    _Condition              = 5,// ta＋ら
    _Imperative             = 6,// え、ろ
    _Volitional             = 7,// おう、ましょう
    _PresentContinuous      = 8,// te + いる
    _PastContinuous         = 9,// te + いた
    _Passive                = 10,// a＋れる a＋られる
    _Causative              = 11,// a＋せる a＋させる
    _CausativePassive       = 12,// a＋せられる a＋させられる
    _Potential              = 13// e＋る e＋られる
    //_Desire             = 14; // i + たい
    //_WhileDoing         = 15; // ながら
    //_WayOfDoing         = 16; // かた・方
    };

enum Polarity {
    _Affirmative        = true,//affirmative sentence
    _Negative           = false//negative sentence
};

enum Politeness {
    _Plain              = false, //plain sentence
    _Polite             = true //polite sentence
};

}

namespace VKatsuyou{
using namespace VerbType;
enum KForm {
    _Imperfective_a     = 1,
    _Imperfective_o     = 2,
    _Conjunctive_i      = 3,
    _Conjunctive_t      = 4,
    _Attributive_u      = 5,
    _Hypothetical_e     = 6,
    _Imperative_e       = 7
};
}

using namespace VConjugate;
using namespace VKatsuyou;

#endif // TYPEDEFS_H
