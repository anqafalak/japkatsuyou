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

#include "verbform.h"

Verbform::Verbform()
{
}

/* \~arabic
* @brief Verbform::eForm <DIV dir="rtl"> استخراج e-form من الفعل</DIV>
*
*
* @param radical <DIV dir="rtl"> الجزء الذي لا يتغير أثناء تصريف الفعل
* مثل 飲む -> 飲 </DIV>
* @param type
* @param end
* @return QString the iform of the verb
*/

/*
QString Verbform::uForm(QString radical, int end)
{
    return radical + _endChars.at(end);
}*/


/*! \~english
 * @brief  Verbform::iForm  Gives the i-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \i radical \i of a verb and gives its i-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b i \b \n
 * eg. 飲む -> 飲み
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: ichidan, godan, etc. See typeDefs.h
 * @param end the ending of the verb: ru, ku, mu, etc. See typeDefs.h
 * @return QString the i-form of the verb
 */
QString Verbform::iForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical;

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("い");
        case _kuEnd:
            return radical + QString::fromUtf8("き");
        case _guEnd:
            return radical + QString::fromUtf8("ぎ");
        case _suEnd:
            return radical + QString::fromUtf8("し");
        case _tuEnd:
            return radical + QString::fromUtf8("ち");
        case _nuEnd:
            return radical + QString::fromUtf8("に");
        case _buEnd:
            return radical + QString::fromUtf8("び");
        case _muEnd:
            return radical + QString::fromUtf8("み");
        case _ruEnd:
            return radical + QString::fromUtf8("り");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("り");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("し");

    case _ikuVerb:
        return radical + QString::fromUtf8("き");

    case _kouTou:
        return radical + QString::fromUtf8("い");

    }

    return radical;
}


/*! \~english
 * @brief  Verbform::eForm  Gives the e-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \i radical \i of a verb and gives its e-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b e \b \n
 * eg. 飲む -> 飲め
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: ichidan, godan, etc. See typeDefs.h
 * @param end the ending of the verb: ru, ku, mu, etc. See typeDefs.h
 * @return QString the e-form of the verb
 */
QString Verbform::eForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical;

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("え");
        case _kuEnd:
            return radical + QString::fromUtf8("け");
        case _guEnd:
            return radical + QString::fromUtf8("げ");
        case _suEnd:
            return radical + QString::fromUtf8("せ");
        case _tuEnd:
            return radical + QString::fromUtf8("て");
        case _nuEnd:
            return radical + QString::fromUtf8("ね");
        case _buEnd:
            return radical + QString::fromUtf8("べ");
        case _muEnd:
            return radical + QString::fromUtf8("め");
        case _ruEnd:
            return radical + QString::fromUtf8("れ");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("れ");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("す");

    case _ikuVerb:
        return radical + QString::fromUtf8("け");

    case _kouTou:
        return radical + QString::fromUtf8("え");

    }

    return radical;
}

/*! \~english
 * @brief  Verbform::oForm  Gives the o-form (stem) of a verb
 *
 *  The function take a \i radical \i of a verb and gives its o-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b o \b \n
 * eg. 飲む -> 飲も
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: ichidan, godan, etc. See typeDefs.h
 * @param end the ending of the verb: ru, ku, mu, etc. See typeDefs.h
 * @return QString the o-form of the verb
 */
QString Verbform::oForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical + QString::fromUtf8("よ");

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("お");
        case _kuEnd:
            return radical + QString::fromUtf8("こ");
        case _guEnd:
            return radical + QString::fromUtf8("ご");
        case _suEnd:
            return radical + QString::fromUtf8("そ");
        case _tuEnd:
            return radical + QString::fromUtf8("と");
        case _nuEnd:
            return radical + QString::fromUtf8("の");
        case _buEnd:
            return radical + QString::fromUtf8("ぼ");
        case _muEnd:
            return radical + QString::fromUtf8("も");
        case _ruEnd:
            return radical + QString::fromUtf8("ろ");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("ろ");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("しよ");

    case _ikuVerb:
        return radical + QString::fromUtf8("こ");

    case _kouTou:
        return radical + QString::fromUtf8("お");
    }

    return radical;
}

/*! \~english
 * @brief  Verbform::aForm  Gives the a-form (stem) of a verb
 *
 *  The function take a \i radical \i of a verb and gives its a-form by changing the last character's sound
 * from \b u \b (dictionary form) to \b a \b \n
 * eg. 飲む -> 飲ま
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: ichidan, godan, etc. See typeDefs.h
 * @param end the ending of the verb: ru, ku, mu, etc. See typeDefs.h
 * @return QString the a-form of the verb
 */
QString Verbform::aForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical;

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("わ");
        case _kuEnd:
            return radical + QString::fromUtf8("か");
        case _guEnd:
            return radical + QString::fromUtf8("が");
        case _suEnd:
            return radical + QString::fromUtf8("さ");
        case _tuEnd:
            return radical + QString::fromUtf8("た");
        case _nuEnd:
            return radical + QString::fromUtf8("な");
        case _buEnd:
            return radical + QString::fromUtf8("ば");
        case _muEnd:
            return radical + QString::fromUtf8("ま");
        case _ruEnd:
            return radical + QString::fromUtf8("ら");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("ら");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("し");

    case _ikuVerb:
        return radical + QString::fromUtf8("か");

    case _kouTou:
        return radical + QString::fromUtf8("わ");
    }

    return radical;
}

/*
                    Case _Irregular
                        Select Case verb_conjug
                            Case "く"
                                verb_conjug = "こ"
                            Case "来", "為"
                                'يبقى كما هو
                            Case "す"
                                verb_conjug = "し"
                        End Select

                    Case _KuruVerb
                        If verb_conjug.EndsWith("く") Then
                            verb_conjug = verb_conjug.Substring(0, verb_conjug.Length - 1) + "こ"
                        End If
                        '来 يبقى كما هو

                    Case _SuruVerb
                        If verb_conjug.EndsWith("す") Then
                            verb_conjug = verb_conjug.Substring(0, verb_conjug.Length - 1) + "し"
                        End If
                        '為 يبقى كما هو
                End Select
*/

//TODO commplete
/*! \~english
 * @brief  Verbform::aForm  Gives the te-form (stem) of a verb
 *
 * In case of GODAN verbs, The function take a \i radical \i of a verb and gives its a-form by changing the last character's sound
 * - u  to tte 買う -> 買って
 * - ku to ite　歩く -> 歩いて
 * - gu to ide　泳ぐ -> 泳いで
 * - su to shite
 * - tsu to tte
 * - nu to nde
 * - bu to nde
 * - mu to nde
 * - ru to tte eg. 取る -> 取って
 *
 * @param radical It is the part which never get changed during conjugation,
 * we can get it dictionary form (u-form) minus the last character (eg. 飲む -> 飲)
 * @param type type of the verb: ichidan, godan, etc. See typeDefs.h
 * @param end the ending of the verb: ru, ku, mu, etc. See typeDefs.h
 * @return QString the a-form of the verb
 */
QString Verbform::teForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical + QString::fromUtf8("て");

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("って");
        case _kuEnd:
            return radical + QString::fromUtf8("いて");
        case _guEnd:
            return radical + QString::fromUtf8("いで");
        case _suEnd:
            return radical + QString::fromUtf8("して");
        case _tuEnd:
            return radical + QString::fromUtf8("って");
        case _nuEnd:
            return radical + QString::fromUtf8("んで");
        case _buEnd:
            return radical + QString::fromUtf8("んで");
        case _muEnd:
            return radical + QString::fromUtf8("んで");
        case _ruEnd:
            return radical + QString::fromUtf8("って");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("って");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("して");

    case _ikuVerb:
        if (radical.endsWith(QString::fromUtf8("ゆ")))
        {
            radical.chop(1);
            return radical + QString::fromUtf8("いって");
        }
        return radical + QString::fromUtf8("って");

    case _kouTou:
        return radical + QString::fromUtf8("うて");
    }

    return radical + QString::fromUtf8("て");
}


QString Verbform::taForm(QString radical, int type, int end)
{
    switch (type){
    case _ichidan:
        return radical + QString::fromUtf8("た");

    case _godan:
        switch (end){
        case _uEnd:
            return radical + QString::fromUtf8("った");
        case _kuEnd:
            return radical + QString::fromUtf8("いた");
        case _guEnd:
            return radical + QString::fromUtf8("いだ");
        case _suEnd:
            return radical + QString::fromUtf8("した");
        case _tuEnd:
            return radical + QString::fromUtf8("った");
        case _nuEnd:
            return radical + QString::fromUtf8("んだ");
        case _buEnd:
            return radical + QString::fromUtf8("んだ");
        case _muEnd:
            return radical + QString::fromUtf8("んだ");
        case _ruEnd:
            return radical + QString::fromUtf8("った");
        }

    case _zuruVerb:
        return radical + QString::fromUtf8("った");

    case _suruVerb:
        radical.chop(1);
        return radical + QString::fromUtf8("した");

    case _ikuVerb:
        if (radical.endsWith(QString::fromUtf8("ゆ")))
        {
            radical.chop(1);
            return radical + QString::fromUtf8("いった");
        }
        return radical + QString::fromUtf8("った");

    case _kouTou:
        return radical + QString::fromUtf8("うた");
    }

    return radical + QString::fromUtf8("た");
}


//private functions
/*
bool Verbform::IkuVerb(QString radical)
{
    if (radical.endsWith(QString::fromUtf8("い")) || radical.endsWith(QString::fromUtf8("行")) || radical.endsWith(QString::fromUtf8("ゆ")))
        return true;
    return false;
}

bool Verbform::Dou_KouVerb(QString radical)
{
    QString verbPoss = QString::fromUtf8("をと,を問,をこ,を請,を乞");
    //int radlength = radical.length();
    if (verbPoss.contains(radical))
        return true;

    return false;
}
*/
