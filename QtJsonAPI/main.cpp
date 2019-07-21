#include <QCoreApplication>
#include "localjsondb.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);\
    QString name("data");
    LocalJSONDB db(name, &app);

    return app.exec();
}
