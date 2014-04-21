#ifndef CALORIESDATA_H
#define CALORIESDATA_H

#include "Data/physicalactivitydata.h"

class CaloriesData : public PhysicalActivityData
{
public:
    explicit CaloriesData();
    explicit CaloriesData(int calories);
    explicit CaloriesData(PhysicalActivityData data, int calories);

    // Accessors
    int calories() const { return _calories; }
    void setCalories(int calories) { _calories = calories; }

    virtual QString toString();

signals:

public slots:

private:
    int _calories;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const CaloriesData &data);
QDataStream &operator>>(QDataStream &in, CaloriesData &data);

#endif // CALORIESDATA_H
