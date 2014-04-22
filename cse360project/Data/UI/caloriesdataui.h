#ifndef CALORIESDATAUI_H
#define CALORIESDATAUI_H

#include <QMainWindow>
#include <QList>

#include "Data/data.h"

namespace Ui {
class CaloriesDataUI;
}

class CaloriesDataUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CaloriesDataUI(QWidget *parent = 0);
    ~CaloriesDataUI();

public slots:
    void submitData();
    void cancel();

private:
    Ui::CaloriesDataUI *ui;

    QList<Data *> dataList;
};

#endif // CALORIESDATAUI_H
