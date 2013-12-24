#include "jpconjhelp.h"
#include "ui_jpconjhelp.h"

bool jpconjhelp::showed = false;

jpconjhelp::jpconjhelp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jpconjhelp)
{
    ui->setupUi(this);
    Init();
}



jpconjhelp::~jpconjhelp()
{
    delete ui;
}



bool jpconjhelp::exists()
{
    return showed;
}



void jpconjhelp::on_actionClose_triggered()
{
    this->close();
}


void jpconjhelp::Init()
{
    showed = true;

    QString helpFile = QString(dataFolder) + "help/" + Language::getCurrentLanguage().left(2) + ".qhc";

    if (! QFile(helpFile).exists())
        helpFile = QString(dataFolder) + "help/en.qhc";

    helpEngine = new QHelpEngine(helpFile, this);
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
                   this, SLOT(loadPage(const QUrl &, const QString &)));



       this->tabifyDockWidget(ui->contentsDock, ui->indexDock);
       ui->contentsDock->raise();
}


void jpconjhelp::loadPage(const QUrl &url)
{
    helpViewer->setSource(url);
}

void jpconjhelp::loadPage(const QUrl &url, const QString & keyword)
{

    QEventLoop eventLoop;
    connect(helpViewer, SIGNAL(loadFinished(bool)), &eventLoop, SLOT(quit()));

    helpViewer->setSource(url);
    //QWebPage::RemoveFormat
    //helpViewer->pageAction()
    eventLoop.exec();
    helpViewer->reload();
    eventLoop.exec();

    QStringList keywords = keyword.split(" ");
    foreach (QString word, keywords)
        helpViewer->findText(word, QWebPage::HighlightAllOccurrences);
}


void jpconjhelp::on_indexInput_textEdited(const QString &arg1)
{
    this->indexInputChanged(arg1);
}




void jpconjhelp::closeEvent(QCloseEvent *event)
{
    showed = false;
    event->accept();
}
