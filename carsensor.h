#ifndef CARSENSOR_H
#define CARSENSOR_H

#include <QQuickItem>
#include <SensorIDs.h>

class QCANMessage;

class CARSensor : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(CARSensor)

    Q_PROPERTY(SensorType id READ getID WRITE setID NOTIFY idChanged)
    Q_PROPERTY(QVariantMap data READ getData NOTIFY dataChanged)

public:
    typedef STE2015::SensorID_t SensorType;
    Q_ENUMS(SensorType)
    explicit CARSensor(QQuickItem* parent = NULL);
    ~CARSensor();

    STE2015::SensorID_t getID();
    void setID(SensorType newID);

    const QVariantMap& getData();

signals:
    void idChanged(SensorType id);
    void dataChanged(const QVariantMap& data);

public slots:
    static void processCANMessage(const QCANMessage& CANMessage);

private:
    static QList<CARSensor*> CARSensorList;
    QVariantMap data;

    STE2015::SensorID_t id;
};

#endif // CARSENSOR_H
