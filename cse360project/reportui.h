#ifndef REPORTUI_H
#define REPORTUI_H

#include "Report/report.h"

#include <QDialog>
#include <QPrinter>

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
    void printReport();
    void reportTabChanged(int);
    void cancel();

    void printPage(QPrinter *);

private:
    Ui::ReportUI *ui;
    QList<Report *> _reports;
};

#endif // REPORTUI_H
