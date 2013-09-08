#ifndef INFLECTION_H
#define INFLECTION_H

#include "libjpconj_global.h"
#include "QString"
#include "QChar"
#include "typeDefs.h"
#include "verbstem.h"

class Inflection
{
public:
    Inflection();
    static QString conjugate(QString verb, VerbType type, VerbForm form, Politeness polite, Polarity affirmative);

private:
    static QString tEnd(QString end, bool te);
    static int getEnd(QString verb); //Not used, it's just for future reference, if it appears some _v5 verbs (unknown end)
};

#endif // INFLECTION_H
