#ifndef LIBJPCONJLINK_H
#define LIBJPCONJLINK_H

#include "verbtype.h"
#include "verbtime.h"
#include "QLibrary"

class libjpconjlink
{
public:
    libjpconjlink();
    static QString conjugate(QString verb, int type, int time, bool polite, bool positive);
};

#endif // LIBJPCONJLINK_H
