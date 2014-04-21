#include "workhoursdata.h"

WorkHoursData::WorkHoursData() :
    PhysicalActivityData()
{
    _type = WorkHoursType;
}

WorkHoursData::WorkHoursData(float hours) :
    PhysicalActivityData()
{
    setHoursWorked(hours);
}

WorkHoursData::WorkHoursData(PhysicalActivityData data, float hours) : PhysicalActivityData(data)
{
    setHoursWorked(hours);
}

QString WorkHoursData::toString()
{
    return PhysicalActivityData::toString() + " | WorkHours: " + QString::number(hoursWorked());
}

QDataStream &operator<<(QDataStream &out, const WorkHoursData &data)
{
    out << data.recordedDate();
    out << data.hoursWorked();
    return out;
}

QDataStream &operator>>(QDataStream &in, WorkHoursData &data)
{
    PhysicalActivityData read;
    float hours;
    in >> read >> hours;

    data.setHoursWorked(hours);
    data.setRecordedDate(read.recordedDate());

    return in;
}
