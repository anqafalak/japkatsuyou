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
    ui->vfrmchoice->addItem(tr("Ichidan"), QVariant(_ichidan));
    ui->vfrmchoice->addItem(tr("Godan"), QVariant(_godan));
    //ui->vfrmchoice->addItem(tr("Zuru Verb"), QVariant(_zuruVerb));

    //Initialize conjugation time
    ui->conjchoice->addItem(tr("TeForm"), QVariant(_TeForm));
    ui->conjchoice->addItem(tr("Present"), QVariant(_Present));
    ui->conjchoice->addItem(tr("Past"), QVariant(_Past));
    ui->conjchoice->addItem(tr("Provisional Condition"), QVariant(_Provision));
    ui->conjchoice->addItem(tr("Condition"), QVariant(_Condition));
    ui->conjchoice->addItem(tr("Imperative"), QVariant(_Imperative));
    ui->conjchoice->addItem(tr("Volitional"), QVariant(_Volitional));
    ui->conjchoice->addItem(tr("Present Continuous"), QVariant(_PresentContinuous));
    ui->conjchoice->addItem(tr("Past Continuous"), QVariant(_PastContinuous));
    ui->conjchoice->addItem(tr("Passive"), QVariant(_Passive));
    ui->conjchoice->addItem(tr("Causative"), QVariant(_Causative));
    ui->conjchoice->addItem(tr("Causative Passive"), QVariant(_CausativePassive));
    ui->conjchoice->addItem(tr("Potential"), QVariant(_Potential));
    ui->conjchoice->addItem(tr("Reason"), QVariant(_Reason));

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


