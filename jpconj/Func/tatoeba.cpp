#include "tatoeba.h"

Tatoeba::Tatoeba()
{
    connect();
}

QList<Tatoeba::Exp> Tatoeba::find(QString verb, QString lang)
{
    QList<Tatoeba::Exp> result;
    //tatoebadb

    QString radical = verb;
    radical.chop(1);

    if (tatoebadb.open()) {
        //qDebug() << "DB connected";
        QSqlQuery query(tatoebadb);
        QString req;
        req = "SELECT * FROM jpn WHERE LIKE \"%" + radical + "%\";";
        query.exec(req);
        QSqlRecord record = query.record();
        int idIdx = record.indexOf("id");
        int sentIdx = record.indexOf("sent");
        if (query.next()) {
            int id = query.value(idIdx).toInt();
            QString JPsent = query.value(sentIdx).toString();
            //query.clear();
            //query.finish();
            QSqlQuery query2(tatoebadb);
            req = "SELECT sent FROM " + lang + ", links\n";
            req += "WHERE links.jpnId = " + QString::number(id) + "\n";
            req += "AND links.id = " + lang + ".id";

            query2.exec(req);

            QList<QString> langTrans;

            while (query2.next()){
                QString langSent = query2.value(0).toString();
                langTrans.append(langSent);
            }

            Tatoeba::Exp example;
            example.jap = JPsent;
            example.lang = langTrans;

            result.append(example);
            //qDebug() << "Verb kanji found" << result;
        }

    } else {
        //qDebug() << "DB not connecting";
    }
    //qDebug() << result;
    tatoebadb.close();

    return result;
}

void Tatoeba::connect()
{
    if (!QSqlDatabase::contains("dbexamples"))
    {
        tatoebadb =  QSqlDatabase::addDatabase("QSQLITE","dbexamples");
        tatoebadb.setDatabaseName(QString(dataFolder) + "DB/tatoeba.db" );
    }
    else
    {
        tatoebadb =  QSqlDatabase::database("dbexamples");
    }

}

void Tatoeba::desconnect()
{
    if (QSqlDatabase::contains("dbexamples"))
    {
        QSqlDatabase::removeDatabase("dbexamples");
    }
}
