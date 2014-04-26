#include "bloodsugarreport.h"
#include "Data/bloodsugardata.h"

#include <QDebug>

BloodSugarReport::BloodSugarReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = BloodSugarType;

    foreach (Data *data, repository)
    {
        if (data->type() == BloodSugarType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString BloodSugarReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Blood Sugar";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        BloodSugarData *data = dynamic_cast<BloodSugarData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->bloodSugar(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
