#ifndef MSG_H
#define MSG_H

#include "typeDefs.h"
#include "QString"
#include <QMap>
#include <QPair>

/*
namespace verbForms {


QMap<int, int> formse;

formDesc desc("","");

formse.insert(1,2);
const int id[]={
    VConjugate::_Present,
    VConjugate::_Past,
    VConjugate::_Provision,
    VConjugate::_Condition,
    VConjugate::_Imperative,
    VConjugate::_Volitional,
    VConjugate::_PresentContinuous,
    VConjugate::_PastContinuous,
    VConjugate::_Passive,
    VConjugate::_Causative,
    VConjugate::_CausativePassive,
    VConjugate::_Potential
};

const QString name[]={
    QObject::tr("Present"),
    QObject::tr("Past"),
    QObject::tr("Provisional Condition"),
    QObject::tr("Condition"),
    QObject::tr("Imperative"),
    QObject::tr("Volitional"),
    QObject::tr("Present Continuous"),
    QObject::tr("Past Continuous"),
    QObject::tr("Passive"),
    QObject::tr("Causative"),
    QObject::tr("Causative Passive"),
    QObject::tr("Potential")
};

}*/


typedef QPair<QString, QString> formDesc;
typedef QObject verbFormNames; //used just to butify i18n files: name of verb form
typedef QObject verbFormDesc; //used just to butify i18n files: description of verb form
static QMap<CForm, formDesc> setVerbForms() {
    QMap<CForm, formDesc> mapVerbForms;

    mapVerbForms.insert(VConjugate::_Present,
                        formDesc(verbFormNames::tr("Present"),
                                 verbFormDesc::tr("This is the present tense")));

    mapVerbForms.insert(VConjugate::_Past,
                        formDesc(verbFormNames::tr("Past"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Provision,
                        formDesc(verbFormNames::tr("Provisional Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Condition,
                        formDesc(verbFormNames::tr("Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Imperative,
                        formDesc(verbFormNames::tr("Imperative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Volitional,
                        formDesc(verbFormNames::tr("Volitional"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_PresentContinuous,
                        formDesc(verbFormNames::tr("Present Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_PastContinuous,
                        formDesc(verbFormNames::tr("Past Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Passive,
                        formDesc(verbFormNames::tr("Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Causative,
                        formDesc(verbFormNames::tr("Causative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_CausativePassive,
                        formDesc(verbFormNames::tr("Causative Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(VConjugate::_Potential,
                        formDesc(verbFormNames::tr("Potential"),
                                 verbFormDesc::tr("")));

    return mapVerbForms;
}
static const QMap<CForm, formDesc> verbForms = setVerbForms();


#endif // MSG_H
