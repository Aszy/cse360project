#include "physicalactivitydata.h"

PhysicalActivityData::PhysicalActivityData() :
    Data()
{
    _type = PhysicalActivityType;
}

PhysicalActivityData::PhysicalActivityData(Data data) : Data()
{
    setRecordedDate(data.recordedDate());
}

QString PhysicalActivityData::toString()
{
    return Data::toString();
}

QDataStream &operator<<(QDataStream &out, const PhysicalActivityData &data)
{
    out << ((Data)data).recordedDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, PhysicalActivityData &data)
{
    Data read;
    in >> read;

    data.setRecordedDate(read.recordedDate());

    return in;
}
