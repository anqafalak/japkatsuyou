#ifndef TATOEBA_H
#define TATOEBA_H

#include <QList>
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

private:
    QSqlDatabase tatoebadb;
};

#endif // TATOEBA_H
