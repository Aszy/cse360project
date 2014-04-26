#include "caloriesreport.h"
#include "Data/caloriesdata.h"

#include <QDebug>

CaloriesReport::CaloriesReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = CaloriesType;

    foreach (Data *data, repository)
    {
        if (data->type() == CaloriesType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString CaloriesReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Calories";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        CaloriesData *data = dynamic_cast<CaloriesData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->calories());
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
