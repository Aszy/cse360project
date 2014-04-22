#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "data.h"
#include <QDataStream>
#include <QList>

class Serializer
{
private:
    Serializer();

public:
    static void serialize(QDataStream &stream, QList<Data *> &list);
    static void deserialize(QDataStream &stream, QList<Data *> &list);
};

#endif // SERIALIZER_H
