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

#include <QQuickItem>

#include <BCControlBarHardwareInterface>

class VehicleApp;

class VehicleAppContainer : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(VehicleApp* app READ getApp WRITE setApp NOTIFY appChanged)
    Q_PROPERTY(BCControlBarHardwareInterface* bccontrolBarHardwareInterface READ getBCControlBarHardwareInterface WRITE setBCControlBarHardwareInterface NOTIFY bccontrolBarHardwareInterfaceChanged)
    Q_PROPERTY(double bccontrolBarOpacity READ getBCControlBarOpacity WRITE setBCControlBarOpacity NOTIFY bccontrolBarOpacityChanged)

public:
    explicit VehicleAppContainer(QQuickItem* parent = NULL);
    ~VehicleAppContainer();

    VehicleApp* getApp();
    BCControlBarHardwareInterface* getBCControlBarHardwareInterface();
    double getBCControlBarOpacity() const;

    void setApp(VehicleApp*);
    void setBCControlBarHardwareInterface(BCControlBarHardwareInterface*);
    void setBCControlBarOpacity(double);

signals:
    void appChanged(VehicleApp*);
    void bccontrolBarHardwareInterfaceChanged(BCControlBarHardwareInterface*);
    void bccontrolBarOpacityChanged(double);

public slots:

private slots:
    void bccontrolBarPositionChanged(double position);

private:
    VehicleApp* app;
    BCControlBarHardwareInterface* bccontrolBarHardwareInterface;
    double bccontrolBarOpacity;

    void disconnectAppToBCControlBar(VehicleApp* app);
    void connectAppToBCControlBar(VehicleApp* app);
};

#endif // VEHICLEAPPCONTAINER_H
