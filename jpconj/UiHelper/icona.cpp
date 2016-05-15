#include "icona.h"

QKIcona *Icona::iconHelper = new QKIcona();
Icona *Icona::_instance = new Icona();
QString Icona::currentIcons = "";


Icona::Icona()
{

}

void Icona::signalIconsChanged()
{
    emit iconsChanged();
}

void Icona::setIcons()
{
    QString icons = getConfigIcons();
    if (icons != currentIcons){
        currentIcons = icons;
        _instance->signalIconsChanged();
    }
}

QString Icona::getConfigIcons()
{
    QSettings settings;

    return settings.value("icons", iconHelper->getDefaultStyle()).toString();
}

QString Icona::getCurrentIcons()
{
    return currentIcons;
}

void Icona::setConfigIcons(QString style)
{
    QSettings settings;
    settings.setValue("icons", style);
}

QMap<QString, QIcon> Icona::getAvailableIcons()
{
    return iconHelper->availableStyles();
}

void Icona::addReceiver(const QObject *receiver, const char *receiverSlot)
{
    connect(_instance, SIGNAL(iconsChanged()), receiver, receiverSlot);
}

QIcon Icona::getIcon(QString iconName)
{
    return iconHelper->getIcon(currentIcons, iconName);
}
