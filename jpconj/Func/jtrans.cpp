#include "jtrans.h"

//hiragana starts from "U+3041"
//katakana starts from "U+30A0"

QHash<QString, QString> JTrans::romajiMap = JTrans::InitMap();

JTrans::JTrans()
{
}

QString JTrans::hiragana2romaji(QString hiragana)
{
    QString result = hiragana;

    foreach (QString key, JTrans::romajiMap.keys()){
        result.replace(key, JTrans::romajiMap[key]);
    }

    const QString reg = QString::fromUtf8("っ(.)");
    result.replace(QRegExp(reg), "\\1\\1");

    const QString reg2 = QString::fromUtf8("iょ");
    result.replace(QRegExp(reg2), "yo");
    return result;

}

QHash<QString, QString> JTrans::InitMap()
{
    QHash<QString, QString> result;
    result[QString::fromUtf8("あ")] = "a";
    result[QString::fromUtf8("い")] = "i";
    result[QString::fromUtf8("う")] = "u";
    result[QString::fromUtf8("え")] = "e";
    result[QString::fromUtf8("お")] = "o";
    result[QString::fromUtf8("か")] = "ka";
    result[QString::fromUtf8("き")] = "ki";
    result[QString::fromUtf8("く")] = "ku";
    result[QString::fromUtf8("け")] = "ke";
    result[QString::fromUtf8("こ")] = "ko";
    result[QString::fromUtf8("さ")] = "sa";
    result[QString::fromUtf8("し")] = "shi";
    result[QString::fromUtf8("す")] = "su";
    result[QString::fromUtf8("せ")] = "se";
    result[QString::fromUtf8("そ")] = "so";
    result[QString::fromUtf8("た")] = "ta";
    result[QString::fromUtf8("ち")] = "chi";
    result[QString::fromUtf8("つ")] = "tsu";
    result[QString::fromUtf8("て")] = "te";
    result[QString::fromUtf8("と")] = "to";
    result[QString::fromUtf8("な")] = "na";
    result[QString::fromUtf8("に")] = "ni";
    result[QString::fromUtf8("ぬ")] = "nu";
    result[QString::fromUtf8("ね")] = "ne";
    result[QString::fromUtf8("の")] = "no";
    result[QString::fromUtf8("は")] = "ha";
    result[QString::fromUtf8("ひ")] = "hi";
    result[QString::fromUtf8("ふ")] = "fu";
    result[QString::fromUtf8("へ")] = "he";
    result[QString::fromUtf8("ほ")] = "ho";
    result[QString::fromUtf8("ま")] = "ma";
    result[QString::fromUtf8("み")] = "mi";
    result[QString::fromUtf8("む")] = "mu";
    result[QString::fromUtf8("め")] = "me";
    result[QString::fromUtf8("も")] = "mo";
    result[QString::fromUtf8("や")] = "ya";
    result[QString::fromUtf8("ゆ")] = "yu";
    result[QString::fromUtf8("よ")] = "yo";
    result[QString::fromUtf8("ら")] = "ra";
    result[QString::fromUtf8("り")] = "ri";
    result[QString::fromUtf8("る")] = "ru";
    result[QString::fromUtf8("れ")] = "re";
    result[QString::fromUtf8("ろ")] = "ro";
    result[QString::fromUtf8("わ")] = "wa";
    result[QString::fromUtf8("を")] = "o";
    result[QString::fromUtf8("ん")] = "n";

    result[QString::fromUtf8("が")] = "ga";
    result[QString::fromUtf8("ぎ")] = "gi";
    result[QString::fromUtf8("ぐ")] = "gu";
    result[QString::fromUtf8("げ")] = "ge";
    result[QString::fromUtf8("ご")] = "go";
    result[QString::fromUtf8("ざ")] = "za";
    result[QString::fromUtf8("じ")] = "ji";
    result[QString::fromUtf8("ず")] = "zu";
    result[QString::fromUtf8("ぜ")] = "ze";
    result[QString::fromUtf8("ぞ")] = "zo";
    result[QString::fromUtf8("だ")] = "da";
    result[QString::fromUtf8("ぢ")] = "di";
    result[QString::fromUtf8("づ")] = "du";
    result[QString::fromUtf8("で")] = "de";
    result[QString::fromUtf8("ど")] = "do";
    result[QString::fromUtf8("ば")] = "ba";
    result[QString::fromUtf8("び")] = "bi";
    result[QString::fromUtf8("ぶ")] = "bu";
    result[QString::fromUtf8("べ")] = "be";
    result[QString::fromUtf8("ぼ")] = "bo";
    result[QString::fromUtf8("ぱ")] = "pa";
    result[QString::fromUtf8("ぴ")] = "pi";
    result[QString::fromUtf8("ぷ")] = "pu";
    result[QString::fromUtf8("ぺ")] = "pe";
    result[QString::fromUtf8("ぽ")] = "po";
    return result;
}
