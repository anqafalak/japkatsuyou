/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

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

#include "language.h"

QTranslator* Language::current = 0;
QHash<QString, QTranslator*> Language::translators;
QHash<QString, QString> Language::languagesInfo;

Language::Language()
{
}


void Language::mainWindowDirection(QMainWindow * w)
{
    QString langID = getConfigLanguage();
    if (QString("ar|dv|ha|he|fa|ps|ur|yi").contains(langID.right(2))){
        qApp->setLayoutDirection(Qt::RightToLeft);
        w->setLayoutDirection(Qt::RightToLeft);
    }else{
        qApp->setLayoutDirection(Qt::LeftToRight);
        w->setLayoutDirection(Qt::LeftToRight);
    }

}


void Language::addTranslation(QString langId, QString dir)
{
    QString jpconjTransLocation = dir + "jpconj_" + langId + ".qm";
    QTranslator* jpconjTranslator = new QTranslator();
    if (jpconjTranslator->load(jpconjTransLocation))
        translators.insert(langId, jpconjTranslator);

    QString qtTransLocation = dir + "jpconj_" + langId.left(2) + ".qm";
    QTranslator* qtTranslator = new QTranslator();
    if (qtTranslator->load(qtTransLocation))
        translators.insert(langId, qtTranslator);
}

QString Language::getConfigLanguage()
{
    QSettings settings;//("DzCoding", "JapKatsuyou")

    return settings.value("langacro", "??").toString();
}

void Language::setConfigLanguage(QString langID)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")

    settings.setValue("langacro", langID);
}

QHash<QString, QString> Language::getLanguagesInfo()
{
    return languagesInfo;
}

void Language::loadTranslations()
{
    QFile languageConfigFile(QString(dataFolder) + "i18n/languages.xml");
    if (! languageConfigFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "The language config file doesn't exist";
        return;
    }

    QDomDocument languageXmlDoc;
    if (!languageXmlDoc.setContent(&languageConfigFile)) {
         languageConfigFile.close();
         return;
    }
    languageConfigFile.close();

    QDomElement xmlDocRoot = languageXmlDoc.documentElement();
    QDomNodeList availableLanguages = xmlDocRoot.elementsByTagName("language");

    for (int langIdx = 0; langIdx < availableLanguages.count(); langIdx++){
        QDomElement thisLanguage = availableLanguages.at(langIdx).toElement();

        //qDebug() << thisLanguage.attribute("id");

        QString languageId = thisLanguage.attribute("id");

        QDomNode LangEntry = thisLanguage.firstChild();
        while(!LangEntry.isNull()) {
            QDomElement LangData = LangEntry.toElement();
            QString DataType = LangData.tagName();

            if(DataType == "name") {
                languagesInfo.insert(languageId, LangData.text()); //insert language id, and its name
                //qDebug() << "language name" << LangData.text();
            } else if (DataType == "location"){
                addTranslation(languageId, LangData.text()); // add language to tanslators
                //qDebug() << "language location" << LangData.text();
            } //end if
            LangEntry = LangEntry.nextSibling();
        } //end while

    } //end for

    //run the specified language
    setLanguage();

}


void Language::setLanguage()
{
    // remove previous

    QString langID = getConfigLanguage();

    if(!translators.contains(langID)){
        langID = QLocale::system().uiLanguages().at(0);

        if(!translators.contains(langID)){
            langID = langID.left(2);
            if(!translators.contains(langID))
                langID = "en";
        }
        setConfigLanguage(langID);
    }

    if (current)
    {
        qApp->removeTranslator(current);
    }

    current = translators.value(langID, 0);

    if (current)
    {
        qApp->installTranslator(current);
    }
}
