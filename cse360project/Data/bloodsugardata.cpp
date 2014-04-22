#include "bloodsugardata.h"

BloodSugarData::BloodSugarData() :
    HealthData()
{
    _type = BloodSugarType;
}

BloodSugarData::BloodSugarData(float level) :
    HealthData()
{
    setBloodSugar(level);
}

BloodSugarData::BloodSugarData(HealthData data, float level) : HealthData(data)
{
    setBloodSugar(level);
}

QString BloodSugarData::toString()
{
    return HealthData::toString() + " | Blood Sugar: " + QString::number(bloodSugar(), 'f', 1);
}

QDataStream &operator<<(QDataStream &out, const BloodSugarData &data)
{
    out << data.recordedDate();
    out << data.bloodSugar();
    return out;
}

QDataStream &operator>>(QDataStream &in, BloodSugarData &data)
{
    HealthData read;
    float level;
    in >> read >> level;

    data.setBloodSugar(level);
    data.setRecordedDate(read.recordedDate());

    return in;
}
