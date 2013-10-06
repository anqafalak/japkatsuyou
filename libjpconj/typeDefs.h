/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
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

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

// Characters which can be the ending of a verb in  dictionary form
#define _endChars QString::fromUtf8("うくぐすつぬぶむるふ")

/*!
 * \brief The EdictType enum contains the verb types as specified in Edict2 dictionary
 *
 * It contains all types defined by Mr. Jim Breen in his dictionary Edict2.
 * It is used in our SqLite database (Edict2verbs.db)
 */
enum EdictType {
    /*! This means no type at all, it is used to return the radical as it is.*/
    _v0         = 0,

    /*! Ichidan verb */
    _v1         = 1,

    /*! Nidan verb with 'u' ending (archaic) */
    _v2a_s      = 2,

    /*! Yondan verb with 'hu/fu' ending (archaic) */
    _v4h        = 3,

    /*! Yondan verb with 'ru' ending (archaic) */
    _v4r        = 4,

    /*! Godan verb (not completely classified) */
    _v5         = 5,

    /*! Godan verb - -aru special class */
    _v5aru      = 6,

    /*! Godan verb with 'bu' ending */
    _v5b        = 7,

    /*! Godan verb with 'gu' ending */
    _v5g        = 8,

    /*! Godan verb with 'ku' ending */
    _v5k        = 9,

    /*! Godan verb - iku/yuku special class */
    _v5k_s      = 10,

    /*! Godan verb with 'mu' ending */
    _v5m        = 11,

    /*! Godan verb with 'nu' ending */
    _v5n        = 12,

    /*! Godan verb with 'ru' ending */
    _v5r        = 13,

    /*! Godan verb with 'ru' ending (irregular verb) */
    _v5r_i      = 14,

    /*! Godan verb with 'su' ending */
    _v5s        = 15,

    /*! Godan verb with 'tsu' ending */
    _v5t        = 16,

    /*! Godan verb with 'u' ending */
    _v5u        = 17,

    /*! Godan verb with 'u' ending (special class) */
    _v5u_s      = 18,

    /*! Godan verb - uru old class verb (old form of Eru) */
    _v5uru      = 19,

    /*! Godan verb with 'zu' ending */
    _v5z        = 20,

    /*! Ichidan verb - zuru verb - (alternative form of -jiru verbs) */
    _vz         = 21,

    /*! kuru verb - special class */
    _vk         = 22,

    /*! irregular nu verb */
    _vn         = 23,

    /*! noun or participle which takes the aux. verb suru */
    _vs         = 24,

    /*! su verb - precursor to the modern suru */
    _vs_c       = 25,

    /*! suru verb - irregular */
    _vs_i       = 26,

    /*! suru verb - special class */
    _vs_s       = 27
};


/*!
 * \brief The CForm enum (Conjugation Form) contains the verb's complex forms.
 *
 * Conjugation Form: contains the verb's complex forms.
 * These forms are created from basic forms (a, e, t, u, i, o)-stems by adding suffixes.
 */
enum CForm {
    /*! This is the te-form of the verb, it has no polite form */
    _TeForm                 = 1,

    /*! Present tense of the verb; plain (u-form + る), polite (i-form + ます)*/
    _Present                = 2,

    /*! Past tense of the verb; plain (t-form + た), polite (i-form + ました) */
    _Past                   = 3,

    /*! Provision form (condition); plain (e-form + ば), polite (i-form + ますれば) */
    _Provision              = 4,

    /*! Condiction form (past condition); plain (t-form + たら), polite (i-form + ましたら)*/
    _Condition              = 5,

    /*! Imperative form; plain (eImp-form), polite (t-form + て下さい) */
    _Imperative             = 6,

    /*! Volitional form (lets ...); plain (o-form + う), polite (i-form + ましょう) */
    _Volitional             = 7,

    /*! Present continuous form; plain (t-form + ている), polite (t-form + ています) */
    _PresentContinuous      = 8,

    /*! Past continuous form; plain (t-form + ていた), polite (t-form + ていました)*/
    _PastContinuous         = 9,

    /*! Passive form; plain (a-form + れる), polite (a-form + れます) */
    _Passive                = 10,

    /*! Causative form */
    _Causative              = 11,// a＋せる a＋させる
    _CausativePassive       = 12,// a＋せられる a＋させられる
    _Potential              = 13// e＋る e＋られる
    //_Desire             = 14; // i + たい
    //_WhileDoing         = 15; // ながら
    //_WayOfDoing         = 16; // かた・方
    };

/*!
 * \brief The Polarity enum Gives the polartity of sentence: affirmative or negative
 */
enum Polarity {
    /*! This is the affirnative conjugation of the verb. eg. 行きます: go (polite present)*/
    _Affirmative        = true,

    /*! This is the negative conjugation of the verb. eg. don't go (polite present)*/
    _Negative           = false
};

/*!
 * \brief The Politeness enum Specifies if the verb is in plain form (used between friends),
 * or polite form (official talking)
 */
enum Politeness {
    /*! Plain form of a verb. eg. 行く: go (plain present)*/
    _Plain              = false,

    /*! Polite form of a verb. eg. 行きます: go (polite present)*/
    _Polite             = true
};




/*!
 * \brief The KForm enum (Conjugation Form) contains the verb's basic forms.
 *
 * Katsuyou Form: contains the verb's basic forms.
 * These forms are thought in Japanese schools, and are origin of complex forms by adding suffixes.
 */
enum KForm {
    /*! Imperfective (general), in Japanese: 未然形*/
    _Imperfective_a     = 1,

    /*! Imperfective (volutional), in Japanese also: 未然形*/
    _Imperfective_o     = 2,

    /*! Conjunctive (-i), in Japanese: 連用形*/
    _Conjunctive_i      = 3,

    /*! Conjunctive (other), in Japanese also: 連用形*/
    _Conjunctive_t      = 4,

    /*! Attributive, in Japanese: 終止形*/
    _Terminal_u         = 5,

    /*! Attributive, in Japanese: 連体形*/
    _Attributive_u      = 6,

    /*! Hypothetical, in Japanese: 仮定形*/
    _Hypothetical_e     = 7,

    /*! Imperative, in Japanese: 命令形*/
    _Imperative_e       = 8
};

#endif // TYPEDEFS_H
