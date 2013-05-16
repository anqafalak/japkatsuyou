#include "jpconjmain.h"

jpconjmain::jpconjmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jpconjmain)
{
    ui->setupUi(this);
    doInit();
}

jpconjmain::~jpconjmain()
{
    delete ui;
}

void jpconjmain::on_action_Close_triggered()
{
    this->close();
}

void jpconjmain::on_actionSay_triggered()
{
    doConj();
}

void jpconjmain::on_btn_conj_clicked()
{
    doConj();
}


//private functions

void jpconjmain::doInit()
{
    //Initialize types of verb
    ui->vfrmchoice->addItem("Ichidan", QVariant(verbType::_ichidan));
    ui->vfrmchoice->addItem("Godan", QVariant(verbType::_godan));
    ui->vfrmchoice->addItem("Zuru Verb", QVariant(verbType::_zuruVerb));

    //Initialize conjugation time
    ui->conjchoice->addItem("TeForm", QVariant(verbTime::_TeForm));
    ui->conjchoice->addItem("Present", QVariant(verbTime::_Present));
    ui->conjchoice->addItem("Past", QVariant(verbTime::_Past));
    ui->conjchoice->addItem("Provision", QVariant(verbTime::_Provision));
}

void jpconjmain::doConj()
{
    QString verb = ui->inputt->text();
    int type = ui->vfrmchoice->itemData(ui->vfrmchoice->currentIndex()).toInt();
    int time = ui->conjchoice->itemData(ui->conjchoice->currentIndex()).toInt();
    bool polite = ui->politecheck->isChecked();
    bool positive = ui->positivecheck->isChecked();
    QString result = libjpconjlink::conjugate(verb, type, time, polite, positive);
    ui->outputt->setText(result);
}
