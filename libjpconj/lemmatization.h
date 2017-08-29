#ifndef LEMMATIZATION_H
#define LEMMATIZATION_H

#include "typeDefs.h"

#include <QList>
#include <QString>


class Lemmatization
{
public:
    Lemmatization();
    static QList<VerbInfo> deConjugate(QString conjVerb);

private:
    static VerbInfo getVerbInfo(QString verb, CForm form, Polarity polarity, Politeness politeness);

};

#endif // LEMMATIZATION_H
