#include "Data/UI/strengthworkoutdataui.h"
#include "ui_strengthworkoutdataui.h"
#include "enterdataui.h"

#include "Data/strengthworkoutdata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

StrengthWorkoutDataUI::StrengthWorkoutDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StrengthWorkoutDataUI)
{
    ui->setupUi(this);
}

StrengthWorkoutDataUI::~StrengthWorkoutDataUI()
{
    delete ui;
}

void StrengthWorkoutDataUI::submitData()
{
    // Get the attributes.
    float workoutTime = ui->spinWorkoutTime->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a StrengthWorkoutData.
    StrengthWorkoutData *strengthWorkoutData = new StrengthWorkoutData;
    strengthWorkoutData->setWorkoutTime(workoutTime);
    strengthWorkoutData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(strengthWorkoutData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted strength workout data.");
    this->cancel();
}

void StrengthWorkoutDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

