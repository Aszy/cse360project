#ifndef BLOODSUGARDATAUI_H
#define BLOODSUGARDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class BloodSugarDataUI;
}

class BloodSugarDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit BloodSugarDataUI(QWidget *parent = 0);
    ~BloodSugarDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::BloodSugarDataUI *ui;

    QList<Data *> dataList;
};

#endif // BLOODSUGARDATAUI_H
