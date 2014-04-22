#include "Data/UI/sleepamountdataui.h"
#include "ui_sleepamountdataui.h"
#include "enterdataui.h"

#include "Data/sleepamountdata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

SleepAmountDataUI::SleepAmountDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SleepAmountDataUI)
{
    ui->setupUi(this);
}

SleepAmountDataUI::~SleepAmountDataUI()
{
    delete ui;
}

void SleepAmountDataUI::submitData()
{
    // Get the attributes.
    float sleepAmount = ui->spinSleepAmount->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a SleepAmountData.
    SleepAmountData *sleepAmountData = new SleepAmountData;
    sleepAmountData->setHoursSlept(sleepAmount);
    sleepAmountData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(sleepAmountData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted sleep amount data.");
    this->cancel();
}

void SleepAmountDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

