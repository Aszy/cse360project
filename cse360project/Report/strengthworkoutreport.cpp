#include "strengthworkoutreport.h"
#include "Data/strengthworkoutdata.h"

#include <QDebug>

StrengthWorkoutReport::StrengthWorkoutReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    _type = StrengthWorkoutType;

    foreach (Data *data, repository)
    {
        if (data->type() == StrengthWorkoutType && start <= data->recordedDate() && end >= data->recordedDate())
        {
            _dataList.append(data);
        }
    }

    foreach (Data *data, _dataList)
    {
        qDebug() << data->toString();
    }
}


QString StrengthWorkoutReport::graphHtml() const
{
    if (_dataList.isEmpty())
        return Report::notEnoughDataTemplate();

    QStringList headers = QStringList() << "x" << "Workout Time";
    QList<QStringList> dataRows;

    foreach (Data *bdata, _dataList)
    {
        StrengthWorkoutData *data = dynamic_cast<StrengthWorkoutData *>(bdata);
        QStringList row;
        row << "'" + data->recordedDate().toString() + "'";
        row << QString::number(data->workoutTime(), 'f', 1);
        dataRows << row;
    }

    return Report::graphHtmlTemplate(headers, dataRows);
}
