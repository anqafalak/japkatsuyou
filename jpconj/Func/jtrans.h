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
