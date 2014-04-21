#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

#include "Data/healthdata.h"

class TemperatureData : public HealthData
{
public:
    explicit TemperatureData();
    explicit TemperatureData(float temperature);
    explicit TemperatureData(HealthData data, float temperature);

    // Accessors
    float temperature() const { return _temperature; }
    void setTemperature(float temperature) { _temperature = temperature; }

    virtual QString toString();

signals:

public slots:

private:
    float _temperature;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const TemperatureData &data);
QDataStream &operator>>(QDataStream &in, TemperatureData &data);

#endif // TEMPERATUREDATA_H
