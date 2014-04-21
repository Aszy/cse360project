#include "data.h"

Data::Data()
{
    _type = NoneType;
}

QList<Data *> Data::repository = QList<Data *>();

QString Data::toString()
{
    return "Type: " + Data::typeToString(type()) + " | Recorded Date: " + recordedDate().toString();
}

QDataStream &operator<<(QDataStream &out, const Data &data)
{
    out << data.recordedDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, Data &data)
{
    QDate date;
    in >> date;

    data.setRecordedDate(date);

    return in;
}

QDataStream &operator<<(QDataStream &out, const DataType &data)
{
    out << (qint32&)data;
    return out;
}

QDataStream &operator>>(QDataStream &in, DataType &data)
{
    in >> (qint32&)data;
    return in;
}
