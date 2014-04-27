#include "healthtrackerui.h"
#include "Data/data.h"
#include "Data/serializer.h"

#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QApplication>

void saveData(QString filename)
{
    // Save
    QFile file(filename);

    // Attempt to open the file.
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Couldn't open the file to write";
        return;
    }

    // Serialize the data into the file.
    QDataStream stream(&file);
    Serializer::serialize(stream, Data::repository);
    file.close();

    // Notify the user.
    qDebug() << "Saved " + QString::number(Data::repository.size()) + " entries.";
}


void loadData(QString filename)
{
    // Load
    QFile file(filename);

    // Attempt to open the file.
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Couldn't open the file to read";
        return;
    }

    // Deserialize the data from the file.
    QDataStream stream(&file);
    Serializer::deserialize(stream, Data::repository);
    file.close();

    // Notify the user.
    qDebug() << "Loaded " + QString::number(Data::repository.count()) + " entries.";
}

int main(int argc, char *argv[])
{
    QString filename = "repository.dat";

    // Initialize the application.
    QApplication a(argc, argv);
    HealthTrackerUI w;
    w.show();

    // Load the data from file.
    loadData(filename);

    // Run the application.
    int ret = a.exec();

    // Save the data to file.
    saveData(filename);

    return ret;
}
