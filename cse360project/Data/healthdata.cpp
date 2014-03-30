#include "healthdata.h"

HealthData::HealthData() :
    Data()
{
}

HealthData::HealthData(Data data) : Data()
{
    setRecordedDate(data.recordedDate());
}

QString HealthData::type() const
{
    return "HealthData";
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

    data = HealthData(read);

    return in;
}
