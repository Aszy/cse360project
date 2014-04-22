#include "Data/UI/bloodsugardataui.h"
#include "ui_bloodsugardataui.h"
#include "enterdataui.h"

#include "Data/bloodsugardata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

BloodSugarDataUI::BloodSugarDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BloodSugarDataUI)
{
    ui->setupUi(this);
}

BloodSugarDataUI::~BloodSugarDataUI()
{
    delete ui;
}

void BloodSugarDataUI::submitData()
{
    // Get the attributes.
    float bloodSugar = ui->spinBloodSugar->value();
    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a BloodSugarData.
    BloodSugarData *bloodSugarData = new BloodSugarData;
    bloodSugarData->setBloodSugar(bloodSugar);
    bloodSugarData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(bloodSugarData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted blood sugar data.");
    this->cancel();
}

void BloodSugarDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

