#include "report.h"

Report::Report(QList<Data *> repository, QDate start, QDate end)
{
    _start = start;
    _end = end;
}

QString Report::graphHtmlTemplate(QStringList headers, QList<QStringList> data)
{
    for (int i = 0; i < headers.size(); i++)
        headers.replace(i, "'" + headers.at(i) + "'");

    QStringList dataRowsList;
    for (int i = 0; i < data.size(); i++)
        dataRowsList << "[" + data.at(i).join(", ") + "]";

    QString headerRow = headers.join(", ");
    QString dataRows = dataRowsList.join(", ");
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
           "        var data = google.visualization.arrayToDataTable(["
           "          [%1],"
           "           %2"
           "        ]);"
           ""
           "        new google.visualization.LineChart(document.getElementById('visualization'))."
           "            draw(data, {width: 500, height: 400, backgroundColor: 'transparent'});"
           "      }"
           ""
           "      google.setOnLoadCallback(drawVisualization);"
           "    </script>"
           "  </head>"
           "  <body style=\"font-family: Arial;border: 0 none;\">"
           "    <div id=\"visualization\" style=\"margin: -50px auto 0 auto; width: 500px; height: 400px;\"></div>"
           "  </body>"
           "</html>​"
    );

    return formatted.arg(headerRow, dataRows);
}
