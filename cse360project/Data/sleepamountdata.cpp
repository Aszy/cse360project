#include "sleepamountdata.h"

SleepAmountData::SleepAmountData() :
    PhysicalActivityData()
{
    _type = SleepAmountType;
}

SleepAmountData::SleepAmountData(float hours) :
    PhysicalActivityData()
{
    setHoursSlept(hours);
}

SleepAmountData::SleepAmountData(PhysicalActivityData data, float hours) : PhysicalActivityData(data)
{
    setHoursSlept(hours);
}

QString SleepAmountData::toString()
{
    return PhysicalActivityData::toString() + " | Sleep Amount: " + QString::number(hoursSlept(), 'f', 1);
}

QDataStream &operator<<(QDataStream &out, const SleepAmountData &data)
{
    out << data.recordedDate();
    out << data.hoursSlept();
    return out;
}

QDataStream &operator>>(QDataStream &in, SleepAmountData &data)
{
    PhysicalActivityData read;
    float hours;
    in >> read >> hours;

    data.setHoursSlept(hours);
    data.setRecordedDate(read.recordedDate());

    return in;
}
