#include "reportui.h"
#include "ui_reportui.h"

#include "Data/data.h"

#include "Report/pulseratereport.h"
#include "Report/bloodsugarreport.h"
#include "Report/bloodpressurereport.h"
#include "Report/temperaturereport.h"

#include "Report/caloriesreport.h"
#include "Report/sleepamountreport.h"
#include "Report/workhoursreport.h"
#include "Report/cardioworkoutreport.h"
#include "Report/strengthworkoutreport.h"

#include "healthtrackerui.h"

#include <QDebug>

ReportUI::ReportUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportUI)
{
    ui->setupUi(this);

    QPalette palette = ui->webView->palette();
    palette.setBrush(QPalette::Base, Qt::transparent);
    ui->webView->page()->setPalette(palette);
    ui->webView->setAttribute(Qt::WA_OpaquePaintEvent, false);
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
        _reports.append(new PulseRateReport(Data::repository, start, end));

    if (ui->checkBloodSugar->isChecked())
        _reports.append(new BloodSugarReport(Data::repository, start, end));

    if (ui->checkBloodPressure->isChecked())
        _reports.append(new BloodPressureReport(Data::repository, start, end));

    if (ui->checkTemperature->isChecked())
        _reports.append(new TemperatureReport(Data::repository, start, end));

    if (ui->checkCalories->isChecked())
        _reports.append(new CaloriesReport(Data::repository, start, end));

    if (ui->checkSleepAmount->isChecked())
        _reports.append(new SleepAmountReport(Data::repository, start, end));

    if (ui->checkWorkHours->isChecked())
        _reports.append(new WorkHoursReport(Data::repository, start, end));

    if (ui->checkCardioWorkout->isChecked())
        _reports.append(new CardioWorkoutReport(Data::repository, start, end));

    if (ui->checkStrengthWorkout->isChecked())
        _reports.append(new StrengthWorkoutReport(Data::repository, start, end));

    qDebug() << "Created " + QString::number(_reports.size()) + " reports";

    ui->tabReports->clear();

    if (_reports.isEmpty())
    {
        ui->tabReports->addTab(new QWidget, "No Report");
    }
    else
    {
        // Add each report as a tab.
        foreach (Report *report, _reports)
        {
            QWidget *page = new QWidget;
            QLayout *layout = new QVBoxLayout;
            page->setLayout(layout);
            ui->tabReports->addTab(page, Data::typeToFriendlyString(report->type()));
        }
    }

    // Trigger the tab change.
    reportTabChanged(0);
}

void ReportUI::reportTabChanged(int tab)
{
    if (tab == -1 || _reports.isEmpty())
        return;

    Report *report = _reports.at(tab);
    ui->webView->setHtml(report->graphHtml(), QUrl("http://example.com"));
    ui->tabReports->currentWidget()->layout()->addWidget(ui->webView);
}

void ReportUI::cancel()
{
    this->close();

    HealthTrackerUI *healthUI = new HealthTrackerUI;
    healthUI->setVisible(true);
}
