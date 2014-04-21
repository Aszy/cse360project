#ifndef CARDIOWORKOUTDATA_H
#define CARDIOWORKOUTDATA_H

#include "Data/physicalactivitydata.h"

class CardioWorkoutData : public PhysicalActivityData
{
public:
    explicit CardioWorkoutData();
    explicit CardioWorkoutData(float time, float distance);
    explicit CardioWorkoutData(PhysicalActivityData data, float time, float distance);

    // Accessors
    float runTime() const { return _runTime; }
    void setRunTime(float time) { _runTime = time; }

    float runDistance() const { return _runDistance; }
    void setRunDistance(float distance) { _runDistance = distance; }

    float averageRunSpeed() { return _runTime / _runDistance; }

    virtual QString toString();

signals:

public slots:

private:
    float _runTime;
    float _runDistance;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const CardioWorkoutData &data);
QDataStream &operator>>(QDataStream &in, CardioWorkoutData &data);

#endif // CARDIOWORKOUTDATA_H
