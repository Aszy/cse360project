#ifndef CALORIESREPORT_H
#define CALORIESREPORT_H

#include "report.h"

class CaloriesReport : public Report
{
public:
    CaloriesReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // CALORIESREPORT_H
