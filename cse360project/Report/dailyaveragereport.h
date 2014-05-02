#ifndef DAILYAVERAGEREPORT_H
#define DAILYAVERAGEREPORT_H

#include "report.h"

class DailyAverageReport : public Report
{
public:
    DailyAverageReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString name() const;
    virtual QString graphHtml() const;
};

#endif // DAILYAVERAGEREPORT_H
