#include "conjframe.h"
#include "ui_conjframe.h"

conjFrame::conjFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::conjFrame)
{
    ui->setupUi(this);
    Init();
}

conjFrame::~conjFrame()
{
    delete ui;
}


void conjFrame::Init()
{
    QPalette palette;
    palette.setBrush(QPalette::Base, Qt::transparent);
    ui->basicConj->page()->setPalette(palette);
    ui->basicConj->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->standardConj->page()->setPalette(palette);
    ui->standardConj->setAttribute(Qt::WA_OpaquePaintEvent, false);

    ui->complexConj->page()->setPalette(palette);
    ui->complexConj->setAttribute(Qt::WA_OpaquePaintEvent, false);
}

void conjFrame::initExporter(Export exporter)
{/*
    exporter.setRTL(rtl);
    exporter.addContent("<p><h1>" + currentVerb + "</h1></p><hr>\n");
    exporter.addContent("<p><h3>" + ui->verbType->text() + "</h3></p>\n");
    if(Export::getConfigExportPart("standard")){
        exporter.addContent("<p><h2>" + ui->ConjgTab->tabText(0) + "</h2></p>\n");
        QString data = ui->standardConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter.addContent(data);
    }
    if(Export::getConfigExportPart("basic")){
        exporter.addContent("<p><h2>" + ui->ConjgTab->tabText(1) + "</h2></p>\n");
        QString data = ui->basicConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter.addContent(data);
    }
    if(Export::getConfigExportPart("complex")){
        exporter.addContent("<p><h2>" + ui->ConjgTab->tabText(2) + "</h2></p>\n");
        QString data = ui->complexConj->page()->mainFrame()->findFirstElement("body").firstChild().toOuterXml();
        exporter.addContent(data);
    }

    if(Export::getConfigExportPart("styled"))
        exporter.setStyle(QDir(QString(dataFolder) + "styles/" + stylesheet).absolutePath());
*/
}



/*!
 * \brief conjFrame::doConj This function is used to show different conjugation forms
 *
 * This function search for the existance of the verb, using Edict2 module.
 * Then, it calls for:
 * - conjFrame::basicConjugation To show the standard and basic conjugation forms.
 * - conjFrame::complexConjugation To show the complex conjugation forms.
 */

void conjFrame::doConj()
{

    QString verb = ui->inputConjVerb->text();

    if (verb == currentVerb)
        return;

    Edict2 edict2;

    EdictType type = edict2.find(verb);



    if (type < 1){
        ui->verbType->setText(Msg::getVerbTypeDesc(type));
        //ui->actionExportResult->setEnabled(false);
        //ui->actionPrint->setEnabled(false);
        currentVerb = "";
        hasContent = false;
        ui->standardConj->setHtml("");
        ui->basicConj->setHtml("");
        ui->complexConj->setHtml("");

        return;
    }

    //ui->verbType->setText(Msg::getVerbTypeDesc(type));
    complexConjugation(verb, type);
    basicConjugation(verb, type);
    hasContent = true;
    currentVerb = verb;
    verbType = type;
    //setHTMLTranslation();

   // ui->actionExportResult->setEnabled(true);
    //ui->actionPrint->setEnabled(true);
}




/*!
 * \brief jpconjmain::basicConjugation Used to show the standard and basic conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
void conjFrame::basicConjugation(QString verb, EdictType type)
{
/*
    if (!hasContent){
        QString basicConjHTML = readHtmlFile(":/output/basicConj");
        QString standardConjHTML = readHtmlFile(":/output/standardConj");

        ui->standardConj->setHtml(standardConjHTML);
        ui->basicConj->setHtml(basicConjHTML);
    }


    //! [Doxygen: basicFormsMap example]
    QMap<KForm, QString> basicForms = Msg::basicFormsMap();
    QWebElement element_stem;
    QWebElement element_suffix;
    QWebElement element_basic;
    foreach (KForm form, basicForms.keys()){
        QStringList conj = JpConj::Katsuyou(verb, type, form).split("|");
        QString elementId = basicForms.value(form);

        element_stem = ui->standardConj->page()->mainFrame()->findFirstElement("#stem_" + elementId);
        element_suffix = ui->standardConj->page()->mainFrame()->findFirstElement("#suffix_" + elementId);
        element_stem.setInnerXml(conj[0]);
        element_suffix.setInnerXml(conj[1]);

        element_basic = ui->basicConj->page()->mainFrame()->findFirstElement("#basic_" + elementId);
        element_basic.setInnerXml(conj[0] + conj[1]);

    }*/
    //! [Doxygen: basicFormsMap example]

}



/*!
 * \brief jpconjmain::complexConjugation Used to show the complex conjugation forms.
 * \param verb The verb in dictionary form (u-form), eg. 食べる, 飲む, 行く, 来る, etc.
 * \param type The Edict2 type of the verb (See: VerbType::EdictType)
 */
void conjFrame::complexConjugation(QString verb, EdictType type)
{
    if (!hasContent){
        QString complexConjHTML = readHtmlFile(":/output/complexConj");
        ui->complexConj->setHtml(complexConjHTML);
    }

    QString jsScript="";
    QMap<CForm, QString> complexForms = Msg::complexFormsMap();
    foreach (CForm form, complexForms.keys()){

        QString elementId = complexForms.value(form);

        jsScript += "document.getElementById(\"PoA_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Polite, _Affirmative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PoN_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Polite, _Negative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PlA_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Plain, _Affirmative).remove("|") + "\";\n";

        jsScript += "document.getElementById(\"PlN_" + elementId + "\").innerHTML = \"";
        jsScript += JpConj::Conjugate(verb, type, form, _Plain, _Negative).remove("|") + "\";\n";
        //complexConjHTML.replace("&_Form_" + str, Msg::getVerbFormName(form));
        //complexConjHTML.replace("&_Tip_" + str, Msg::getVerbFormDesc(form));
    }

    ui->complexConj->page()->mainFrame()->evaluateJavaScript(jsScript);

}

/*!
 * \brief jpconjmain::readHtmlFile Reads an HTML file and return a QString
 * \param URL URL of the HTML file, we want to read.
 * \return A QString which is the content of this HTML file.
 */
QString conjFrame::readHtmlFile(QString URL)
{
    QString result="<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" /><body>";
    QFile HtmlFile(URL);

    if (HtmlFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream htmlStream(&HtmlFile);
        result = htmlStream.readAll();
    }

    result += "</body>";

    return result;
}

