#ifndef ICONA_H
#define ICONA_H

#include "qkicona.h"

#include <QSettings>
#include <QIcon>


class Icona : public QObject
{
    Q_OBJECT

public:
    Icona();
    void signalIconsChanged();

    static void setIcons();
    static QString getConfigIcons();
    static QString getCurrentIcons();
    static void setConfigIcons(QString style);

    static QMap<QString, QIcon> getAvailableIcons();

    static void addReceiver(const QObject * receiver, const char * receiverSlot);

    static QIcon getIcon(QString iconName);

private:
    static QKIcona * iconHelper;
    static Icona * _instance;
    static QString currentIcons;

signals:
    void iconsChanged();
};

#endif // ICONA_H
