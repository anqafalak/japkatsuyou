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
    verbForm::_Present,
    verbForm::_Past,
    verbForm::_Provision,
    verbForm::_Condition,
    verbForm::_Imperative,
    verbForm::_Volitional,
    verbForm::_PresentContinuous,
    verbForm::_PastContinuous,
    verbForm::_Passive,
    verbForm::_Causative,
    verbForm::_CausativePassive,
    verbForm::_Potential
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
static QMap<int, formDesc> setVerbForms() {
    QMap<int, formDesc> mapVerbForms;

    mapVerbForms.insert(verbForm::_Present,
                        formDesc(verbFormNames::tr("Present"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Past,
                        formDesc(verbFormNames::tr("Past"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Provision,
                        formDesc(verbFormNames::tr("Provisional Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Condition,
                        formDesc(verbFormNames::tr("Condition"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Imperative,
                        formDesc(verbFormNames::tr("Imperative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Volitional,
                        formDesc(verbFormNames::tr("Volitional"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_PresentContinuous,
                        formDesc(verbFormNames::tr("Present Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_PastContinuous,
                        formDesc(verbFormNames::tr("Past Continuous"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Passive,
                        formDesc(verbFormNames::tr("Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Causative,
                        formDesc(verbFormNames::tr("Causative"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_CausativePassive,
                        formDesc(verbFormNames::tr("Causative Passive"),
                                 verbFormDesc::tr("")));

    mapVerbForms.insert(verbForm::_Potential,
                        formDesc(verbFormNames::tr("Potential"),
                                 verbFormDesc::tr("")));

    return mapVerbForms;
}
static const QMap<int, formDesc> verbForms = setVerbForms();


#endif // MSG_H
