#include "tatoeba.h"

Tatoeba::Tatoeba()
{
    connect();
}

QList<Tatoeba::Exp> Tatoeba::find(QString verb)
{
    QList<Tatoeba::Exp> result;


    return result;
}

void Tatoeba::connect()
{
    if (!QSqlDatabase::contains("dbexamples"))
    {
        verbdb =  QSqlDatabase::addDatabase("QSQLITE","dbexamples");
        verbdb.setDatabaseName(QString(dataFolder) + "DB/tatoeba.db" );
    }
    else
    {
        verbdb =  QSqlDatabase::database("dbexamples");
    }

}

void Tatoeba::desconnect()
{
    if (QSqlDatabase::contains("dbexamples"))
    {
        QSqlDatabase::removeDatabase("dbexamples");
    }
}
