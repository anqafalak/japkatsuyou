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
#ifndef TATOEBA_H
#define TATOEBA_H

#include <QList>
#include <QMap>
#include <QDebug>
#include <QtSql/QtSql>

class Tatoeba
{
public:
    struct Exp {
            QString jap;
            QList<QString> lang;
    };

    Tatoeba();

    QList<Exp> find (QString verb, QString lang);
    void connect();
    void desconnect();

    static QString convertLang(QString lang);

private:
    QSqlDatabase tatoebadb;
};

#endif // TATOEBA_H
