#ifndef CONJFRAME_H
#define CONJFRAME_H

#include "UiHelper/export.h"
#include "Conj/edict2.h"
#include "UiHelper/msg.h"
#include "UiHelper/funcframe.h"
#include "Ui/preference.h"
#include "jpconj.h"
#include <QWebElement>
#include <QWebFrame>


namespace Ui {
class ConjFrame;
}

class ConjFrame : public FuncFrame
{
    Q_OBJECT
    
public:
    explicit ConjFrame(QWidget *parent = 0);
    ~ConjFrame();

    void initExporter(Export exporter);
    void doConj();
    virtual void zoom(signed char sign);
    virtual void refreshLanguage(bool rtl);
    virtual void changeStyle(QString styleID);


protected:
    virtual void initUI();
    virtual void initExporter();
    
private slots:
    void on_conjugateButton_clicked();
    void on_inputConjVerb_returnPressed();

private:
    Ui::ConjFrame *ui;


    //bool languageChanged;
    EdictType verbType;
    QString currentVerb;

    void basicConjugation(QString verb, EdictType type);
    void complexConjugation(QString verb, EdictType type);

    QString readHtmlFile(QString URL);
};

#endif // CONJFRAME_H
