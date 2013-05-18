#include "jpconjmain.h"
#include "qdialog.h"

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

void jpconjmain::on_action_About_triggered()
{
    openAbout();
}


//private functions

void jpconjmain::openAbout()
{
    winAbout = new About(this);
    //winAbout->setWindowFlags(Qt::WindowTitleHint | Qt::Dialog | Qt::CustomizeWindowHint);
    //winAbout->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    winAbout->setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    winAbout->show();
}

void jpconjmain::doInit()
{
    //Initialize types of verb
    ui->vfrmchoice->addItem("Ichidan", QVariant(_ichidan));
    ui->vfrmchoice->addItem("Godan", QVariant(_godan));
    //ui->vfrmchoice->addItem("Zuru Verb", QVariant(_zuruVerb));

    //Initialize conjugation time
    ui->conjchoice->addItem("TeForm", QVariant(_TeForm));
    ui->conjchoice->addItem("Present", QVariant(_Present));
    ui->conjchoice->addItem("Past", QVariant(_Past));
    ui->conjchoice->addItem("Provision", QVariant(_Provision));
    ui->conjchoice->addItem("Condition", QVariant(_Condition));
    ui->conjchoice->addItem("Imperative", QVariant(_Imperative));
    ui->conjchoice->addItem("Volitional", QVariant(_Volitional));
    ui->conjchoice->addItem("Present Continuous", QVariant(_PresentContinuous));
    ui->conjchoice->addItem("Past Continuous", QVariant(_PastContinuous));
    ui->conjchoice->addItem("Passive", QVariant(_Passive));
    ui->conjchoice->addItem("Causative", QVariant(_Causative));
    ui->conjchoice->addItem("Causative Passive", QVariant(_CausativePassive));
    ui->conjchoice->addItem("Potential", QVariant(_Potential));
    ui->conjchoice->addItem("Raison", QVariant(_Raison));

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


