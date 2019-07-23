#include <QCoreApplication>
#include "localjsondb.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    LocalJSONDB db("data", &app);

    return app.exec();
}
