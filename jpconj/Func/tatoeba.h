#ifndef TATOEBA_H
#define TATOEBA_H

#include <QList>
#include <QMap>
#include <QDebug>
#include <QtSql/QtSql>

class Tatoeba
{
public:
    struct Exp {
            QString jap;
            QList<QString> lang;
    };

    Tatoeba();

    QList<Exp> find (QString verb, QString lang);
    void connect();
    void desconnect();

    static QString convertLang(QString lang);

private:
    QSqlDatabase tatoebadb;
};

#endif // TATOEBA_H
