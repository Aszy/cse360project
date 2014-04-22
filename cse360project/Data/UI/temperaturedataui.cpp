#include "Data/UI/temperaturedataui.h"
#include "ui_temperaturedataui.h"
#include "enterdataui.h"

#include "Data/temperaturedata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

TemperatureDataUI::TemperatureDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TemperatureDataUI)
{
    ui->setupUi(this);
}

TemperatureDataUI::~TemperatureDataUI()
{
    delete ui;
}

void TemperatureDataUI::submitData()
{
    // Get the attributes.
    float temperature = ui->spinTemperature->value();
    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a TemperatureData.
    TemperatureData *temperatureData = new TemperatureData;
    temperatureData->setTemperature(temperature);
    temperatureData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(temperatureData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted temperature data.");
    this->cancel();
}

void TemperatureDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

