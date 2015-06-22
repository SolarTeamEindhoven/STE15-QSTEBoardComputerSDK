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

#ifndef VEHICLEAPPCONTAINER_H
#define VEHICLEAPPCONTAINER_H

#include <bcsdkcommon.h>

#include <QQuickItem>

#include <BCControlBarHardwareInterface>

class BCVehicleApp;

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT BCVehicleAppContainer : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(BCVehicleApp* app READ getApp WRITE setApp NOTIFY appChanged)
    Q_PROPERTY(BCControlBarHardwareInterface* bccontrolBarHardwareInterface READ getBCControlBarHardwareInterface WRITE setBCControlBarHardwareInterface NOTIFY bccontrolBarHardwareInterfaceChanged)
    Q_PROPERTY(double bccontrolBarOpacity READ getBCControlBarOpacity WRITE setBCControlBarOpacity NOTIFY bccontrolBarOpacityChanged)

public:
    explicit BCVehicleAppContainer(QQuickItem* parent = NULL);
    ~BCVehicleAppContainer();

    BCVehicleApp* getApp();
    BCControlBarHardwareInterface* getBCControlBarHardwareInterface();
    double getBCControlBarOpacity() const;

    void setApp(BCVehicleApp*);
    void setBCControlBarHardwareInterface(BCControlBarHardwareInterface*);
    void setBCControlBarOpacity(double);

signals:
    void appChanged(BCVehicleApp*);
    void bccontrolBarHardwareInterfaceChanged(BCControlBarHardwareInterface*);
    void bccontrolBarOpacityChanged(double);

public slots:

private slots:
    void bccontrolBarPositionChanged(double position);
    void updateControlBarWidth();

private:
    BCVehicleApp* app;
    BCControlBarHardwareInterface* bccontrolBarHardwareInterface;
    double bccontrolBarOpacity;

    void disconnectAppToBCControlBar(BCVehicleApp* app);
    void connectAppToBCControlBar(BCVehicleApp* app);
};

#endif // VEHICLEAPPCONTAINER_H
