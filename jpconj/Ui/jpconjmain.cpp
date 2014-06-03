/*
    This file is part of JapKatsuyou project; an application that provide
    Japanese verb conjugation

    Copyright (C) 2013  Abdelkrime Aries <kariminfo0@gmail.com>
    Copyright (C) 2013  DzCoding group (JapKatsuyou team)

    Authors:
            Abdelkrime Aries <kariminfo0@gmail.com>
            Zakaria Smahi <zakaria08esi@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

    conjFrame* conjfrm = new conjFrame(this);
    ui->formLayout->addWidget(conjfrm);
    rtl = false;
    hasContent = false;
    languageChanged = true;
    verbType = _v0;
    currentVerb = "";

    //qDebug()<< QString(VERSION);
    Language::loadTranslations();
    rtl = Language::mainWindowDirection(this);

    ui->menu_View->addAction(ui->mainTool->toggleViewAction());
    ui->menu_View->addAction(ui->zoomTool->toggleViewAction());
    //ui->menu_View->addAction(ui->search->toggleViewAction());
    //ui->showt->setLayoutDirection(Qt::LeftToRight);

    //changeStyle(Style::getCurrentStyle());
    Style::addReceiver(this, SLOT(changeStyle(QString)));
    Style::loadStyles();
    //connect(style, SIGNAL(styleChanged(QString)), this, SLOT(changeStyle(QString)));


    //tray Icon
    trayIconSys = new JpconjTray(this);

    actionShow = new QAction(tr("Show"), this); //qApp->translate, "jpconjmain"
    actionShow->setIcon(QIcon(":/img/show.png"));

    connect(actionShow, SIGNAL(triggered()), trayIconSys, SLOT(showMain()) );
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
/*
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

    Export exporter = initExporter();

    if (filename.endsWith(".pdf")){
        //exporter.exportPdf(filename);
        exporter.exportPdf(filename);
        return;
    }

    if (filename.endsWith(".odt")){
        exporter.exportOdf(filename);
        return;
    }

    if (filename.endsWith(".htm")){
        exporter.exportHtml(filename);
    }*/
}



void jpconjmain::doPrint()
{
    /*QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    //dialog->setWindowTitle(tr("Print Document"));
    if (dialog->exec() != QDialog::Accepted)
        return;

    Export exporter = initExporter();

    exporter.print(&printer);*/
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
    /*if (sign < 0){
        ui->standardConj->setTextSizeMultiplier(qMax(0.5, ui->standardConj->textSizeMultiplier() - 1.0 / 10.0));
        ui->basicConj->setTextSizeMultiplier(qMax(0.5, ui->basicConj->textSizeMultiplier() - 1.0 / 10.0));
        ui->complexConj->setTextSizeMultiplier(qMax(0.5, ui->complexConj->textSizeMultiplier() - 1.0 / 10.0));

        return;
    }

    if (sign > 0){
        ui->standardConj->setTextSizeMultiplier(qMin(2.5,ui->standardConj->textSizeMultiplier() + 1.0 / 10.0));
        ui->basicConj->setTextSizeMultiplier(qMin(2.5, ui->basicConj->textSizeMultiplier() + 1.0 / 10.0));
        ui->complexConj->setTextSizeMultiplier(qMin(2.5, ui->complexConj->textSizeMultiplier() + 1.0 / 10.0));

        return;
    }

    ui->standardConj->setTextSizeMultiplier(1.0);
    ui->basicConj->setTextSizeMultiplier(1.0);
    ui->complexConj->setTextSizeMultiplier(1.0);*/
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
void jpconjmain::setHTMLTranslation()
{
    /*
    if (!hasContent)
        return;

    //ui->verbType->setText(Msg::getVerbTypeDesc(verbType));

    if (!languageChanged)
        return;

    QString jsScript = "var body = document.getElementsByTagName('body')[0]; \n";
    QString dir = (rtl)?"rtl":"ltr";
    jsScript += "body.dir = \"" + dir + "\";";

    //ui->standardConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    //it is better for standard conjugation to stay ltr
    ui->basicConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);
    //qDebug()<< jsScript;

    //Retranslate strings

    {//standard
        QWebElementCollection standardConjConst = ui->standardConj->page()->mainFrame()->findAllElements(".Const");

        for(int i = 0; i < standardConjConst.count(); i++){
            QWebElement element = standardConjConst.at(i);
            QString elementName = element.attribute("name", "");
            element.setInnerXml(Msg::getTranslatedString(elementName));
        }
    }

    {//basic
        QWebElementCollection basicConjConst = ui->basicConj->page()->mainFrame()->findAllElements(".Const");

        for(int i = 0; i < basicConjConst.count(); i++){
            QWebElement element = basicConjConst.at(i);
            QString elementName = element.attribute("name", "");
            element.setInnerXml(Msg::getTranslatedString(elementName));
        }

        QMap<KForm, QString> basicForms = Msg::basicFormsMap();
        QWebElement element_basic;
        foreach (KForm form, basicForms.keys()){
            QString elementId = basicForms.value(form);
            element_basic = ui->basicConj->page()->mainFrame()->findFirstElement("#_Name_" + elementId);
            element_basic.setInnerXml(Msg::getBasicFormName(form));
        }
    }

    //complexConj

    QWebElementCollection complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Form\"]");
    for(int i = 0; i < complexConjConst.count(); i++)
        complexConjConst.at(i).setInnerXml(Msg::getTranslatedString("_Form"));

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Polite\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolitenessName(_Polite));
        element.setAttribute("title", Msg::getVerbPolitenessDesc(_Polite));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Plain\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolitenessName(_Plain));
        element.setAttribute("title", Msg::getVerbPolitenessDesc(_Plain));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Affirmative\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolarityName(_Affirmative));
        element.setAttribute("title", Msg::getVerbPolarityDesc(_Affirmative));
    }

    complexConjConst = ui->complexConj->page()->mainFrame()->findAllElements("[name=\"_Negative\"]");
    for(int i = 0; i < complexConjConst.count(); i++){
        QWebElement element = complexConjConst.at(i);
        element.setInnerXml(Msg::getVerbPolarityName(_Negative));
        element.setAttribute("title", Msg::getVerbPolarityDesc(_Negative));
    }

    QMap<CForm, QString> complexForms = Msg::complexFormsMap();
    QWebElement element_complex;
    foreach (CForm form, complexForms.keys()){
        QString elementId = complexForms.value(form);

        element_complex = ui->complexConj->page()->mainFrame()->findFirstElement("#_Form_" + elementId);
        element_complex.setInnerXml(Msg::getVerbFormName(form));
        element_complex.setAttribute("title", Msg::getVerbFormDesc(form));
    }
    //qDebug()<< jsScript;
    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);

    //qDebug()<< "Strings translation";
    languageChanged = false;
*/
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
        rtl=Language::mainWindowDirection(this);
        languageChanged = true;
        setHTMLTranslation();
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
    //qDebug() << "style changed" << styleID;
    /*setCSS(ui->basicConj, stylesheet);
    setCSS(ui->standardConj, stylesheet);
    setCSS(ui->complexConj, stylesheet);*/
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
    //doExport();
}

void jpconjmain::on_actionPrint_triggered()
{
    //doPrint();
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
