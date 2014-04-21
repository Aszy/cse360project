#ifndef BLOODSUGARDATA_H
#define BLOODSUGARDATA_H

#include "Data/healthdata.h"

class BloodSugarData : public HealthData
{
public:
    explicit BloodSugarData();
    explicit BloodSugarData(float level);
    explicit BloodSugarData(HealthData data, float level);

    // Accessors
    float bloodSugar() const { return _bloodSugar; }
    void setBloodSugar(float level) { _bloodSugar = level; }

    virtual QString toString();

signals:

public slots:

private:
    float _bloodSugar;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const BloodSugarData &data);
QDataStream &operator>>(QDataStream &in, BloodSugarData &data);

#endif // BLOODSUGARDATA_H
