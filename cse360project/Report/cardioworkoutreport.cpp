#include "cardioworkoutreport.h"
#include "Data/cardioworkoutdata.h"

#include <QDebug>

CardioWorkoutReport::CardioWorkoutReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = CardioWorkoutType;

    foreach (Data *data, repository)
    {
        if (data->type() == CardioWorkoutType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString CardioWorkoutReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Run Time" << "Run Distance" << "Average Run Spin";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        CardioWorkoutData *data = dynamic_cast<CardioWorkoutData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->runTime(), 'f', 1);
        row << QString::number(data->runDistance(), 'f', 1);
        row << QString::number(data->averageRunSpeed(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
