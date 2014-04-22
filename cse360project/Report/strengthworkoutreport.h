#ifndef STRENGTHWORKOUTREPORT_H
#define STRENGTHWORKOUTREPORT_H

#include "report.h"

class StrengthWorkoutReport : public Report
{
public:
    StrengthWorkoutReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // STRENGTHWORKOUTREPORT_H
