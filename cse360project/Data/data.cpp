#include "data.h"

Data::Data()
{
}

QString Data::type() const
{
    return "Data";
}

QString Data::toString()
{
    return "Type: " + type() + " | Recorded Date: " + recordedDate().toString();
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

    data = Data();
    data.setRecordedDate(date);

    return in;
}
