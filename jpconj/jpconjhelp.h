#ifndef HELP_H
#define HELP_H

#include "helpviewer.h"

#include <QDebug>
#include <QMainWindow>
#include <QHelpEngine>
#include <QHelpContentWidget>
#include <QHelpIndexWidget>
#include <QFile>
#include <QStringList>
#include <QWebFrame>

namespace Ui {
class jpconjhelp;
}

class jpconjhelp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit jpconjhelp(QWidget *parent = 0);
    ~jpconjhelp();
    
private slots:
    void on_actionClose_triggered();
    void loadPage(const QUrl &url);
    void loadPage(const QUrl &url, const QString & keyword);

    void on_indexInput_textEdited(const QString &arg1);

private:
    Ui::jpconjhelp *ui;

    QHelpEngine *helpEngine;
    HelpViewer *helpViewer;

    void Init();

signals:
    void indexInputChanged( const QString & filter, const QString & wildcard = QString());
};

#endif // HELP_H
