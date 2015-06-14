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

#ifndef CARSENSOR_H
#define CARSENSOR_H

#include "ste15-qsteboardcomputersdk_plugin.h"

#include <QQuickItem>
#include <SensorIDs.h>

class QCANMessage;

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT CARSensor : public QQuickItem
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
