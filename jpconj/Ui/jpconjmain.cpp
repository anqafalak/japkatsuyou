/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013-2016  AnqaFalak group
    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>

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
    ui->menu_View->addAction(ui->example->toggleViewAction());
    //ui->menu_View->addAction(ui->search->toggleViewAction());
    //ui->showt->setLayoutDirection(Qt::LeftToRight);

    //changeStyle(Style::getCurrentStyle());
    Style::addReceiver(this, SLOT(changeStyle(QString)));
    Style::loadStyles();
    Style::addFontReceiver(this, SLOT(changeFont(QString,QString,int,int)));
    Style::setFont();

    connect(workfrm, SIGNAL(open()), this, SLOT(workfrmOpen()));
    connect(workfrm, SIGNAL(close()), this, SLOT(workfrmClose()));
    connect(workfrm, SIGNAL(newVerb(QString)), this, SLOT(newVerb(QString)));
    //tray Icon
    trayIconSys = new JpconjTray(this);

    actionShow = new QAction(tr("Show"), this); //qApp->translate, "jpconjmain"


    connect(actionShow, SIGNAL(triggered()), trayIconSys, SLOT(showMain()));
    trayIconSys->addAction(actionShow);
    trayIconSys->addSeparator();

    //Init examples
    QPalette palette;

    //hasContent = false;
    palette.setBrush(QPalette::Base, Qt::transparent);
    ui->expView->page()->setPalette(palette);
    ui->expView->setAttribute(Qt::WA_OpaquePaintEvent, false);

    Icona::addReceiver(this, SLOT(changeIcons()));
    Icona::setIcons();
}


void jpconjmain::doExamples()
{
    if (ui->example->isVisible()){

        Tatoeba tatoeba;
        QList<Tatoeba::Exp> examples = tatoeba.find(currentVerb, Language::getCurrentLanguage());
        //QList<Exp> examples = tatoeba.find(currentVerb, "eng");
        QString result = "<!doctype html>\n";
        result += "<html>\n";
        result += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" />\n";
        result += "<style>\n";
        result += ".lan {font-family:" + Style::getCurrentFont(false) + ";";
        result += "font-size:" + QString::number(Style::getCurrentFontSize(false)) + "pt;}\n";
        result += ".jp {font-family:" + Style::getCurrentFont(true);
        result += "; font-size :" + QString::number(Style::getCurrentFontSize(true)) + "pt;}\n";
        result += "\n</style>\n";
        result += "<body>\n";

        foreach(Tatoeba::Exp example, examples){
            result += "<table width=\"100%\">\n";
            result += "<tr><td class=\"title_odd jp\">" + example.jap + "</td></tr>\n";
            bool even = true;
            foreach(QString trans, example.lang){
                if (even)
                    result += "<tr><td class=\"row1 col_even lan\">\n";
                else
                    result += "<tr><td class=\"row2 col_odd lan\">\n";
                result += trans + "\n</td></tr>\n";

                even = ! even;
            }
            result += "</table>\n";
            result += "<div style=\"height: 1em;\"></div>\n";
        }

        result += "</body>\n</html>";

        ui->expView->setHtml(result);

    }
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
 * \brief jpconjmain::doExport Used to export the result content as pdf, odt, etc.
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
    exportExamples(exporter);


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

/*!
 * \brief jpconjmain::exportExamples function used to export the examples from the
 * example web viewer, using a given exporter
 * \param exporter the exporter which is used to create the exported content.
 */
void jpconjmain::exportExamples(Export * exporter)
{

    if(Export::getConfigExportPart("examples")){
        exporter->addContent("<p><h2>" + ui->example->windowTitle() + "</h2></p>\n");
        QString data = ui->expView->page()->mainFrame()->findFirstElement("body").toOuterXml();
        exporter->addContent(data);
    }
}


/*!
 * \brief jpconjmain::doPrint
 */
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


/*!
 * \brief jpconjmain::openHelp
 */
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

void jpconjmain::changeExamplesFont(QString font, QString jpfont, int size, int jpsize)
{
    QString style = ".lan {font-family:" + font;
    style += "; font-size :" + QString::number(size) + "pt;}\n";

    style += ".jp {font-family:" + jpfont;
    style += "; font-size :" + QString::number(jpsize) + "pt;}";

    QWebElement expEl = ui->expView->page()->mainFrame()->findFirstElement("style");
    expEl.setInnerXml(style);

}

void jpconjmain::changeUiIcons()
{
    ui->actionAbout->setIcon(Icona::getIcon("about"));
    ui->actionClose->setIcon(Icona::getIcon("close"));
    ui->actionContactUs->setIcon(Icona::getIcon("mail"));
    ui->actionExportResult->setIcon(Icona::getIcon("export"));
    ui->actionHelpContent->setIcon(Icona::getIcon("help"));
    ui->actionHide->setIcon(Icona::getIcon("hide"));
    ui->actionHomePage->setIcon(Icona::getIcon("home"));
    ui->actionNormalSize->setIcon(Icona::getIcon("zoom1"));
    ui->actionPreference->setIcon(Icona::getIcon("pref"));
    ui->actionPrint->setIcon(Icona::getIcon("print"));
    ui->actionZoomIn->setIcon(Icona::getIcon("zoom+"));
    ui->actionZoomOut->setIcon(Icona::getIcon("zoom"));

    ui->menuZoom->setIcon(Icona::getIcon("zoom"));

    actionShow->setIcon(Icona::getIcon("show"));
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
    setCSS(ui->expView, stylesheet);
    //qDebug()<< "style changed";
}

void jpconjmain::changeFont(QString font, QString jpfont, int size, int jpsize)
{
    workfrm->changeFont(font, jpfont, size, jpsize);
    changeExamplesFont(font, jpfont, size, jpsize);
}

void jpconjmain::changeIcons()
{
    changeUiIcons();
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
    doExamples();
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
