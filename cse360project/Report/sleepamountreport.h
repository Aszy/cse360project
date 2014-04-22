#ifndef SLEEPAMOUNTREPORT_H
#define SLEEPAMOUNTREPORT_H

#include "report.h"

class SleepAmountReport : public Report
{
public:
    SleepAmountReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // SLEEPAMOUNTREPORT_H
