#ifndef PULSERATEREPORT_H
#define PULSERATEREPORT_H

#include "report.h"

class PulseRateReport : public Report
{
public:
    PulseRateReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // PULSERATEREPORT_H
