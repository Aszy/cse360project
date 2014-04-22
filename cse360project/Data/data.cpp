#include "data.h"

Data::Data()
{
    _type = NoneType;
}

QList<Data *> Data::repository = QList<Data *>();

QString Data::toString()
{
    return "Type: " + Data::typeToString(type()) + " | Recorded Date: " + recordedDate().toString();
}

/* static */
QString Data::typeToString(DataType value)
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

/* static */
QString Data::typeToFriendlyString(DataType value)
{
    switch (value)
    {
    case HealthType:            return "Health";
    case PulseRateType:         return "Pulse Rate";
    case BloodPressureType:     return "Blood Pressure";
    case BloodSugarType:        return "Blood Sugar";
    case TemperatureType:       return "Temperature";

    case PhysicalActivityType:	return "Physical Activity";
    case StrengthWorkoutType:	return "Strength Workout";
    case CardioWorkoutType:     return "Cardio Workout";
    case SleepAmountType:   	return "Sleep Amount";
    case WorkHoursType:         return "Work Hours";
    case CaloriesType:          return "Calories";

    default:                    return "";
    }
}

QDataStream &operator<<(QDataStream &out, const Data &data)
{
    out << data.recordedDate();
    return out;
}

QDataStream &operator>>(QDataStream &in, Data &data)
{
    QDate date;
    in >> date;

    data.setRecordedDate(date);

    return in;
}

QDataStream &operator<<(QDataStream &out, const DataType &data)
{
    out << (qint32&)data;
    return out;
}

QDataStream &operator>>(QDataStream &in, DataType &data)
{
    in >> (qint32&)data;
    return in;
}
