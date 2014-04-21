#ifndef HEALTHTRACKERUI_H
#define HEALTHTRACKERUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class SampleUI;
}

class SampleUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit SampleUI(QWidget *parent = 0);
    ~SampleUI();

public slots:
    void submitPulseRateData();
    void updateListWidget();

    void testSave();
    void testLoad();

private:
    Ui::SampleUI *ui;

    QList<Data *> dataList;
};

#endif // HEALTHTRACKERUI_H
