#ifndef HEALTHTRACKERUI_H
#define HEALTHTRACKERUI_H

#include <QDialog>

namespace Ui {
class HealthTrackerUI;
}

class HealthTrackerUI : public QDialog
{
    Q_OBJECT

public:
    explicit HealthTrackerUI(QWidget *parent = 0);
    ~HealthTrackerUI();

public slots:
    void openEnterDataUI();
    void openReportUI();

private:
    Ui::HealthTrackerUI *ui;
};

#endif // HEALTHTRACKERUI_H
