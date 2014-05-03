#include <QtTest/QTest>

#include "Data/data.h"

class DataTest : QObject
{
    Q_OBJECT

private slots:
    void testDataTypeToString()
    {
        QVERIFY(0 == QString::compare("HealthData", Data::typeToString(HealthType)));
        QVERIFY(0 == QString::compare("PulseRateData", Data::typeToString(PulseRateType)));
        QVERIFY(0 == QString::compare("BloodPressureData", Data::typeToString(BloodPressureType)));
        QVERIFY(0 == QString::compare("BloodSugarData", Data::typeToString(BloodSugarType)));
        QVERIFY(0 == QString::compare("TemperatureData", Data::typeToString(TemperatureType)));

        QVERIFY(0 == QString::compare("PhysicalActivityData", Data::typeToString(PhysicalActivityType)));
        QVERIFY(0 == QString::compare("StrengthWorkoutData", Data::typeToString(StrengthWorkoutType)));
        QVERIFY(0 == QString::compare("CardioWorkoutData", Data::typeToString(CardioWorkoutType)));
        QVERIFY(0 == QString::compare("SleepAmountData", Data::typeToString(SleepAmountType)));
        QVERIFY(0 == QString::compare("WorkHoursData", Data::typeToString(WorkHoursType)));
        QVERIFY(0 == QString::compare("CaloriesData", Data::typeToString(CaloriesType)));

        QVERIFY(0 == QString::compare("Data", Data::typeToString(HealthType)));
    }

    void testSaveData()
    {
        QString filename;

        filename = "Z:/cannot/write/here";
        QVERIFY(Main::saveData(filename) == false);

        filename = "C:/canwritethis.dat";
        QVERIFY(Main::saveData(filename));
    }

    void testLoadData()
    {
        QString filename("C:/doesnotexistyet.dat");

        // Can't load a non-existent file.
        QVERIFY(Main::loadData(filename) == false);

        // Save the file, then load.
        QVERIFY(Main::saveData(filename));
        QVERIFY(Main::loadData(filename));
    }
};
