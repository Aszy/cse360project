#include "reportui.h"
#include "ui_reportui.h"

#include "Data/data.h"
#include "Report/pulseratereport.h"

#include "healthtrackerui.h"

#include <QDebug>

ReportUI::ReportUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportUI)
{
    ui->setupUi(this);
}

ReportUI::~ReportUI()
{
    delete ui;
}

void ReportUI::generateReport()
{
    _reports.clear();

    // Get the start and end dates.
    QDate start = ui->dateStart->date();
    QDate end = ui->dateEnd->date();

    // Create a report for each checked type.
    if (ui->checkPulseRate->isChecked())
    {
        _reports.append(new PulseRateReport(Data::repository, start, end));
    }

    qDebug() << "Created " + QString::number(_reports.size()) + " reports";
}

void ReportUI::cancel()
{
    this->close();

    HealthTrackerUI *healthUI = new HealthTrackerUI;
    healthUI->setVisible(true);
}
