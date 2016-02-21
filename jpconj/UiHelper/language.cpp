/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

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

#include "language.h"

/*!
 * \class Language
 * This class is used to manage the localization
 */

QTranslator* Language::currentQtTranslator = 0;
QTranslator* Language::currentJpconjTranslator = 0;
QString Language::currentLanguageID = "";
QHash<QString, PairTrans> Language::translators;
QHash<QString, QString> Language::languagesInfo;



/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief Language::mainWindowDirection Sets the Layout direction to RTL or LTR
 *
 * Sets the direction of a given QMainWindow to RTL or LTR according to current local
 * - RTL: If the local first two characters are in: ar, dv, ha, he, fa, ps, ur, yi
 * - LTR: Otherwise
 * \param w A QMainWindow which we want to set the direction.
 * \return true if rtl, false if ltr
 */
bool Language::mainWindowDirection(QMainWindow * w)
{
    QString langID = getConfigLanguage();
    if (QString("ar|dv|ha|he|fa|ps|ur|yi").contains(langID.right(2))){
        qApp->setLayoutDirection(Qt::RightToLeft);
        w->setLayoutDirection(Qt::RightToLeft);
        return true;
    }

    qApp->setLayoutDirection(Qt::LeftToRight);
    w->setLayoutDirection(Qt::LeftToRight);

    return false;

}



/*!
 * \brief Language::getConfigLanguage Get the language ID from the Config file
 * \return The ID of the specified language \n
 * If the language ID is not available, it returns "??"
 */
QString Language::getConfigLanguage()
{
    QSettings settings;//("DzCoding", "JapKatsuyou")

    return settings.value("langacro", "??").toString();
}



/*!
 * \brief Language::getCurrentLanguage Get the current language ID
 * \return The ID of the language used currently
 */
QString Language::getCurrentLanguage()
{
    return currentLanguageID;
}



/*!
 * \brief Language::setConfigLanguage Set the language ID to the Config file
 * \param langID
 */
void Language::setConfigLanguage(QString langID)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.setValue("langacro", langID);

    //currentLanguageID = langID;
}



/*!
 * \brief Language::getLanguagesInfo Get ID's and names of available languages.
 * \return A QHash of language-ID as key, and language-name as value. \n
 * Example: <en, English>, <ar, Arabic>, etc.
 */
QHash<QString, QString> Language::getLanguagesInfo()
{
    return languagesInfo;
}



/*!
 * \brief Language::loadTranslations Look for available translations and load them.
 *
 * It looks for available languages in an XML file, containing id, name, location.
 * Then, it loads the languages (translations) from their locations.
 * It creates, also, the QHash<QString, QString> languagesInfo that can be returned
 * using the function Language::getLanguagesInfo
 */
void Language::loadTranslations()
{
    QDir langDefaultDir (QString(dataFolder) + "i18n/");
    QStringList languageINIFiles = langDefaultDir.entryList(QStringList("jpconj_*.ini"));

    languagesInfo.insert("en", "English");
    addTranslation("en", ""); // add English language to tanslators

    foreach (QString langINIFile, languageINIFiles){
        QString langFileName = langINIFile;
        langFileName.chop(4);

        QFile langFile (QString(dataFolder) + "i18n/" + langFileName +".qm");
        if (langFile.exists()){
            QString languageId = langFileName.mid(7);
            QSettings langSettings(QString(dataFolder) + "i18n/" + langINIFile, QSettings::IniFormat);
            langSettings.setIniCodec("UTF-8");
            QString languageName = langSettings.value("name").toString();
            //qDebug() << langFile.fileName();
            languagesInfo.insert(languageId, languageName);
            addTranslation(languageId, QString(dataFolder) + "i18n/"); // add language to tanslators
        }
    }
    setLanguage();

}



/*******************************************************
 *                    PRIVATE
 *******************************************************/

/*!
 * \brief Language::addTranslation Add a translation (language) to available languages.
 * \param langId The language ID: "en", "ar", "fr", "ja", etc.
 * \param dir The language's translation file's location. eg. "./i18n/jpconj_ar.qm"
 */
void Language::addTranslation(QString langId, QString dir)
{
    QString jpconjTransLocation = dir + "jpconj_" + langId + ".qm";
    QTranslator* jpconjTranslator = new QTranslator();

    /*if (jpconjTranslator->load(jpconjTransLocation))
        translators.insert(langId, jpconjTranslator);*/
    //qDebug() << langId << "-----" << dir;

    QString qtTransLocation = dir + "qt_" + langId.left(2) + ".qm";
    QTranslator* qtTranslator = new QTranslator();
    /*if (qtTranslator->load(qtTransLocation))
        translators.insert(langId, qtTranslator);*/
    qtTranslator->load(qtTransLocation);
    jpconjTranslator->load(jpconjTransLocation);

    translators.insert(langId, PairTrans(jpconjTranslator, qtTranslator));

}



/*******************************************************
 *                   PUBLIC SLOTS
 *******************************************************/

/*!
 * \brief Language::setLanguage Set a specified language to be used in the UI.
 *
 * To set a language, you have to follow these steps:
 * - First, load translations in the start of the application using Language::loadTranslations
 * - Then get available languages using the function Language::getLanguagesInfo \n
 * eg. \code QHash<QString, QString> langinf = Language::getLanguagesInfo(); \code
 * - Choose a language ID. Let say, you choosed language ID "ja" for Japanese
 * - Save this language ID in the config file, using Language::setConfigLanguage \n
 * eg. \code Language::setConfigLanguage("ja") \code
 * - Finaly, call this function, and it will get the language ID from the config file
 * and charge it, if not available it charge the system's language, if also not available
 * it charge the English language (ID = "en").
 */
void Language::setLanguage()
{
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

    if (langID != currentLanguageID){

        currentLanguageID = langID;

        if (currentJpconjTranslator)
            qApp->removeTranslator(currentJpconjTranslator);

        if (currentQtTranslator)
            qApp->removeTranslator(currentQtTranslator);

        currentJpconjTranslator = translators.value(currentLanguageID).first;
        currentQtTranslator = translators.value(currentLanguageID).second;

        if (currentQtTranslator)
            qApp->installTranslator(currentQtTranslator);

        if (currentJpconjTranslator)
            qApp->installTranslator(currentJpconjTranslator);
    }
}
