#ifndef REPORTUI_H
#define REPORTUI_H

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

private:
    Ui::ReportUI *ui;
};

#endif // REPORTUI_H
