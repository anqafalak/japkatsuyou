#include "jpconjtray.h"

JpconjTray::JpconjTray(QMainWindow* parent):
    QObject(parent)
{
    trayIcon = 0;
    trayMenu = 0;
    mainWindow = parent;
    initiateMenu();
}

JpconjTray::~JpconjTray()
{
}


void JpconjTray::addAction(QAction* action)
{
    //QAction* newAction = new QAction(action->icon(), action->text(), this);
    //connect(newAction, SIGNAL(triggered()), action, SLOT(trigger()) );
    if (trayMenu)
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
    if (! trayIcon){
        trayIcon = new QSystemTrayIcon(QIcon(":/img/icon.png"), this);
        trayIcon->setContextMenu(trayMenu);

        connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                 this, SLOT(showMain(QSystemTrayIcon::ActivationReason)) );
    }

    mainWindow->hide();
    trayIcon->show();
}



void JpconjTray::showMain()
{
    mainWindow->show();
    //mainWindow->activateWindow();
    //mainWindow->raise();
    //mainWindow->setFocus();
    //hide();

    //delete trayMenu;
    trayIcon->hide();
    //delete trayIcon;
    //trayIcon = 0;
    //initiateMenu();
}



void JpconjTray::initiateMenu()
{
    if (trayMenu)
        delete trayMenu;
    trayMenu = new QMenu();
    QAction *actionShow = new QAction(qApp->translate("jpconjmain", "Show"), this);
    actionShow->setIcon(QIcon(":/img/show.png"));
    connect( actionShow, SIGNAL(triggered()), this, SLOT(showMain()) );
    trayMenu->addAction(actionShow);
    trayMenu->addSeparator();

}



void JpconjTray::showMain(QSystemTrayIcon::ActivationReason reason )
{
    if( reason )
        if( reason != QSystemTrayIcon::Trigger )
            return;

    showMain();
}
