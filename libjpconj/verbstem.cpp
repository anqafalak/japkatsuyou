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

#include "verbstem.h"

/*!
 * \class Verbstem
 * It is used to get the verb's six forms which are a, e, u, i, o, and t -forms.
 */

//TODO: check suru types


/*! \~english
 * @brief  Verbstem::aForm  Gives the a-form (stem) of a verb
 *
 *  The function take a \e radical \e of a verb and gives its a-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b a \b \n
 * eg. 飲む -> 飲ま
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the a-form of the verb
 */
QString Verbstem::aForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical;

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical; //TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical; //TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical; //TODO: check

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("ら");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("ば");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("が");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("か");

    case _v5k_s://Godan verb - iku/yuku special class
        return radical + QString::fromUtf8("か");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("ま");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("な");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("ら");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + "|";

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("さ");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("た");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("わ");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("わ");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical; //TODO: check

    case _v5z://Godan verb with 'zu' ending
        return radical; //TODO: check

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(2);
        return radical + QString::fromUtf8("|じ");

    case _vk://kuru verb - special class
        if (radical.endsWith(QString::fromUtf8("く|"))){
            radical.chop(2);
            radical += QString::fromUtf8("こ|");
        }
        return radical;

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("な");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_c://su verb - precursor to the modern suru
        //radical.chop(1);
        return radical + QString::fromUtf8("せ");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|し");
    }

    return radical;
}



/*! \~english
 * @brief  Verbstem::eForm  Gives the e-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \e radical \e of a verb and gives its e-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b e \b \n
 * eg. 飲む -> 飲め
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the e-form of the verb
 */
QString Verbstem::eForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical + QString::fromUtf8("れ");

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical; //TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical; //TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical; //TODO: check

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("れ");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("べ");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("げ");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("け");

    case _v5k_s://Godan verb - iku/yuku special class
        return radical + QString::fromUtf8("け");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("め");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("ね");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("れ");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + QString::fromUtf8("|あれ");

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("せ");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("て");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("え");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("え");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical; //TODO: check

    case _v5z://Godan verb with 'zu' ending
        return radical; //TODO: check

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(2);
        return radical + QString::fromUtf8("|(じ/ず)れ");

    case _vk://kuru verb - special class
        return radical + QString::fromUtf8("れ");

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("ね");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|すれ");

    case _vs_c://su verb - precursor to the modern suru
        //radical.chop(1);
        return radical + QString::fromUtf8("すれ");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|すれ");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|(すれ/せ)");

    default:
        break;
    }

    return radical;
}



/*! \~english
 * @brief  Verbstem::eImpForm  Gives the e-imperative form (stem) of a verb
 *
 * It is the same as Verbstem::eImpForm, but in case of suru and kuru, ichidan, and zuru it's different
 * eg. する -> しろ
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the e-imperative form of the verb
 */
QString Verbstem::eImpForm(QString radical, EdictType type)
{
    switch (type){

    case _v0: //just the radical
        return radical;

    case _v1: 	//Ichidan verb
        return radical + QString::fromUtf8("|(ろ/よ)");

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical; //TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical; //TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("|い");

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(1);
        return radical + QString::fromUtf8("|(じろ/じよ/ぜよ)");

    case _vk://kuru verb - special class
        if (radical.endsWith(QString::fromUtf8("く"))){
            radical.chop(1);
            radical += QString::fromUtf8("こ");
        }
        return radical + QString::fromUtf8("|い");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(1);
        return radical + QString::fromUtf8("|(しろ/せよ)");

    case _vs_c://su verb - precursor to the modern suru
        return radical + QString::fromUtf8("|せよ");

    case _vs_i://suru verb - irregular
        radical.chop(1);
        return radical + QString::fromUtf8("|(しろ/せよ)");

    case _vs_s: //suru verb - special class
        radical.chop(1);
        return radical + QString::fromUtf8("|(しろ/せよ)");

    default:
        break;
    }

    //if not included in special cases, the form is same as eForm
    return eForm(radical, type);
}



/*! \~english
 * @brief  Verbstem::tForm  Gives the t-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \e radical \e of a verb and gives its t-form by changing the last character's sound
 * - u  to t 買う -> 買っ
 * - ku to i　歩く -> 歩い
 * - gu to i　泳ぐ -> 泳い
 * - su to shi 出す -> 出し
 * - tsu to t 立つ -> 立っ
 * - nu to n 死ぬ -> 死ん
 * - bu to n 遊ぶ -> 遊ん
 * - mu to n 飲む -> 飲ん
 * - ru to t eg. 取る -> 取っ
 *
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the t-form of the verb
 */
QString Verbstem::tForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical;

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical; //TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical; //TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical; //TODO: check

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class くださる　なさる　etc.
        return radical + QString::fromUtf8("っ");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("ん");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("い");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("い");

    case _v5k_s://Godan verb - iku/yuku special class
        if (radical.endsWith(QString::fromUtf8("ゆ"))){
            radical.chop(1);
            radical += QString::fromUtf8("い");
        }
        return radical + QString::fromUtf8("っ");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("ん");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("ん");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("っ");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + QString::fromUtf8("|あっ");

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("し");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("っ");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("っ");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("う");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical; //TODO: check

    case _v5z://Godan verb with 'zu' ending
        return radical; //TODO: check

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(2);
        return radical + QString::fromUtf8("|じ");

    case _vk://kuru verb - special class
        if (radical.endsWith(QString::fromUtf8("く|"))){
            radical.chop(2);
            radical += QString::fromUtf8("き|");
        }
        return radical;

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("ん");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_c://su verb - precursor to the modern suru
        return radical + QString::fromUtf8("し");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    default:
        break;
    }

    return radical;

}



/*! \~english
 * @brief  Verbstem::uForm  Gives the u-form (stem) of a verb
 *
 * Gives the dictionary form of a verb
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString dictionary form of the verb
 */
QString Verbstem::uForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical + QString::fromUtf8("る");

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical + QString::fromUtf8("う");

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical + QString::fromUtf8("ふ");

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical + QString::fromUtf8("る");

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("る");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("ぶ");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("ぐ");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("く");

    case _v5k_s://Godan verb - iku/yuku special class
        return radical + QString::fromUtf8("く");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("む");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("ぬ");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("る");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + QString::fromUtf8("|ある");

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("す");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("つ");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("う");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("う");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical + QString::fromUtf8("る");

    case _v5z://Godan verb with 'zu' ending
        return radical + QString::fromUtf8("ず");

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        return radical + QString::fromUtf8("る");

    case _vk://kuru verb - special class
        return radical + QString::fromUtf8("る");

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("ぬ");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|する");

    case _vs_c://su verb - precursor to the modern suru
        return radical + QString::fromUtf8("する");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|する");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|する");

    default:
        break;
    }

    return radical;
}



/*! \~english
 * @brief  Verbstem::iForm  Gives the i-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \e radical \e of a verb and gives its i-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b i \b \n
 * eg. 飲む -> 飲み
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the i-form of the verb
 */
QString Verbstem::iForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical;

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical;//TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical;//TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical;//TODO: check

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("い");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("び");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("ぎ");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("き");

    case _v5k_s://Godan verb - iku/yuku special class
        return radical + QString::fromUtf8("き");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("み");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("に");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("り");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + QString::fromUtf8("|あり");

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("し");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("ち");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("い");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("い");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical + QString::fromUtf8("る");

    case _v5z://Godan verb with 'zu' ending
        return radical + QString::fromUtf8("ず");

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(2);
        return radical + QString::fromUtf8("|じ");

    case _vk://kuru verb - special class
        if (radical.endsWith(QString::fromUtf8("く|"))){
            radical.chop(2);
            return radical + QString::fromUtf8("き|");
        }
        return radical;

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("に");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_c://su verb - precursor to the modern suru
        return radical + QString::fromUtf8("し");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    default:
        break;
    }

    return radical;

}


/*! \~english
 * @brief  Verbstem::oForm  Gives the o-form (stem) of a verb
 *
 *  The function take a \e radical \e of a verb and gives its o-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b o \b \n
 * eg. 飲む -> 飲も
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: v1, v5u, etc. (See EdictType)
 * @return QString the o-form of the verb
 */
QString Verbstem::oForm(QString radical, EdictType type)
{
    radical += QString::fromUtf8("|");

    switch (type){

    case _v0: //just the radical
        radical.chop(1);
        return radical;

    case _v1: 	//Ichidan verb
        return radical;

    case _v2a_s: 	//Nidan verb with 'u' ending (archaic)
        return radical;//TODO: check

    case _v4h: 	//Yondan verb with 'hu/fu' ending (archaic)
        return radical;//TODO: check

    case _v4r: //Yondan verb with 'ru' ending (archaic)
        return radical;//TODO: check

    case _v5://Godan verb (not completely classified)
        return radical; //TODO: check

    case _v5aru: //Godan verb - -aru special class
        return radical + QString::fromUtf8("ろ");

    case _v5b://Godan verb with 'bu' ending
        return radical + QString::fromUtf8("ぼ");

    case _v5g://Godan verb with 'gu' ending
        return radical + QString::fromUtf8("ご");

    case _v5k://Godan verb with 'ku' ending
        return radical + QString::fromUtf8("こ");

    case _v5k_s://Godan verb - iku/yuku special class
        return radical + QString::fromUtf8("こ");

    case _v5m://Godan verb with 'mu' ending
        return radical + QString::fromUtf8("も");

    case _v5n://Godan verb with 'nu' ending
        return radical + QString::fromUtf8("の");

    case _v5r://Godan verb with 'ru' ending
        return radical + QString::fromUtf8("ろ");

    case _v5r_i://Godan verb with 'ru' ending (irregular verb) ある
        radical.chop(2);
        return radical + QString::fromUtf8("|あり");

    case _v5s://Godan verb with 'su' ending
        return radical + QString::fromUtf8("そ");

    case _v5t://Godan verb with 'tsu' ending
        return radical + QString::fromUtf8("と");

    case _v5u://Godan verb with 'u' ending
        return radical + QString::fromUtf8("お");

    case _v5u_s: //Godan verb with 'u' ending (special class) こう　とう
        return radical + QString::fromUtf8("お");

    case _v5uru://Godan verb - uru old class verb (old form of Eru)
        return radical + QString::fromUtf8("ろ");

    case _v5z://Godan verb with 'zu' ending
        return radical + QString::fromUtf8("ず");

    case _vz://Ichidan verb - zuru verb - (alternative form of -jiru verbs)
        radical.chop(2);
        return radical + QString::fromUtf8("|じ");

    case _vk://kuru verb - special class
        if (radical.endsWith(QString::fromUtf8("く|"))){
            radical.chop(2);
            return radical + QString::fromUtf8("こ|");
        }
        return radical;

    case _vn://irregular nu verb 死ぬ
        return radical + QString::fromUtf8("の");

    case _vs://noun or participle which takes the aux. verb suru
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_c://su verb - precursor to the modern suru
        return radical + QString::fromUtf8("し");

    case _vs_i://suru verb - irregular
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    case _vs_s: //suru verb - special class
        radical.chop(2);
        return radical + QString::fromUtf8("|し");

    default:
        break;
    }

    return radical;

}
