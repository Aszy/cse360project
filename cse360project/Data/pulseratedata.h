#ifndef PULSERATEDATA_H
#define PULSERATEDATA_H

#include "Data/healthdata.h"

class PulseRateData : public HealthData
{
public:
    explicit PulseRateData();
    explicit PulseRateData(int rate);
    explicit PulseRateData(HealthData data, int rate);

    // Accessors
    int pulseRate() const { return _pulseRate; }
    void setPulseRate(int rate) { _pulseRate = rate; }

    virtual QString type() const;

    virtual QString toString();

signals:

public slots:

private:
    int _pulseRate;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const PulseRateData &data);
QDataStream &operator>>(QDataStream &in, PulseRateData &data);

#endif // PULSERATEDATA_H
