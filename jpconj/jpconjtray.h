#ifndef JPCONJTRAY_H
#define JPCONJTRAY_H

#include <QApplication>
#include <QIcon>
#include <QMenu>
#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>

class JpconjTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    JpconjTray(QMainWindow *parent);
    ~JpconjTray();

    void addAction(QAction* action);
    void hideMain();

    static void setConfigTraySettings(QMap<QString, bool> traySettings);
    static bool getConfigTraySetting(QString traySetting);


private:
    QMenu *trayMenu;
    QMainWindow* mainWindow;

private slots:
    void showMain();
    void showMain(QSystemTrayIcon::ActivationReason reason);
};

#endif // JPCONJTRAY_H
