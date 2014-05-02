#include "dailyaveragereport.h"

#include "Data/cardioworkoutdata.h"
#include "Data/sleepamountdata.h"
#include "Data/strengthworkoutdata.h"
#include "Data/workhoursdata.h"

#include <math.h>
#include <QDebug>

DailyAverageReport::DailyAverageReport(QList<Data *> repository, QDate start, QDate end)
    : Report(repository, start, end)
{
    foreach (Data *data, repository)
    {
	if (start <= data->recordedDate() && end >= data->recordedDate() &&
	    (data->type() == CardioWorkoutType ||
	     data->type() == SleepAmountType ||
	     data->type() == StrengthWorkoutType ||
	     data->type() == WorkHoursType))
	{
	    _dataList.append(data);
	}
    }

    foreach (Data *data, _dataList)
    {
	qDebug() << data->toString();
    }
}

QString DailyAverageReport::name() const
{
    return "Daily Activity";
}


QString DailyAverageReport::graphHtml() const
{
    if (_dataList.isEmpty())
	return Report::notEnoughDataTemplate();

    float cardioHours = 0.0,
	  sleepHours = 0.0,
	  strengthHours = 0.0,
	  workHours = 0.0,
	  otherHours = 0.0;
    int cardioCount = 0,
	sleepCount = 0,
	strengthCount = 0,
	workCount = 0;

    foreach (Data *data, _dataList)
    {
	switch (data->type())
	{
	case CardioWorkoutType:
	    cardioHours += (dynamic_cast<CardioWorkoutData *>(data))->runTime();
	    cardioCount++;
	    break;

	case SleepAmountType:
	    sleepHours += (dynamic_cast<SleepAmountData *>(data))->hoursSlept();
	    sleepCount++;
	    break;

	case StrengthWorkoutType:
	    strengthHours += (dynamic_cast<StrengthWorkoutData *>(data))->workoutTime();
	    strengthCount++;
	    break;

	case WorkHoursType:
	    workHours += (dynamic_cast<WorkHoursData *>(data))->hoursWorked();
	    workCount++;
	    break;
	}
    }

    if (cardioCount > 0)
	cardioHours /= cardioCount;

    if (sleepCount > 0)
	sleepHours /= sleepCount;

    if (strengthCount > 0)
	strengthHours /= strengthCount;

    if (workCount > 0)
	workHours /= workCount;

    otherHours = fmaxf(0.0, 24.0 - cardioHours - sleepHours - strengthHours - workHours);

    QStringList activities;

    if (cardioHours > 0)
	activities << "['Cardio Workout', " + QString::number(cardioHours, 'f', 1) + "]";

    if (sleepHours > 0)
	activities << "['Sleep', " + QString::number(sleepHours, 'f', 1) + "]";

    if (strengthHours > 0)
	activities << "['Strength Workout', " + QString::number(strengthHours, 'f', 1) + "]";

    if (workHours > 0)
	activities << "['Work', " + QString::number(workHours, 'f', 1) + "]";

    if (otherHours > 0)
	activities << "['Other', " + QString::number(otherHours, 'f', 1) + "]";

    QString formatted(
	   "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
	   " <html xmlns=\"http://www.w3.org/1999/xhtml\">"
	   "   <head>"
	   "     <meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>"
	   "    <script type=\"text/javascript\" src=\"//www.google.com/jsapi\"></script>"
	   "    <script type=\"text/javascript\">"
	   "      google.load('visualization', '1', {packages: ['corechart']});"
	   "    </script>"
	   "    <script type=\"text/javascript\">"
	   "      function drawVisualization() {"
	   "      var data = google.visualization.arrayToDataTable(["
	   "        ['Activity', 'Average hours per day'],"
	   "        %1"
	   "      ]);"
	   ""
	   "      new google.visualization.PieChart(document.getElementById('visualization'))."
	   "          draw(data, {title:'Average Daily Activity'});"
	   "    }"
	   ""
	   "      google.setOnLoadCallback(drawVisualization);"
	   "    </script>"
	   "  </head>"
	   "  <body style=\"font-family: Arial;border: 0 none;\">"
	   "    <div id=\"visualization\" style=\"margin: 0 auto; width: 500px; height: 400px; border: 1px solid #bbb; background: white;\"></div>"
	   "  </body>"
	   "</html>​"
    );

    return formatted.arg(activities.join(','));
}
