#include "workhoursreport.h"
#include "Data/workhoursdata.h"

#include <QDebug>

WorkHoursReport::WorkHoursReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = WorkHoursType;

    foreach (Data *data, repository)
    {
        if (data->type() == WorkHoursType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString WorkHoursReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return "Not enough data for report.";

    QStringList headers = QStringList() << "x" << "Hours Worked";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        WorkHoursData *data = dynamic_cast<WorkHoursData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->hoursWorked(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
