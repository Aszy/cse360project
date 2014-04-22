#include "Data/UI/caloriesdataui.h"
#include "ui_caloriesdataui.h"
#include "enterdataui.h"

#include "Data/caloriesdata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

class HealthTrackerUI;

CaloriesDataUI::CaloriesDataUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CaloriesDataUI)
{
    ui->setupUi(this);
}

CaloriesDataUI::~CaloriesDataUI()
{
    delete ui;
}

void CaloriesDataUI::submitData()
{
    // Get the attributes.
    int calories = ui->spinCalories->value();

    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a CaloriesData.
    CaloriesData *caloriesData = new CaloriesData;
    caloriesData->setCalories(calories);
    caloriesData->setRecordedDate(date);

    // Add the data to the repository.
    Data::repository.append(caloriesData);

    // Go back to the menu.
    QMessageBox::information(this, "Success", "Successfully submitted calories data.");
    this->cancel();
}

void CaloriesDataUI::cancel()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}

