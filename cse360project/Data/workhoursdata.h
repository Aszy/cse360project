#ifndef WORKHOURSDATA_H
#define WORKHOURSDATA_H

#include "Data/physicalactivitydata.h"

class WorkHoursData : public PhysicalActivityData
{
public:
    explicit WorkHoursData();
    explicit WorkHoursData(float hours);
    explicit WorkHoursData(PhysicalActivityData data, float hours);

    // Accessors
    float hoursWorked() const { return _hoursWorked; }
    void setHoursWorked(float hours) { _hoursWorked = hours; }

    virtual QString toString();

signals:

public slots:

private:
    float _hoursWorked;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const WorkHoursData &data);
QDataStream &operator>>(QDataStream &in, WorkHoursData &data);

#endif // WORKHOURSDATA_H
