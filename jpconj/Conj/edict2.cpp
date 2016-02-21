/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#include "edict2.h"

/*!
 * \class Edict2
 * This class is used to connect to the verbs' database,
 * and verify if a verb exists, then get its type
 */



/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief Edict2::Edict2 Constructor of the Edict2 management module
 */
Edict2::Edict2()
{
    connect();
}



/*!
 * \brief Edict2::~Edict2 Destructor of the Edict2 management module
 */
Edict2::~Edict2()
{

}



/*!
 * \brief Edict2::connect Connect to edict2verbs.db SqLite database
 *
 * This function is loaded when we want to manage edict2verbs.db SqLite database.
 * It looks for a connection name called "dbverbs", if found we just use the database
 * assigned to that connection name.
 * If not, we search for edict2verbs.db, and assign connection name called "dbverbs" to it.
 */
void Edict2::connect()
{
    if (!QSqlDatabase::contains("dbverbs"))
    {
        verbdb =  QSqlDatabase::addDatabase("QSQLITE","dbverbs");
        verbdb.setDatabaseName(QString(dataFolder) + "verbs/edict2verbs.db" );
    }
    else
    {
        verbdb =  QSqlDatabase::database("dbverbs");
    }
}



/*!
 * \brief Edict2::desconnect Desconnect edict2verbs.db SqLite database
 *
 * It looks for a connection name called "dbverbs", if found we remove it.
 */
void Edict2::desconnect()
{
    if (QSqlDatabase::contains("dbverbs"))
    {
        QSqlDatabase::removeDatabase("dbverbs");
    }
}



/*!
 * \brief Edict2::find Search for a verb in the database, and return its type.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \return The type of the verb if found (See: VerbType::EdictType)
 */
EdictType Edict2::find(QString verb)
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

    return (EdictType) result;
}

