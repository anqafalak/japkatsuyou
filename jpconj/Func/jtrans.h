#ifndef JTRANS_H
#define JTRANS_H

#include <QString>

/**
 * @brief The JTrans class is used to romanize hiragana and katakana
 */
class JTrans
{
public:
    JTrans();
    static QString hiragana2romaji(QString hiragana);
};

#endif // JTRANS_H
