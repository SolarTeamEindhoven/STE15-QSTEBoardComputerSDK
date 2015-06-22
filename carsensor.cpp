/**************************************************************************
 **
 ** Copyright 2015 Solar Team Eindhoven. All rights reserved.
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **   http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 **
 **************************************************************************/

#include "bccarsensor.h"

#include <QCANMessage>

QList<BCCARSensor*> BCCARSensor::CARSensorList;

BCCARSensor::BCCARSensor(QQuickItem *parent)
    : QQuickItem(parent)
{
    CARSensorList.append(this);
}

BCCARSensor::~BCCARSensor()
{
    CARSensorList.removeOne(this);
}

BCCARSensor::SensorType BCCARSensor::getID()
{
    return id;
}

void BCCARSensor::setID(BCCARSensor::SensorType newID)
{
    id = newID;
    emit idChanged(id);
}

const QVariantMap& BCCARSensor::getData()
{
    return data;
}

void BCCARSensor::processCANMessage(const QCANMessage& CANMessage)
{
    foreach(BCCARSensor* sensor, CARSensorList)
    {
        if(sensor->id == CANMessage.getID())
        {
            sensor->data = CANMessage.getData();
            emit sensor->dataChanged(sensor->data);
        }
    }
}
