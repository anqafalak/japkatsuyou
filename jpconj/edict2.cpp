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

#include "edict2.h"

//
const int Edict2::map2jpconj[28][2] = {
{0, -1}, // 0
{_ichidan, _ruEnd}, //1
{_nidan, _uEnd}, //2
{_yondan, _huEnd}, //3
{_yondan, _ruEnd}, //4
{_ichidan, _ruEnd}, //5
{_irregular, _ruEnd}, //6
{_godan, _buEnd}, //7
{_godan, _guEnd}, //8
{_godan, _kuEnd}, //9
{_ikuVerb, _kuEnd}, //10
{_godan, _muEnd}, //11
{_godan, _nuEnd}, //12
{_godan, _ruEnd}, //13
{_aruVerb, _ruEnd}, //14  godan with ru irregular
{_godan, _suEnd}, //15
{_godan, _tuEnd}, //16
{_godan, _uEnd}, //17
{_kouTou, _uEnd}, //18 godan with u special
{_godan, -1}, //19 godan with uru old form of eru : no verb in the database
{_godan, -1}, //20 godan with zu : no verb in the database
{_zuruVerb, _ruEnd}, //21
{_kuruVerb, _ruEnd}, //22 kuru verb - special class
{_godan, _nuEnd}, //23 irregular nu verb : 死ぬ
{_suruVerb, _ruEnd}, //24 noun or participle which takes the aux. verb suru
{_suruVerb, -1}, //25 su verb - precursor to the modern suru
{_suruVerb, _ruEnd}, //26 suru verb - irregular
{_ssuruVerb, _ruEnd}//27 suru verb - special class
};

Edict2::Edict2()
{
    connect();
}

Edict2::~Edict2()
{
    //
}

void Edict2::connect()
{
    if (!QSqlDatabase::contains("dbverbs"))
    {
        verbdb =  QSqlDatabase::addDatabase("QSQLITE","dbverbs");
        verbdb.setDatabaseName(QString(dataFolder) + "verbs/edict2verbs.db" );//QDir::homePath() + QDir::separator() + "inoveDB.db3"
    }
    else
    {
        verbdb =  QSqlDatabase::database("dbverbs");
    }
}



void Edict2::desconnect()
{
    if (QSqlDatabase::contains("dbverbs"))
    {
        QSqlDatabase::removeDatabase("dbverbs");
    }
}

int Edict2::find(QString verb)
{
    int result= 0;

        if (verbdb.open()) {
            //qDebug() << "DB connected";
            QSqlQuery query(verbdb);
            query.exec("SELECT * FROM tkanji WHERE kanji='" + verb + "';");
            QSqlRecord record = query.record();
            if (query.next()) {
                result = query.value(record.indexOf("idtype")).toInt();
                //qDebug() << "Verb kanji found" << result;
            }
            else
            {
                query.exec("SELECT * FROM tkana WHERE kana='" + verb + "';");
                record = query.record();
                if (query.next()) {
                    result = query.value(record.indexOf("idtype")).toInt();
                    //qDebug() << "Verb kana found" << result;
                }
            }

        } else {
            //qDebug() << "DB not connecting";
        }
    //qDebug() << result;
    verbdb.close();

    return result;
}

void Edict2::getType(int edict2type, int &type, int &end)
{
    type = map2jpconj[edict2type][0];
    end = map2jpconj[edict2type][1];
}
