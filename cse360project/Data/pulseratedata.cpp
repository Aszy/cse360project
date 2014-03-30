#include "pulseratedata.h"

PulseRateData::PulseRateData() :
    HealthData()
{

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

QString PulseRateData::type() const
{
    return "PulseRateData";
}

QString PulseRateData::toString()
{
    return HealthData::toString() + " | Pulse Rate: " + QString::number(pulseRate());
}

QDataStream &operator<<(QDataStream &out, const PulseRateData &data)
{
    out << ((HealthData)data).recordedDate();
    out << data.pulseRate();
    return out;
}

QDataStream &operator>>(QDataStream &in, PulseRateData &data)
{
    HealthData read;
    int rate;
    in >> read >> rate;

    data = PulseRateData(read, rate);

    return in;
}
