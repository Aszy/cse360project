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
    return PhysicalActivityData::toString() + " | Strength Workout Time: " + QString::number(workoutTime(), 'f', 1);
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
