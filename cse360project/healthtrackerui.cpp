#include "healthtrackerui.h"
#include "ui_healthtrackerui.h"

#include "Data/pulseratedata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

HealthTrackerUI::HealthTrackerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HealthTrackerUI)
{
    ui->setupUi(this);
}

HealthTrackerUI::~HealthTrackerUI()
{
    delete ui;
}

void HealthTrackerUI::testSave()
{
    // Create a PulseRateData.
    PulseRateData pulseData;
    pulseData.setPulseRate(rand() % 100);
    pulseData.setRecordedDate(QDate::currentDate());

    // Save
    QString fileName = QFileDialog::getSaveFileName(this,
             "Save some data", "",
             "Health Tracker (*.health);;All Files (*)"
    );

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);

        // Attempt to open the file.
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, "Error saving file", "Couldn't open the file to write");
            return;
        }

        // Serialize the data into the file.
        QDataStream stream(&file);
        stream << pulseData;

        // Close the file.
        file.close();

        // Notify the user.
        QMessageBox::information(this, "Successfully saved data!", pulseData.toString());
    }
}


void HealthTrackerUI::testLoad()
{
    // Create a PulseRateData.
    PulseRateData pulseData;

    // Load
    QString fileName = QFileDialog::getOpenFileName(this,
             "Load some data", "",
             "Health Tracker (*.health);;All Files (*)"
    );

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);

        // Attempt to open the file.
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, "Error loading file", "Couldn't open the file to read");
            return;
        }

        // Serialize the data into the file.
        QDataStream stream(&file);
        stream >> pulseData;

        // Close the file.
        file.close();

        // Notify the user.
        QMessageBox::information(this, "Successfully loaded data!", pulseData.toString());
    }
}
