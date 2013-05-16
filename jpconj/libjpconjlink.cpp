#include "libjpconjlink.h"

libjpconjlink::libjpconjlink()
{
}


QString libjpconjlink::conjugate(QString verb, int type, int time, bool polite, bool positive)
{
    typedef QString (*pf)(QString, int, int, bool, bool);

     pf conj =(pf)QLibrary::resolve("liblibjpconj","conj");

     return  conj(verb, type, time, polite, positive);
}

