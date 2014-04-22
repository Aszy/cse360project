#ifndef WORKHOURSREPORT_H
#define WORKHOURSREPORT_H

#include "report.h"

class WorkHoursReport : public Report
{
public:
    WorkHoursReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // WORKHOURSREPORT_H
