#include "Data/UI/workhoursdataui.h"
#include "ui_workhoursdataui.h"
#include "enterdataui.h"

#include "Data/workhoursdata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

WorkHoursDataUI::WorkHoursDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkHoursDataUI)
{
    ui->setupUi(this);
}

WorkHoursDataUI::~WorkHoursDataUI()
{
    delete ui;
}

void WorkHoursDataUI::submitData()
{
    // Get the attributes.
    float workHours = ui->spinHoursWorked->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a WorkHoursData.
    WorkHoursData *workHoursData = new WorkHoursData;
    workHoursData->setHoursWorked(workHours);
    workHoursData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(workHoursData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted work hours data.");
    this->cancel();
}

void WorkHoursDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

