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
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug().noquote() << "Error! Can't open file!!";
    }

    root = QJsonDocument::fromJson(file->readAll()).array();
    Q_UNUSED(file->resize(0));
}

LocalJSONDB::~LocalJSONDB()
{
    delete file;
}
