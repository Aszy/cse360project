#include "cardioworkoutdata.h"

CardioWorkoutData::CardioWorkoutData() :
    PhysicalActivityData()
{
    _type = CardioWorkoutType;
}

CardioWorkoutData::CardioWorkoutData(float time, float distance) :
    PhysicalActivityData()
{
    setRunTime(time);
    setRunDistance(distance);
}

CardioWorkoutData::CardioWorkoutData(PhysicalActivityData data, float time, float distance) : PhysicalActivityData(data)
{
    setRunTime(time);
    setRunDistance(distance);
}

QString CardioWorkoutData::toString()
{
    return PhysicalActivityData::toString() + " | Cardio Workout, Time: " + QString::number(runTime()) + ", Distance: " + QString::number(runDistance());
}

QDataStream &operator<<(QDataStream &out, const CardioWorkoutData &data)
{
    out << data.recordedDate();
    out << data.runTime();
    out << data.runDistance();
    return out;
}

QDataStream &operator>>(QDataStream &in, CardioWorkoutData &data)
{
    PhysicalActivityData read;
    float time, distance;
    in >> read >> time >> distance;

    data.setRunTime(time);
    data.setRunDistance(distance);
    data.setRecordedDate(read.recordedDate());

    return in;
}
