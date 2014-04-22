#include "serializer.h"

#include "pulseratedata.h"
#include "bloodsugardata.h"
#include "bloodpressuredata.h"
#include "temperaturedata.h"

#include "caloriesdata.h"
#include "sleepamountdata.h"
#include "workhoursdata.h"
#include "cardioworkoutdata.h"
#include "strengthworkoutdata.h"

void Serializer::serialize(QDataStream &stream, QList<Data *> &list)
{
    foreach (Data *data, list)
    {
        // Serialize the data's type.
        stream << data->type();

        switch (data->type())
        {
        case PulseRateType:
            stream << *dynamic_cast<PulseRateData *>(data);
            break;

        case BloodSugarType:
            stream << *dynamic_cast<BloodSugarData *>(data);
            break;

        case BloodPressureType:
            stream << *dynamic_cast<BloodPressureData *>(data);
            break;

        case TemperatureType:
            stream << *dynamic_cast<TemperatureData *>(data);
            break;

        case CaloriesType:
            stream << *dynamic_cast<CaloriesData *>(data);
            break;

        case SleepAmountType:
            stream << *dynamic_cast<SleepAmountData *>(data);
            break;

        case WorkHoursType:
            stream << *dynamic_cast<WorkHoursData *>(data);
            break;

        case CardioWorkoutType:
            stream << *dynamic_cast<CardioWorkoutData *>(data);
            break;

        case StrengthWorkoutType:
            stream << *dynamic_cast<StrengthWorkoutData *>(data);
            break;

        default:
            stream << data;
        }
    }
}

void Serializer::deserialize(QDataStream &stream, QList<Data *> &list)
{
    while (!stream.atEnd())
    {
        DataType type;

        // Deserialize the data's type.
        stream >> type;

        switch (type)
        {
            case PulseRateType:
            {
                PulseRateData *data = new PulseRateData;
                stream >> *data;
                list << data;
                break;
            }

            case BloodSugarType:
            {
                BloodSugarData *data = new BloodSugarData;
                stream >> *data;
                list << data;
                break;
            }

            case BloodPressureType:
            {
                BloodPressureData *data = new BloodPressureData;
                stream >> *data;
                list << data;
                break;
            }

            case TemperatureType:
            {
                TemperatureData *data = new TemperatureData;
                stream >> *data;
                list << data;
                break;
            }

            case CaloriesType:
            {
                CaloriesData *data = new CaloriesData;
                stream >> *data;
                list << data;
                break;
            }

            case SleepAmountType:
            {
                SleepAmountData *data = new SleepAmountData;
                stream >> *data;
                list << data;
                break;
            }

            case WorkHoursType:
            {
                WorkHoursData *data = new WorkHoursData;
                stream >> *data;
                list << data;
                break;
            }

            case CardioWorkoutType:
            {
                CardioWorkoutData *data = new CardioWorkoutData;
                stream >> *data;
                list << data;
                break;
            }

            case StrengthWorkoutType:
            {
                StrengthWorkoutData *data = new StrengthWorkoutData;
                stream >> *data;
                list << data;
                break;
            }

            default:
            {
                Data *data = new Data;
                stream >> *data;
                list << data;
                break;
            }
        }
    }
}
