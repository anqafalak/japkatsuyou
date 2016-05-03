/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>
            Zakaria Smahi <zakaria08esi@gmail.com>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#include "jpconjmain.h"
#include "ui_jpconjmain.h"

/*!
 * \class jpconjmain
 * This class is used to manage the main window of the application.
 */


/*******************************************************
 *                    PUBLIC
 *******************************************************/

/*!
 * \brief jpconjmain::jpconjmain The constructor of the main window
 * \param parent
 */
jpconjmain::jpconjmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jpconjmain)
{
    ui->setupUi(this);
    doInit();
}



/*!
 * \brief jpconjmain::~jpconjmain The destructor of the main window
 */
jpconjmain::~jpconjmain()
{
    delete ui;
}



/*******************************************************
 *                    PRIVATE
 *******************************************************/

/*!
 * \brief jpconjmain::doInit Initialize the components of the main window
 *
 * This function sets the language and direction of the main window.
 * You can call it in the constructor of this window.
 */
void jpconjmain::doInit()
{

    workfrm = new ConjFrame(this);
    ui->formLayout->addWidget(workfrm);
    hasContent = false;
    languageChanged = true;
    verbType = _v0;
    currentVerb = "";

    //qDebug()<< QString(VERSION);
    Language::loadTranslations();
    //bool rtl = Language::mainWindowDirection(this);

    ui->menu_View->addAction(ui->mainTool->toggleViewAction());
    ui->menu_View->addAction(ui->zoomTool->toggleViewAction());
    //ui->menu_View->addAction(ui->search->toggleViewAction());
    //ui->showt->setLayoutDirection(Qt::LeftToRight);

    //changeStyle(Style::getCurrentStyle());
    Style::addReceiver(this, SLOT(changeStyle(QString)));
    Style::loadStyles();
    //connect(style, SIGNAL(styleChanged(QString)), this, SLOT(changeStyle(QString)));

    connect(workfrm, SIGNAL(open()), this, SLOT(workfrmOpen()));
    connect(workfrm, SIGNAL(close()), this, SLOT(workfrmClose()));
    connect(workfrm, SIGNAL(newVerb(QString)), this, SLOT(newVerb(QString)));
    //tray Icon
    trayIconSys = new JpconjTray(this);

    actionShow = new QAction(tr("Show"), this); //qApp->translate, "jpconjmain"
    actionShow->setIcon(QIcon(":/img/show.png"));

    connect(actionShow, SIGNAL(triggered()), trayIconSys, SLOT(showMain()));
    trayIconSys->addAction(actionShow);
    trayIconSys->addSeparator();
}



/*!
 * \brief jpconjmain::openAbout This function is used to call "about" dialog box.
 */
void jpconjmain::openAbout()
{
    winAbout = new About(this);
    winAbout->setLayoutDirection(this->layoutDirection());
    winAbout->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    winAbout->show();

}



/*!
 * \brief jpconjmain::openPref This function is used to call "preferences" dialog box.
 */
void jpconjmain::openPref()
{
    winPref = new Preference(this);
    winPref->setLayoutDirection(this->layoutDirection());
    winPref->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    winPref->show();
}





/*!
 * \brief jpconjmain::doConj Used to export the result content as pdf, odt, etc.
 */
void jpconjmain::doExport()
{

    QHash<QString, QString> extensions = Msg::getExportExtensions();

    QStringList filters;

    foreach (QString extension, extensions.keys())
        filters << extensions.value(extension) + " (*" + extension + ")";

    QFileDialog saveDialog;
    saveDialog.setOptions(QFileDialog::DontUseNativeDialog | QFileDialog::DontConfirmOverwrite);  // with or without this
    saveDialog.setFilters(filters);
    //saveDialog.setDefaultSuffix("pdf");
    saveDialog.setFileMode(QFileDialog::AnyFile);
    saveDialog.setAcceptMode(QFileDialog::AcceptSave);
    saveDialog.setDirectory(QDir::homePath());
    QString defaultName = currentVerb + "_" + Language::getCurrentLanguage();
    saveDialog.selectFile(defaultName);

    int response = saveDialog.exec();
    if (response != QDialog::Accepted)
        return;

    QString filename = saveDialog.selectedFiles().first();

    if(!QString(".pdf|.odt|.htm").contains(filename.right(4))){
        QString selectedExtension = saveDialog.selectedNameFilter().right(5);
        selectedExtension.chop(1);
        filename += selectedExtension;
    }

    if(QFileInfo(filename).exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, Msg::fileExists(true), Msg::fileExists(false),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No)
            return;
    }

    Export * exporter = new Export();
    workfrm->initExporter(exporter);

    if (filename.endsWith(".pdf")){
        //exporter.exportPdf(filename);
        exporter->exportPdf(filename);
        return;
    }

    if (filename.endsWith(".odt")){
        exporter->exportOdf(filename);
        return;
    }

    if (filename.endsWith(".htm")){
        exporter->exportHtml(filename);
    }
}



void jpconjmain::doPrint()
{
    if (workfrm == NULL)
        return;

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    //dialog->setWindowTitle(tr("Print Document"));
    if (dialog->exec() != QDialog::Accepted)
        return;

    Export * exporter = new Export();
    workfrm->initExporter(exporter);
    exporter->print(&printer);
}



void jpconjmain::openHelp()
{
    if(!jpconjhelp::exists()){
        jpconjhelp* helpWindow = new jpconjhelp(this);
        helpWindow->show();
    }
}



void jpconjmain::zoom(signed char sign)
{
    workfrm->zoom(sign);

}




/*!
 * \brief jpconjmain::setCSS Set a user defined CSS to the QWebView
 * \param webView The QWebView we want to set the content CSS.
 * \param nameCSS The name of the CSS located in <dataFolder>/styles/ with the extension ".css"
 */
void jpconjmain::setCSS(QWebView * webView, QString nameCSS)
{
    QString cssfile = "file:" + QDir(QString(dataFolder)).absolutePath() + "/styles/" + nameCSS;
    QWebSettings * settings = webView->settings();
    settings->setUserStyleSheetUrl(QUrl(cssfile));
}



/*!
 * \brief jpconjmain::setHTMLDirection Set the direction of the webView body.
 */
void jpconjmain::setHTMLTranslation(bool rtl)
{

    if (!languageChanged)
        return;

    workfrm->refreshLanguage(rtl);

    languageChanged = false;
}



void jpconjmain::createTryIcon()
{
    //System tray Icon
    QAction *actionHelpContent = ui->actionHelpContent;
    trayIconSys->addAction(actionHelpContent);
    QAction *actionClose = ui->actionClose;
    trayIconSys->addAction(actionClose);
    trayIconSys->hideMain();

}

/*******************************************************
 *                    PROTECTED
 *******************************************************/

/*!
 * \brief jpconjmain::changeEvent The event treated here is the change of language.
 * \param event
 */
void jpconjmain::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        //Msg::updateMsg();
        ui->retranslateUi(this);
        bool rtl=Language::mainWindowDirection(this);
        languageChanged = true;
        setHTMLTranslation(rtl);
        actionShow->setText(tr("Show"));
        //qDebug()<< "changed";
    }
    QMainWindow::changeEvent(event);
}


void jpconjmain::closeEvent(QCloseEvent *event)
{
    //trayIcon->hideMain();
    createTryIcon();
    event->ignore();
    //qApp->quit();

}

/*******************************************************
 *                   PRIVATE SLOTS
 *******************************************************/

void jpconjmain::changeStyle(QString styleID)
{
    stylesheet = styleID + ".css";
    workfrm->changeStyle(styleID);
}

void jpconjmain::workfrmOpen()
{
    ui->actionExportResult->setEnabled(true);
    ui->actionPrint->setEnabled(true);
}

void jpconjmain::workfrmClose()
{
    ui->actionExportResult->setEnabled(false);
    ui->actionPrint->setEnabled(false);
}

void jpconjmain::newVerb(QString verb)
{
    currentVerb = verb;
}

void jpconjmain::on_actionClose_triggered()
{
    qApp->quit();
}


void jpconjmain::on_actionAbout_triggered()
{
    openAbout();
}

void jpconjmain::on_actionPreference_triggered()
{
    openPref();
}

void jpconjmain::on_actionHelpContent_triggered()
{
    openHelp();
}



void jpconjmain::on_actionExportResult_triggered()
{
    doExport();
}

void jpconjmain::on_actionPrint_triggered()
{
    doPrint();
}

void jpconjmain::on_actionZoomIn_triggered()
{
    zoom(1);
}

void jpconjmain::on_actionZoomOut_triggered()
{
    zoom(-1);
}

void jpconjmain::on_actionNormalSize_triggered()
{
    zoom(0);
}

void jpconjmain::on_actionHide_triggered()
{
    createTryIcon();
}

void jpconjmain::on_actionContactUs_triggered()
{
    QDesktopServices::openUrl(QUrl("mailto:dzcoding@googlegroups.com"));
}

void jpconjmain::on_actionHomePage_triggered()
{
    QDesktopServices::openUrl(QUrl("http://japkatsuyou.sourceforge.net"));
}
