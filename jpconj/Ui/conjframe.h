#ifndef CONJFRAME_H
#define CONJFRAME_H

#include "UiHelper/export.h"
#include "Conj/edict2.h"
#include "UiHelper/msg.h"
#include "Ui/preference.h"
#include "jpconj.h"
#include <QFrame>
#include <QWebElement>
#include <QWebFrame>

namespace Ui {
class conjFrame;
}

class conjFrame : public QFrame
{
    Q_OBJECT
    
public:
    explicit conjFrame(QWidget *parent = 0);
    ~conjFrame();

    void initExporter(Export exporter);
    void doConj();
    void zoom(signed char sign);
    void setHTMLTranslation();
    void changeStyle(QString styleID);
    void setCSS(QWebView * webView, QString nameCSS);
    
private slots:
    void on_conjugateButton_clicked();
    void on_inputConjVerb_returnPressed();

private:
    Ui::conjFrame *ui;

    bool rtl;
    bool hasContent;
    //bool languageChanged;
    EdictType verbType;
    QString currentVerb;
    QString stylesheet;

    void basicConjugation(QString verb, EdictType type);
    void complexConjugation(QString verb, EdictType type);



    void Init();
    QString readHtmlFile(QString URL);
};

#endif // CONJFRAME_H
