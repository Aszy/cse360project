#ifndef BLOODSUGARREPORT_H
#define BLOODSUGARREPORT_H

#include "report.h"

class BloodSugarReport : public Report
{
public:
    BloodSugarReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // BLOODSUGARREPORT_H
