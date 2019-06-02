#ifndef JSONSTORAGE_H
#define JSONSTORAGE_H

#include <QObject>

class JsonStorage : public QObject
{
    Q_OBJECT
public:
    explicit JsonStorage(QObject *parent = nullptr);

signals:

public slots:
};

#endif // JSONSTORAGE_H
