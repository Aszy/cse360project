#ifndef REPORTUI_H
#define REPORTUI_H

#include "Report/report.h"

#include <QDialog>

namespace Ui {
class ReportUI;
}

class ReportUI : public QDialog
{
    Q_OBJECT

public:
    explicit ReportUI(QWidget *parent = 0);
    ~ReportUI();

public slots:
    void generateReport();
    void cancel();

private:
    Ui::ReportUI *ui;
    QList<Report *> _reports;
};

#endif // REPORTUI_H
