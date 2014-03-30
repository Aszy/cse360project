#include "healthdata.h"

HealthData::HealthData() :
    Data()
{
    _type = HealthType;
}

HealthData::HealthData(Data data) : Data()
{
    setRecordedDate(data.recordedDate());
}

QString HealthData::toString()
{
    return Data::toString();
}

QDataStream &operator<<(QDataStream &out, const HealthData &data)
{
    out << ((Data)data).recordedDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, HealthData &data)
{
    Data read;
    in >> read;

    data.setRecordedDate(read.recordedDate());

    return in;
}
