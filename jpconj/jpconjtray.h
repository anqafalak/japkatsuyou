#ifndef JPCONJTRAY_H
#define JPCONJTRAY_H

#include <QApplication>
#include <QIcon>
#include <QInputContext>
#include <QObject>
#include <QPoint>
#include <QMenu>
#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>


class JpconjTray: public QSystemTrayIcon
{
    Q_OBJECT

public:
    JpconjTray(QMainWindow *parent);
    ~JpconjTray();
    void hideMain();

    static void setConfigTraySettings(QMap<QString, bool> traySettings);
    static bool getConfigTraySetting(QString traySetting);
    void addSeparator();
    void addAction(QAction* action);


private:
    QMenu *trayMenu;
    QMainWindow* mainWindow;

private slots:
    void showMain();
    void showMain(QSystemTrayIcon::ActivationReason reason);
};

#endif // JPCONJTRAY_H
