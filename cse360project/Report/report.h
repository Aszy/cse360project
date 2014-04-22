#ifndef REPORT_H
#define REPORT_H

#include "Data/data.h"

#include <QList>
#include <QDate>

class Report
{
public:
    Report(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphURL() const = 0;

protected:
    QList<Data *> _dataList;
    QDate _start;
    QDate _end;
};

#endif // REPORT_H
