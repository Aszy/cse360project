#include <QtTest/QTest>
#include <QList>

#include "Report/workhoursreport.h"
#include "Data/workhoursdata.h"

class WorkHoursReportTest : QObject
{
    Q_OBJECT

private slots:
    void testReport()
    {
        // With an empty repository, the report should tell us that there is not enough data.
        QList<Data *> repository;
        QDate today = QDate::currentDate();
        QDate yesterday = today.addDays(-1);
        WorkHoursReport report(repository, yesterday, today);

        QString html = report.graphHtml();
        QVERIFY(html.contains("Not enough data", Qt::CaseInsensitive));

        // With some data, the graph should be generated.
        Data *data = new WorkHoursData(2.0);
        data->setRecordedDate(QDate::currentDate());
        repository << data;

        html = report.graphHtml();
        QVERIFY(false == html.contains("Not enough data", Qt::CaseInsensitive));
    }
};
