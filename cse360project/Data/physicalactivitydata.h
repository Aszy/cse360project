#ifndef PHYSICALACTIVITYDATA_H
#define PHYSICALACTIVITYDATA_H

#include "Data/data.h"

class PhysicalActivityData : public Data
{
public:
    explicit PhysicalActivityData();
    explicit PhysicalActivityData(Data data);

    virtual QString toString();

signals:

public slots:

};

// Serialization
QDataStream &operator<<(QDataStream &out, const PhysicalActivityData &data);
QDataStream &operator>>(QDataStream &in, PhysicalActivityData &data);

#endif // PHYSICALACTIVITYDATA_H
