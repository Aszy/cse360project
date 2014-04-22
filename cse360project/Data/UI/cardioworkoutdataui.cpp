#include "Data/UI/cardioworkoutdataui.h"
#include "ui_cardioworkoutdataui.h"
#include "enterdataui.h"

#include "Data/cardioworkoutdata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

CardioWorkoutDataUI::CardioWorkoutDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardioWorkoutDataUI)
{
    ui->setupUi(this);
}

CardioWorkoutDataUI::~CardioWorkoutDataUI()
{
    delete ui;
}

void CardioWorkoutDataUI::updateRunSpeed()
{
    // Get the attributes.
    float runTime = ui->spinRunTime->value();
    float runDistance = ui->spinRunDistance->value();

    // Construct a temporary CardioWorkoutData.
    CardioWorkoutData data;
    data.setRunTime(runTime);
    data.setRunDistance(runDistance);

    ui->labelRunSpeed->setText(QString::number(data.averageRunSpeed(), 'f', 1) + " mph");
}

void CardioWorkoutDataUI::submitData()
{
    // Get the attributes.
    float runTime = ui->spinRunTime->value();
    float runDistance = ui->spinRunDistance->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a CardioWorkoutData.
    CardioWorkoutData *cardioWorkoutData = new CardioWorkoutData;
    cardioWorkoutData->setRunTime(runTime);
    cardioWorkoutData->setRunDistance(runDistance);
    cardioWorkoutData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(cardioWorkoutData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted cardio workout data.");
    this->cancel();
}

void CardioWorkoutDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

