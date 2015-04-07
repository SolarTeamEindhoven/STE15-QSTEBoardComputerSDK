#include "carsensor.h"

#include <QCANMessage>

QList<CARSensor*> CARSensor::CARSensorList;

CARSensor::CARSensor(QQuickItem *parent)
    : QQuickItem(parent)
{
    CARSensorList.append(this);
}

CARSensor::~CARSensor()
{
    CARSensorList.removeOne(this);
}

CARSensor::SensorType CARSensor::getID()
{
    return id;
}

void CARSensor::setID(CARSensor::SensorType newID)
{
    id = newID;
    emit idChanged(id);
}

const QVariantMap& CARSensor::getData()
{
    return data;
}

void CARSensor::processCANMessage(const QCANMessage& CANMessage)
{
    foreach(CARSensor* sensor, CARSensorList)
    {
        if(sensor->id == CANMessage.getID())
        {
            sensor->data = CANMessage.getData();
            emit sensor->dataChanged(sensor->data);
        }
    }
}
