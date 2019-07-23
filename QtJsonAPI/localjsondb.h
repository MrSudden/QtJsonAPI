#ifndef LOCALJSONDB_H
#define LOCALJSONDB_H

#include <QObject>                          //This class is the base class of all Qt objects.
#include <QDebug>                           //Class that provides an output stream for debugging information.
#include <QDir>                             //Class that provides access to directory structures and their contents.
#include <QFile>                            //Class that provides an interface for reading from and writing to files.
#include <QTextStream>                      //Class that provides a convenient interface for reading and writing text.
#include <QJsonArray>                       //Class that encapsulates a JSON array.
#include <QJsonDocument>                    //Class that provides a way to read and write JSON documents.
#include <QJsonObject>                      //Class that encapsulates a JSON object.
#include <QJsonValue>                       //Class that encapsulates a value in JSON.
#include <QCoreApplication>                 //Class that instantiates an application.

class LocalJSONDB : public QObject
{
    Q_OBJECT
public:
    explicit LocalJSONDB(QString name = QString(), QCoreApplication *app = nullptr, QObject *parent = nullptr);
    ~LocalJSONDB();

    QJsonValue ref(QString path = QString());

signals:

public slots:

private:
    QFile* file;
    QCoreApplication* app;
    QJsonArray root;
};

#endif // LOCALJSONDB_H
