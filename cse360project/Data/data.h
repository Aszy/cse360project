#ifndef DATA_H
#define DATA_H

#include <QDate>
#include <QDataStream>

typedef enum DataType
{
    NoneType,

    HealthType,
    PulseRateType,
    BloodPressureType,
    BloodSugarType,
    TemperatureType,

    PhysicalActivityType,
    StrengthWorkoutType,
    CardioWorkoutType,
    SleepAmountType,
    WorkHoursType,
    CaloriesType
} DataType;

class Data
{
public:
    explicit Data();

    // Accessors
    QDate recordedDate() const { return _recordedDate; }
    void setRecordedDate(const QDate recordedDate) { _recordedDate = recordedDate; }

    virtual DataType type() const { return _type; }

    virtual QString toString();

signals:

public slots:

protected:
    DataType _type;

private:
    QDate _recordedDate;

public: /* static */
    static QString typeToString(DataType value)
    {
        switch (value)
        {
        case HealthType:            return "HealthData";
        case PulseRateType:         return "PulseRateData";
        case BloodPressureType:     return "BloodPressureData";
        case BloodSugarType:        return "BloodSugarData";
        case TemperatureType:       return "TemperatureData";

        case PhysicalActivityType:	return "PhysicalActivityData";
        case StrengthWorkoutType:	return "StrengthWorkoutData";
        case CardioWorkoutType:     return "CardioWorkoutData";
        case SleepAmountType:   	return "SleepAmountData";
        case WorkHoursType:         return "WorkHoursData";
        case CaloriesType:          return "CaloriesData";

        default:                    return "Data";
        }
    }

};

// Serialization
QDataStream &operator<<(QDataStream &out, const Data &data);
QDataStream &operator>>(QDataStream &in, Data &data);

// Serialization
QDataStream &operator<<(QDataStream &out, const DataType &data);
QDataStream &operator>>(QDataStream &in, DataType &data);

#endif // DATA_H
