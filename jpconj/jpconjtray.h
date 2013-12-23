#ifndef JPCONJTRAY_H
#define JPCONJTRAY_H

#include <QApplication>
#include <QIcon>
#include <QInputContext>
#include <QObject>
#include <QMenu>
#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>


class JpconjTray:QObject
{
    Q_OBJECT

public:
    JpconjTray(QMainWindow *parent);
    ~JpconjTray();

    void addAction(QAction* action);
    void hideMain();

    static void setConfigTraySettings(QMap<QString, bool> traySettings);
    static bool getConfigTraySetting(QString traySetting);
    void initiateMenu();


private:
    QMenu *trayMenu;
    QMainWindow* mainWindow;
    QSystemTrayIcon * trayIcon;

private slots:
    void showMain();
    void showMain(QSystemTrayIcon::ActivationReason reason);
};

#endif // JPCONJTRAY_H
