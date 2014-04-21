#include "enterdataui.h"
#include "ui_enterdataui.h"

#include "Data/UI/pulseratedataui.h"

#include "healthtrackerui.h"

EnterDataUI::EnterDataUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterDataUI)
{
    ui->setupUi(this);
}

EnterDataUI::~EnterDataUI()
{
    delete ui;
}

void EnterDataUI::showPulseRateDataUI()
{
    this->close();

    PulseRateDataUI *dataUI = new PulseRateDataUI();
    dataUI->setVisible(true);
}

void EnterDataUI::cancel()
{
    this->close();

    HealthTrackerUI *healthUI = new HealthTrackerUI();
    healthUI->setVisible(true);
}
