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
#ifndef JTRANS_H
#define JTRANS_H

#include <QString>
#include <QHash>
#include <QDebug>
#include <QRegExp>

/**
 * @brief The JTrans class is used to romanize hiragana and katakana
 */
class JTrans
{
    //typedef QHash<QString, QString> map;

public:
    JTrans();
    static QString hiragana2romaji(QString hiragana);


private:
    static QHash<QString, QString> InitMap();
    static QHash<QString, QString> romajiMap;
};

#endif // JTRANS_H
