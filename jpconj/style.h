#ifndef STYLE_H
#define STYLE_H

#include "paths.h"

#include <QCustomEvent>
#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QHash>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QStringList>

class Styleinfo
{
public:
    Styleinfo();
    QString name;
    QString author;
    QString date;
    QString desc;
};


class Style : public QObject
{
    Q_OBJECT

public:
    Style();
    void emitSignal(QString styleID);
    static void loadStyles();
    static QHash<QString, Styleinfo *> getStyleInfo();
    static void setStyle();
    static QString getConfigStyle();
    static QString getCurrentStyle();
    static void setConfigStyle(QString styleID);
    static void addReceiver(const QObject * receiver, const char * receiverSlot);

private:
    static QHash<QString, Styleinfo*> styles;
    static QString currentstyle;
    //static Style* getInstance();
    static Style* _instance;


signals:
    void styleChanged(QString styleID);
};

#endif // STYLE_H
