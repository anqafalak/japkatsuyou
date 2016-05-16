/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013-2016  AnqaFalak group
    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

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

#include "style.h"

/*!
 * \class Style
 * This class is used to manage the tables styles (CSS)
 */

QHash<QString, Styleinfo*> Style::styles;
QString Style::currentstyle = "";

QString Style::currentFont = "";
QString Style::currentJpFont = "";
int Style::currentFontSize = 12;
int Style::currentJpFontSize = 12;

Style* Style::_instance = new Style();



/*******************************************************
 *                    PUBLIC
 *******************************************************/

Styleinfo::Styleinfo()
{

}


Style::Style()
{

}

void Style::emitSignal(QString styleID)
{
    emit styleChanged(styleID);
}

void Style::signalFontChanged(QString font, QString jpfont, int size, int jpsize)
{
    emit fontChanged(font, jpfont, size, jpsize);
}

void Style::loadStyles()
{
    styles.clear();

    QDir styleDefaultDir (QString(dataFolder) + "styles/");
    QStringList styleFiles = styleDefaultDir.entryList(QStringList("*.ini"));

    foreach (QString styleFile, styleFiles){
        QString styleFileName = styleFile;
        styleFileName.chop(4);
        Styleinfo* styleinfo = new Styleinfo();

        QSettings styleSettings(QString(dataFolder) + "styles/" + styleFile, QSettings::IniFormat);
        styleSettings.setIniCodec("UTF-8");
        styleinfo->name = styleSettings.value("name").toString();
        styleinfo->author = styleSettings.value("author").toString();
        styleinfo->date = styleSettings.value("date").toString();
        styleinfo->desc = styleSettings.value("desc").toString();

        styles.insert(styleFileName, styleinfo);

    }

    setStyle();
}

/*!
 * \brief Style::getStyleInfo Get ID's and names of available style sheets.
 * \return A QHash of style-ID as key, and style-name as value. \n
 * Example: <DzStyle, DzCoding default style>, etc.
 */
QHash<QString, Styleinfo*> Style::getStyleInfo()
{
    return styles;
}


void Style::setConfigStyle(QString styleID)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.setValue("style", styleID);
}


QString Style::getConfigStyle()
{
    QSettings settings;//("DzCoding", "JapKatsuyou")

    return settings.value("style", "??").toString();
}


QString Style::getCurrentStyle()
{
    return currentstyle;
}


void Style::addReceiver(const QObject * receiver, const char * receiverSlot)
{
    connect(_instance, SIGNAL(styleChanged(QString)), receiver, receiverSlot);
}

void Style::addFontReceiver(const QObject *receiver, const char *receiverSlot)
{
    connect(_instance, SIGNAL(fontChanged(QString, QString, int,int)), receiver, receiverSlot);
}

QString Style::getConfigFont(bool jap)
{
    QSettings settings;

    if (jap)
        return settings.value("jp_font-family", "").toString();
    return settings.value("font-family", "").toString();
}

QString Style::getCurrentFont(bool jap)
{
    if (jap)
        return currentJpFont;

    return currentFont;
}

void Style::setConfigFont(QString font, bool jap)
{
    QSettings settings;

    if (jap)
        settings.setValue("jp_font-family", font);
    else
        settings.setValue("font-family", font);
}

int Style::getConfigFontSize(bool jap)
{
    QSettings settings;

    if (jap)
        return settings.value("jp_font-size", "12").toInt();

    return settings.value("font-size", "12").toInt();
}

int Style::getCurrentFontSize(bool jap)
{
    if (jap)
        return currentJpFontSize;

    return currentFontSize;
}

void Style::setConfigFontSize(int fontSize, bool jap)
{
    QSettings settings;

    if (jap)
        settings.setValue("jp_font-size", fontSize);
    else
        settings.setValue("font-size", fontSize);
}


/*******************************************************
 *                   PUBLIC SLOTS
 *******************************************************/

void Style::setStyle()
{
    //currentstyle = styleID;
    QString styleID = getConfigStyle();
    if(!styles.contains(styleID)){
        styleID = "DzStyle";
        setConfigStyle(styleID);
    }

    if (styleID != currentstyle){
        currentstyle = styleID;
        _instance->emitSignal(styleID);
        //qDebug() << "emit signal";
    }

}

void Style::setFont()
{
    QString font = getConfigFont(false);
    QString jpfont = getConfigFont(true);
    int size = getConfigFontSize(false);
    int jpsize = getConfigFontSize(true);

    bool changed = false;

    if (font != currentFont){
        currentFont = font;
        changed = true;
    }

    if (jpfont != currentJpFont){
        currentJpFont = jpfont;
        changed = true;
    }

    if (size != currentFontSize){
        currentFontSize = size;
        changed = true;
    }

    if (jpsize != currentJpFontSize){
        currentJpFontSize = jpsize;
        changed = true;
    }

    if (changed)
        _instance->signalFontChanged(font, jpfont, size, jpsize);
}
