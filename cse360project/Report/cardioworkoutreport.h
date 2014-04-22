#ifndef CARDIOWORKOUTREPORT_H
#define CARDIOWORKOUTREPORT_H

#include "report.h"

class CardioWorkoutReport : public Report
{
public:
    CardioWorkoutReport(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const;
};

#endif // CARDIOWORKOUTREPORT_H
