/*
    This file is part of JapKatsyou project; an application that provide
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

#ifndef EDICT2_H
#define EDICT2_H

#include <QtSql/QtSql>
#include "QDebug"
#include "typeDefs.h"
#include "paths.h"

class Edict2
{

public:
    Edict2();
    ~Edict2();
    int find(QString verb);
    void connect();
    void desconnect();
    static void getType(int edict2type, int &type, int &end);

private:
    QSqlDatabase verbdb;
    static const int map2jpconj[28][2];

    /*
    const TypeEnd map2jpconj[] = {
        TypeEnd(0, -1}, // 0
        TypeEnd{_ichidan, _ruEnd}, //1
        TypeEnd{_nidan, _uEnd}, //2
        TypeEnd{_yondan, _huEnd}, //3
        TypeEnd{_yondan, _ruEnd}, //4
        TypeEnd{_ichidan, _ruEnd}, //5
        TypeEnd{_irregular, _ruEnd}, //6
        TypeEnd{_godan, _buEnd}, //7
        TypeEnd{_godan, _guEnd}, //8
        TypeEnd{_godan, _kuEnd}, //9
        TypeEnd{_iku, _kuEnd}, //10
        TypeEnd{_godan, _muEnd}, //11
        TypeEnd{_godan, _nuEnd}, //12
        TypeEnd{_godan, _ruEnd}, //13
        TypeEnd{_aru, _ruEnd}, //14  godan with ru irregular
        TypeEnd{_godan, _suEnd}, //15
        TypeEnd{_godan, _tuEnd}, //16
        TypeEnd{_godan, _uEnd}, //17
        TypeEnd{_irregular, _uEnd}, //18 godan with u special
        TypeEnd{_godan, -1}, //19 godan with uru old form of eru : no verb in the database
        TypeEnd{_godan, -1}, //20 godan with zu : no verb in the database
        TypeEnd{_zuruVerb, _ruEnd}, //21
        TypeEnd{_kuruVerb, _ruEnd}, //22 kuru verb - special class
        TypeEnd{_godan, _nuEnd}, //23 irregular nu verb : 死ぬ
        TypeEnd{_suruVerb, _ruEnd}, //24 noun or participle which takes the aux. verb suru
        TypeEnd{_suruVerb, -1}, //25 su verb - precursor to the modern suru
        TypeEnd{_suruVerb, _ruEnd}, //26 suru verb - irregular
        TypeEnd{_suruVerb, _ruEnd)}; //27 suru verb - special class
*/
};

#endif // EDICT2_H
