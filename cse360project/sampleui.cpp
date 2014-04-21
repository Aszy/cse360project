#include "sampleui.h"
#include "ui_sampleui.h"

#include "Data/pulseratedata.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

SampleUI::SampleUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SampleUI)
{
    ui->setupUi(this);
}

SampleUI::~SampleUI()
{
    delete ui;
}

void SampleUI::submitPulseRateData()
{
    // Get the attributes.
    int rate = ui->spinPulseRate->value();
    QDate date;
    if (ui->radioToday->isChecked())
        date = QDate::currentDate();
    else
        date = ui->dateSelect->date();

    // Construct a PulseRateData.
    PulseRateData *pulseData = new PulseRateData;
    pulseData->setPulseRate(rate);
    pulseData->setRecordedDate(date);
    qDebug() << pulseData->toString();

    // Push the data to the list.
    dataList << pulseData;

    // Update the UI.
    ui->labelEntries->setText("Entries: " + QString::number(dataList.count()));
    updateListWidget();
    ui->spinPulseRate->setValue(0);
}

void SampleUI::testSave()
{
    // Save
    QString fileName = QFileDialog::getSaveFileName(this,
             "Save some data", "",
             "Health Tracker (*.health);;All Files (*)"
    );

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);

        // Attempt to open the file.
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, "Error saving file", "Couldn't open the file to write");
            return;
        }

        // Serialize the data into the file.
        QDataStream stream(&file);

        foreach (Data *data, dataList)
        {
            // Serialize the data's type.
            stream << data->type();

            switch (data->type())
            {
            case PulseRateType:
                stream << *dynamic_cast<PulseRateData *>(data);
                break;

            default:
                stream << data;
            }
        }

        // Close the file.
        file.close();

        // Notify the user.
        QMessageBox::information(this, "Successfully saved data!", "Saved " + QString::number(dataList.count()) + " entries.");

        // Update the data list.
        qDeleteAll(dataList);
        dataList.clear();
        ui->labelEntries->setText("Entries: " + QString::number(dataList.count()));
        updateListWidget();
    }
}


void SampleUI::testLoad()
{
    // Load
    QString fileName = QFileDialog::getOpenFileName(this,
             "Load some data", "",
             "Health Tracker (*.health);;All Files (*)"
    );

    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);

        // Attempt to open the file.
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, "Error loading file", "Couldn't open the file to read");
            return;
        }

        // Serialize the data into the file.
        QDataStream stream(&file);

        while (!stream.atEnd())
        {
            DataType type;

            // Deserialize the data's type.
            stream >> type;

            switch (type)
            {
                case PulseRateType:
                {
                    PulseRateData *pulseRateData = new PulseRateData;
                    stream >> *pulseRateData;
                    dataList << pulseRateData;
                    qDebug() << "Loaded " + pulseRateData->toString();
                    break;
                }

                default:
                {
                    Data *data = new Data;
                    stream >> *data;
                    dataList << data;
                    qDebug() << "Loaded " + data->toString();
                    break;
                }
            }
        }

        // Close the file.
        file.close();

        // Update the data list.
        ui->labelEntries->setText("Entries: " + QString::number(dataList.count()));
        updateListWidget();

        // Notify the user.
        QMessageBox::information(this, "Successfully loaded data!", "Loaded " + QString::number(dataList.count()) + " entries.");
    }
}

void SampleUI::updateListWidget()
{
    ui->entriesListWidget->clear();

    foreach (Data *data, dataList)
    {
        ui->entriesListWidget->addItem(data->toString());
    }
}
