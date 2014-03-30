#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include "Data/data.h"

class HealthData : public Data
{
public:
    explicit HealthData();
    explicit HealthData(Data data);

    virtual QString type() const;

    virtual QString toString();

signals:

public slots:

};

// Serialization
QDataStream &operator<<(QDataStream &out, const HealthData &data);
QDataStream &operator>>(QDataStream &in, HealthData &data);

#endif // HEALTHDATA_H
