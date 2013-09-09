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
    EdictType find(QString verb);
    void connect();
    void desconnect();

private:
    QSqlDatabase verbdb;

};

#endif // EDICT2_H
