#include "temperaturedata.h"

TemperatureData::TemperatureData() :
    HealthData()
{
    _type = TemperatureType;
}

TemperatureData::TemperatureData(float level) :
    HealthData()
{
    setTemperature(level);
}

TemperatureData::TemperatureData(HealthData data, float level) : HealthData(data)
{
    setTemperature(level);
}

QString TemperatureData::toString()
{
    return HealthData::toString() + " | Temperature: " + QString::number(temperature());
}

QDataStream &operator<<(QDataStream &out, const TemperatureData &data)
{
    out << data.recordedDate();
    out << data.temperature();
    return out;
}

QDataStream &operator>>(QDataStream &in, TemperatureData &data)
{
    HealthData read;
    float level;
    in >> read >> level;

    data.setTemperature(level);
    data.setRecordedDate(read.recordedDate());

    return in;
}
