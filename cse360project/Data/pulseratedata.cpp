#include "pulseratedata.h"

PulseRateData::PulseRateData() :
    HealthData()
{
    _type = PulseRateType;
}

PulseRateData::PulseRateData(int rate) :
    HealthData()
{
    setPulseRate(rate);
}

PulseRateData::PulseRateData(HealthData data, int rate) : HealthData(data)
{
    setPulseRate(rate);
}

QString PulseRateData::toString()
{
    return HealthData::toString() + " | Pulse Rate: " + QString::number(pulseRate());
}

QDataStream &operator<<(QDataStream &out, const PulseRateData &data)
{
    out << data.recordedDate();
    out << data.pulseRate();
    return out;
}

QDataStream &operator>>(QDataStream &in, PulseRateData &data)
{
    HealthData read;
    int rate;
    in >> read >> rate;

    data.setPulseRate(rate);
    data.setRecordedDate(read.recordedDate());

    return in;
}
