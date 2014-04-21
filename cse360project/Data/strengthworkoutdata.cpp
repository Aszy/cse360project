#include "strengthworkoutdata.h"

StrengthWorkoutData::StrengthWorkoutData() :
    PhysicalActivityData()
{
    _type = StrengthWorkoutType;
}

StrengthWorkoutData::StrengthWorkoutData(float workoutTime) :
    PhysicalActivityData()
{
    setWorkoutTime(workoutTime);
}

StrengthWorkoutData::StrengthWorkoutData(PhysicalActivityData data, float workoutTime) : PhysicalActivityData(data)
{
    setWorkoutTime(workoutTime);
}

QString StrengthWorkoutData::toString()
{
    return PhysicalActivityData::toString() + " | Sleep Amount: " + QString::number(workoutTime());
}

QDataStream &operator<<(QDataStream &out, const StrengthWorkoutData &data)
{
    out << data.recordedDate();
    out << data.workoutTime();
    return out;
}

QDataStream &operator>>(QDataStream &in, StrengthWorkoutData &data)
{
    PhysicalActivityData read;
    float workoutTime;
    in >> read >> workoutTime;

    data.setWorkoutTime(workoutTime);
    data.setRecordedDate(read.recordedDate());

    return in;
}
