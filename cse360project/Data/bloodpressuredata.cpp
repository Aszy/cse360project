#include "bloodpressuredata.h"

BloodPressureData::BloodPressureData() :
    HealthData()
{
    _type = BloodPressureType;
}

BloodPressureData::BloodPressureData(int systolic, int diastolic) :
    HealthData()
{
    setSystolicPressure(systolic);
    setDiastolicPressure(diastolic);
}

BloodPressureData::BloodPressureData(HealthData data, int systolic, int diastolic) : HealthData(data)
{
    setSystolicPressure(systolic);
    setDiastolicPressure(diastolic);
}

QString BloodPressureData::toString()
{
    return HealthData::toString() + " | Blood Pressure, Systolic: " + QString::number(systolicPressure()) + ", Diastolic: " + QString::number(diastolicPressure());
}

QDataStream &operator<<(QDataStream &out, const BloodPressureData &data)
{
    out << data.recordedDate();
    out << data.systolicPressure();
    out << data.diastolicPressure();
    return out;
}

QDataStream &operator>>(QDataStream &in, BloodPressureData &data)
{
    HealthData read;
    int systolic;
    int diastolic;
    in >> read >> systolic >> diastolic;

    data.setSystolicPressure(systolic);
    data.setDiastolicPressure(diastolic);
    data.setRecordedDate(read.recordedDate());

    return in;
}
