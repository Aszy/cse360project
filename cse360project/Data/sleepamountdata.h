#ifndef SLEEPAMOUNTDATA_H
#define SLEEPAMOUNTDATA_H

#include "Data/physicalactivitydata.h"

class SleepAmountData : public PhysicalActivityData
{
public:
    explicit SleepAmountData();
    explicit SleepAmountData(float hours);
    explicit SleepAmountData(PhysicalActivityData data, float hours);

    // Accessors
    float hoursSlept() const { return _hoursSlept; }
    void setHoursSlept(float hours) { _hoursSlept = hours; }

    virtual QString toString();

signals:

public slots:

private:
    float _hoursSlept;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const SleepAmountData &data);
QDataStream &operator>>(QDataStream &in, SleepAmountData &data);

#endif // SLEEPAMOUNTDATA_H
