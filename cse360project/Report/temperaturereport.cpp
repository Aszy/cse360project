#include "temperaturereport.h"
#include "Data/temperaturedata.h"

#include <QDebug>

TemperatureReport::TemperatureReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = TemperatureType;

    foreach (Data *data, repository)
    {
        if (data->type() == TemperatureType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString TemperatureReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return "Not enough data for report.";

    QStringList headers = QStringList() << "x" << "Temperature";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        TemperatureData *data = dynamic_cast<TemperatureData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->temperature(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
