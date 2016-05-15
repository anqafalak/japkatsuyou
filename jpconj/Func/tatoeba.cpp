/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2016  AnqaFalak group

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

#include "tatoeba.h"

Tatoeba::Tatoeba()
{
    connect();
}

QList<Tatoeba::Exp> Tatoeba::find(QString verb, QString lang)
{

    QString lang2 = convertLang(lang);
    QList<Exp> result;
    //tatoebadb

    QString radical = verb;
    radical.chop(1);

    if (tatoebadb.open()) {
        //qDebug() << "Tatoeba DB connected";
        QSqlQuery query(tatoebadb);
        QString req;

        bool notJPN = true;

        if (lang2 == "jpn"){
            req = "SELECT jpn.id, jpn.sent \n";
            req += "FROM jpn \n";
            req += "WHERE jpn.sent LIKE \"%" + radical + "%\" LIMIT 100;\n";
            notJPN = false;
        } else {
            req = "SELECT jpn.id, jpn.sent, " + lang2 + ".sent\n";
            req += "FROM jpn, links, " + lang2 + "\n";
            req += "WHERE jpn.sent LIKE \"%" + radical + "%\"\n";
            req += "AND links.jpnId = jpn.id \n";
            req += "AND links.id = " + lang2 + ".id  LIMIT 200;\n";
        }

        int pastId = -1;
        query.exec(req);
        QString JPsent;
        int i = 0;
        while (query.next()) {
            int id = query.value(0).toInt();

            if (id != pastId){
                i++;
                if(i > 100)
                    break;
                JPsent = query.value(1).toString();
                QList<QString> langTrans;

                Exp example;
                example.jap = JPsent;
                example.lang = langTrans;

                result.append(example);

                pastId = id;

            }

            if(notJPN){
                Exp & example = result.last();
                QList<QString> & langTrans = example.lang;
                QString langSent = query.value(2).toString();
                langTrans.append(langSent);
            }

        }

    } else {
        qDebug() << "DB not connecting";
    }
    //qDebug() << result.size();
    tatoebadb.close();

    return result;
}

void Tatoeba::connect()
{
    if (!QSqlDatabase::contains("dbexamples"))
    {
        tatoebadb =  QSqlDatabase::addDatabase("QSQLITE","dbexamples");
        tatoebadb.setDatabaseName(QString(dataFolder) + "DB/tatoeba.db" );
    }
    else
    {
        tatoebadb =  QSqlDatabase::database("dbexamples");
    }

}

void Tatoeba::desconnect()
{
    if (QSqlDatabase::contains("dbexamples"))
    {
        QSqlDatabase::removeDatabase("dbexamples");
    }
}

QString Tatoeba::convertLang(QString lang)
{
    if (lang == "ar")
        return "ara";
    if(lang == "en")
        return "eng";
    if(lang == "fr" )
        return "fra";

    return "jpn";
}
