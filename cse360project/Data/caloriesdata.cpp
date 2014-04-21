#include "caloriesdata.h"

CaloriesData::CaloriesData() :
    PhysicalActivityData()
{
    _type = CaloriesType;
}

CaloriesData::CaloriesData(int calories) :
    PhysicalActivityData()
{
    setCalories(calories);
}

CaloriesData::CaloriesData(PhysicalActivityData data, int calories) : PhysicalActivityData(data)
{
    setCalories(calories);
}

QString CaloriesData::toString()
{
    return PhysicalActivityData::toString() + " | Calories: " + QString::number(calories());
}

QDataStream &operator<<(QDataStream &out, const CaloriesData &data)
{
    out << data.recordedDate();
    out << data.calories();
    return out;
}

QDataStream &operator>>(QDataStream &in, CaloriesData &data)
{
    PhysicalActivityData read;
    int calories;
    in >> read >> calories;

    data.setCalories(calories);
    data.setRecordedDate(read.recordedDate());

    return in;
}
