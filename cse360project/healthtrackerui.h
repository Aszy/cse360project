#ifndef HEALTHTRACKERUI_H
#define HEALTHTRACKERUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class HealthTrackerUI;
}

class HealthTrackerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit HealthTrackerUI(QWidget *parent = 0);
    ~HealthTrackerUI();

public slots:
    void submitPulseRateData();
    void updateListWidget();

    void testSave();
    void testLoad();

private:
    Ui::HealthTrackerUI *ui;

    QList<Data *> dataList;
};

#endif // HEALTHTRACKERUI_H
