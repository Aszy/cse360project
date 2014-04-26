#ifndef REPORT_H
#define REPORT_H

#include "Data/data.h"

#include <QList>
#include <QStringList>
#include <QDate>

class Report
{
public:
    Report(QList<Data *> repository, QDate start, QDate end);

    virtual QString graphHtml() const = 0;

    /* Accessors */
    DataType type() const { return _type; }

    QList<Data *> dataList() { return _dataList; }
    QDate startDate() { return _start; }
    QDate endDate() { return _end; }

    static QString graphHtmlTemplate(QStringList headers, QList<QStringList> data);

protected:
    DataType _type;
    QList<Data *> _dataList;
    QDate _start;
    QDate _end;

};

#endif // REPORT_H
