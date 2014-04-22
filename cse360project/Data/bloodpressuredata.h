#ifndef BLOODPRESSUREDATA_H
#define BLOODPRESSUREDATA_H

#include "Data/healthdata.h"

class BloodPressureData : public HealthData
{
public:
    explicit BloodPressureData();
    explicit BloodPressureData(int systolic, int diastolic);
    explicit BloodPressureData(HealthData data, int systolic, int diastolic);

    // Accessors
    int systolicPressure() const { return _systolic; }
    void setSystolicPressure(int systolic) { _systolic = systolic; }

    int diastolicPressure() const { return _diastolic; }
    void setDiastolicPressure(int diastolic) { _diastolic = diastolic; }

    virtual QString toString();

signals:

public slots:

private:
    int _systolic;
    int _diastolic;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const BloodPressureData &data);
QDataStream &operator>>(QDataStream &in, BloodPressureData &data);

#endif // BLOODPRESSUREDATA_H
