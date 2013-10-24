#include "jpconjtray.h"

JpconjTray::JpconjTray(QMainWindow* parent):
    QSystemTrayIcon(QIcon(":/img/icon.png"), 0)
{
    trayMenu = new QMenu();
    mainWindow = parent;
    this->setContextMenu(trayMenu);

    connect( this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
             this, SLOT(showMain(QSystemTrayIcon::ActivationReason)) );


    QAction *actionShow = new QAction(qApp->translate("jpconjmain", "Show"), this);
    actionShow->setIcon(QIcon(":/img/icon.png"));
    connect( actionShow, SIGNAL(triggered()), this, SLOT(showMain()) );
    trayMenu->addAction(actionShow);
    trayMenu->addSeparator();

}


JpconjTray::~JpconjTray()
{
}


void JpconjTray::addAction(QAction* action)
{
    //QAction* newAction = new QAction(action->icon(), action->text(), this);
    //connect(newAction, SIGNAL(triggered()), action, SLOT(trigger()) );

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
    show();
}


void JpconjTray::showMain()
{
    mainWindow->show();
    //mainWindow->activateWindow();
    //mainWindow->raise();
    //mainWindow->setFocus();
    hide();
}

void JpconjTray::showMain(QSystemTrayIcon::ActivationReason reason )
{
    if( reason )
        if( reason != QSystemTrayIcon::Trigger )
            return;

    showMain();
}
