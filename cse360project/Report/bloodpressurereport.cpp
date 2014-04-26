#include "bloodpressurereport.h"
#include "Data/bloodpressuredata.h"

#include <QDebug>

BloodPressureReport::BloodPressureReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = BloodPressureType;

    foreach (Data *data, repository)
    {
        if (data->type() == BloodPressureType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString BloodPressureReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Systolic Blood Pressure" << "Diastolic Blood Pressure";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        BloodPressureData *data = dynamic_cast<BloodPressureData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->systolicPressure());
        row << QString::number(data->diastolicPressure());
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
