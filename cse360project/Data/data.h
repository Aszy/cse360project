#ifndef DATA_H
#define DATA_H

#include <QDate>
#include <QDataStream>

class Data
{
public:
    explicit Data();

    // Accessors
    QDate recordedDate() const { return _recordedDate; }
    void setRecordedDate(const QDate recordedDate) { _recordedDate = recordedDate; }

    virtual QString type() const;

    virtual QString toString();

signals:

public slots:

private:
    QDate _recordedDate;

};

// Serialization
QDataStream &operator<<(QDataStream &out, const Data &data);
QDataStream &operator>>(QDataStream &in, Data &data);

#endif // DATA_H
