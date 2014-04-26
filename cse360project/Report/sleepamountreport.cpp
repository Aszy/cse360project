#include "sleepamountreport.h"
#include "Data/sleepamountdata.h"

#include <QDebug>

SleepAmountReport::SleepAmountReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = SleepAmountType;

    foreach (Data *data, repository)
    {
        if (data->type() == SleepAmountType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString SleepAmountReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return "Not enough data for report.";

    QStringList headers = QStringList() << "x" << "Hours Slept";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        SleepAmountData *data = dynamic_cast<SleepAmountData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->hoursSlept(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
