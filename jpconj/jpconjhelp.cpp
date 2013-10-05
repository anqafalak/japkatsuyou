#include "jpconjhelp.h"
#include "ui_jpconjhelp.h"

jpconjhelp::jpconjhelp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jpconjhelp)
{
    ui->setupUi(this);
    Init();
    this->tabifyDockWidget(ui->contentsDock, ui->indexDock);
    ui->contentsDock->raise();
}

jpconjhelp::~jpconjhelp()
{
    delete ui;
}

void jpconjhelp::on_actionClose_triggered()
{
    this->close();
}


void jpconjhelp::Init()
{
    helpEngine = new QHelpEngine("./help/en.qhc", this);
    helpEngine->setupData();

       //QHelpContentModel *contentModel = helpEngine->contentModel();
       QHelpContentWidget *contentWidget = helpEngine->contentWidget();
       //QHelpIndexModel* indexModel = helpEngine->indexModel();
       QHelpIndexWidget* indexWidget = helpEngine->indexWidget();


       //splitter->addWidget((QWidget*) contentWidget);
       //splitter->addWidget((QWidget*) indexWidget);
       //contentWidget->setModel(contentModel);
       //indexWidget->setModel(indexModel);

       ui->contentsWidget->layout()->addWidget((QWidget*) contentWidget);
       ui->indexWidget->layout()->addWidget((QWidget*) indexWidget);

       helpViewer = new HelpViewer (helpEngine, this);

       ui->frame->layout()->addWidget(helpViewer);

       connect(this, SIGNAL(indexInputChanged(const QString & , const QString &)),
                   indexWidget, SLOT(filterIndices(const QString & , const QString &)));

       connect(contentWidget, SIGNAL(linkActivated(const QUrl &)),
                   this, SLOT(loadPage(const QUrl &)));

       connect(indexWidget, SIGNAL(linkActivated(const QUrl &, const QString &)),
                   this, SLOT(loadPage(const QUrl &)));


}


void jpconjhelp::loadPage(const QUrl &url)
{
    helpViewer->setSource(url);
}

void jpconjhelp::loadPage(const QUrl &url, const QString & keyword)
{
    helpViewer->setSource(url);
}


void jpconjhelp::on_indexInput_textEdited(const QString &arg1)
{
    this->indexInputChanged(arg1);
}
