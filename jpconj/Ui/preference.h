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

#ifndef PREFERENCE_H
#define PREFERENCE_H

#include "UiHelper/export.h"
#include "UiHelper/language.h"
#include "UiHelper/style.h"

#include <QDebug>
#include <QDialog>
#include <QMap>


namespace Ui {
class Preference;
}

class Preference : public QDialog
{
    Q_OBJECT
    
public:
    explicit Preference(QWidget *parent = 0);
    ~Preference();

private:
    Ui::Preference *ui;
    void doInit();
    void doSave();

private slots:
    void on_prefOK_accepted();

};

#endif // PREFERENCE_H
