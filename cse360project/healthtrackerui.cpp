#include "healthtrackerui.h"
#include "ui_healthtrackerui.h"

#include "enterdataui.h"

#include <QDebug>

HealthTrackerUI::HealthTrackerUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HealthTrackerUI)
{
    ui->setupUi(this);

    foreach (Data *data, Data::repository) {
        qDebug() << data->toString();
    }
    qDebug() << "\n";
}

HealthTrackerUI::~HealthTrackerUI()
{
    delete ui;
}

void HealthTrackerUI::openEnterDataUI()
{
    this->close();

    EnterDataUI *dataUI = new EnterDataUI();
    dataUI->setVisible(true);
}
