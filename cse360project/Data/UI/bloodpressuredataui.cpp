#include "Data/UI/bloodpressuredataui.h"
#include "ui_bloodpressuredataui.h"
#include "enterdataui.h"

#include "Data/bloodpressuredata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

BloodPressureDataUI::BloodPressureDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BloodPressureDataUI)
{
    ui->setupUi(this);
}

BloodPressureDataUI::~BloodPressureDataUI()
{
    delete ui;
}

void BloodPressureDataUI::submitData()
{
    // Get the attributes.
    int systolic = ui->spinSystolic->value();
    int diastolic = ui->spinDiastolic->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a BloodPressureData.
    BloodPressureData *bloodPressureData = new BloodPressureData;
    bloodPressureData->setSystolicPressure(systolic);
    bloodPressureData->setDiastolicPressure(diastolic);
    bloodPressureData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(bloodPressureData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted pulse rate data.");
    this->cancel();
}

void BloodPressureDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

