#ifndef BLOODPRESSUREREPORT_H
#define BLOODPRESSUREREPORT_H

#include "report.h"

class BloodPressureReport : public Report
{
public:
    BloodPressureReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // BLOODPRESSUREREPORT_H
