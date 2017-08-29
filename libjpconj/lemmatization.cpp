#include "lemmatization.h"

Lemmatization::Lemmatization()
{

}


QList<VerbInfo> Lemmatization::deConjugate(QString conjVerb)
{
    QList<VerbInfo> result;

    result << getVerbInfo(conjVerb, _Present, _Affirmative, _Plain);
    return result;
}


VerbInfo Lemmatization::getVerbInfo(QString verb, CForm form, Polarity polarity, Politeness politeness)
{
    VerbInfo info;
    info.verb = verb;
    info.form = form;
    info.polarity = polarity;
    info.politeness = politeness;
    return info;
}
