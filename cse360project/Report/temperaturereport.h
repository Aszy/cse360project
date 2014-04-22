#ifndef TEMPERATUREREPORT_H
#define TEMPERATUREREPORT_H

#include "report.h"

class TemperatureReport : public Report
{
public:
    TemperatureReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // TEMPERATUREREPORT_H
