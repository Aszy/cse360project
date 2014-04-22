#include "reportui.h"
#include "ui_reportui.h"

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
