#ifndef STRENGTHWORKOUTDATA_H
#define STRENGTHWORKOUTDATA_H

#include "Data/physicalactivitydata.h"

class StrengthWorkoutData : public PhysicalActivityData
{
public:
    explicit StrengthWorkoutData();
    explicit StrengthWorkoutData(float workoutTime);
    explicit StrengthWorkoutData(PhysicalActivityData data, float workoutTime);

    // Accessors
    float workoutTime() const { return _workoutTime; }
    void setWorkoutTime(float workoutTime) { _workoutTime = workoutTime; }

    virtual QString toString();

signals:

public slots:

private:
    float _workoutTime;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const StrengthWorkoutData &data);
QDataStream &operator>>(QDataStream &in, StrengthWorkoutData &data);

#endif // STRENGTHWORKOUTDATA_H
