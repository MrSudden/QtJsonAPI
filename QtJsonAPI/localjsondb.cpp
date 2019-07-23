#include "localjsondb.h"

LocalJSONDB::LocalJSONDB(QString name, QCoreApplication* app, QObject *parent): QObject(parent),
    file(new QFile()), app(app)
{
    QDir mDir;
    QString appDirPath(app->applicationDirPath());
    appDirPath += "/AppData";
    mDir.mkdir(appDirPath);
    mDir.cd(appDirPath);
    QString fileName(appDirPath + "/" + name + ".json");
    file->setFileName(fileName);
}

LocalJSONDB::~LocalJSONDB()
{
    delete file;
}

QJsonValue LocalJSONDB::ref(QString path)
{
    Q_UNUSED(path);
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug().noquote() << "Error! Can't open file!!";
    }
    QJsonValue val = QJsonDocument::fromJson(file->readAll()).array();
    file->close();
    return val;
}
