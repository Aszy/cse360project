#include "pulseratereport.h"
#include "Data/pulseratedata.h"

#include <QDebug>

PulseRateReport::PulseRateReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = PulseRateType;

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


QString PulseRateReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Pulse Rate";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        PulseRateData *data = dynamic_cast<PulseRateData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->pulseRate());
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
