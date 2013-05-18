#ifndef JPCONJMAIN_H
#define JPCONJMAIN_H

#include <QMainWindow>
#include <QTextEdit>
#include "ui_jpconjmain.h"
#include "QDebug"
#include "libjpconjlink.h"
#include "about.h"

namespace Ui {
class jpconjmain;
}

class jpconjmain : public QMainWindow
{
    Q_OBJECT

public slots:
    void openAbout();

public:
    explicit jpconjmain(QWidget *parent = 0);
    ~jpconjmain();
    
private slots:
    void on_action_Close_triggered();

    void on_actionSay_triggered();

    void on_btn_conj_clicked();

    void on_action_About_triggered();

private:
    Ui::jpconjmain *ui;
    About     *winAbout;
    void doInit();
    void doConj();
};

#endif // JPCONJMAIN_H
