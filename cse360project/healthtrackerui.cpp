#include "healthtrackerui.h"
#include "ui_healthtrackerui.h"

HealthTrackerUI::HealthTrackerUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HealthTrackerUI)
{
    ui->setupUi(this);
}

HealthTrackerUI::~HealthTrackerUI()
{
    delete ui;
}
