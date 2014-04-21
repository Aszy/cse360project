#include "Data/UI/pulseratedataui.h"
#include "ui_pulseratedataui.h"
#include "enterdataui.h"

#include "Data/pulseratedata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

PulseRateDataUI::PulseRateDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PulseRateDataUI)
{
    ui->setupUi(this);
}

PulseRateDataUI::~PulseRateDataUI()
{
    delete ui;
}

void PulseRateDataUI::submitPulseRateData()
{
    // Get the attributes.
    int rate = ui->spinPulseRate->value();
    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a PulseRateData.
    PulseRateData *pulseData = new PulseRateData;
    pulseData->setPulseRate(rate);
    pulseData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(pulseData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted pulse rate data.");
    this->cancel();
}

void PulseRateDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

