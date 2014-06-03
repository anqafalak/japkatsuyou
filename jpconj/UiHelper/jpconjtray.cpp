#include "jpconjtray.h"

JpconjTray::JpconjTray(QMainWindow* parent):
    QSystemTrayIcon(parent)
{
    mainWindow = parent;
    this->setIcon(QIcon(":/img/icon.png"));

    trayMenu = new QMenu();
    this->setContextMenu(trayMenu);

    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(showMain(QSystemTrayIcon::ActivationReason)) );
}



JpconjTray::~JpconjTray()
{
}


void JpconjTray::addAction(QAction* action)
{
    trayMenu->addAction(action);
}



void JpconjTray::setConfigTraySettings(QMap<QString, bool> traySettings)
{
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("SysTray");
    foreach (QString settingName, traySettings.keys())
        settings.setValue(settingName, traySettings.value(settingName));
    settings.endGroup();

}



bool JpconjTray::getConfigTraySetting(QString traySetting)
{
    bool result;
    QSettings settings;//("DzCoding", "JapKatsuyou")
    settings.beginGroup("SysTray");
    result = settings.value(traySetting, true).toBool();
    settings.endGroup();

    return result;
}



void JpconjTray::hideMain()
{
    mainWindow->hide();
    this->show();
}



void JpconjTray::showMain()
{
    mainWindow->show();
    this->hide();
}



void JpconjTray::addSeparator()
{

    trayMenu->addSeparator();

}


void JpconjTray::showMain(QSystemTrayIcon::ActivationReason reason )
{
    if( reason )
        if( reason != QSystemTrayIcon::Trigger )
            return;

    showMain();
}
