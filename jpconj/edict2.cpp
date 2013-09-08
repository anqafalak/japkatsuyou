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

