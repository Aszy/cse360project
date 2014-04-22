#include "pulseratereport.h"

#include <QDebug>

PulseRateReport::PulseRateReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    foreach (Data *data, repository)
    {
        if (data->type() == PulseRateType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString PulseRateReport::graphURL() const
{
    return "";
}
