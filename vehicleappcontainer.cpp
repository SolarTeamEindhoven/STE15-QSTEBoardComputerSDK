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

#include "vehicleappcontainer.h"

#include "bccontrolbar.h"
#include "vehicleapp.h"

VehicleAppContainer::VehicleAppContainer(QQuickItem *parent)
    : QQuickItem(parent)
    , app(NULL)
    , bccontrolBarHardwareInterface(NULL)
    , bccontrolBarOpacity(0)
{
    ;
}

VehicleAppContainer::~VehicleAppContainer()
{
    ;
}

VehicleApp* VehicleAppContainer::getApp()
{
    return app;
}

BCControlBarHardwareInterface* VehicleAppContainer::getBCControlBarHardwareInterface()
{
    return bccontrolBarHardwareInterface;
}

double VehicleAppContainer::getBCControlBarOpacity() const
{
    return bccontrolBarOpacity;
}

void VehicleAppContainer::setApp(VehicleApp* newApp)
{
    disconnectAppToBCControlBar(app);

    app = newApp;

    QVariant linkToThis = QVariant::fromValue<VehicleAppContainer*>(this);
    app->setProperty("parent", linkToThis);
    app->property("anchors").value<QObject*>()->setProperty("fill", linkToThis);

    connectAppToBCControlBar(newApp);

    emit appChanged(newApp);
}

void VehicleAppContainer::setBCControlBarHardwareInterface(BCControlBarHardwareInterface* newBCControlBarHardwareInterface)
{
    if(bccontrolBarHardwareInterface)
        disconnect(bccontrolBarHardwareInterface, &BCControlBarHardwareInterface::positionChanged, this, &VehicleAppContainer::bccontrolBarPositionChanged);

    connect(newBCControlBarHardwareInterface, &BCControlBarHardwareInterface::positionChanged, this, &VehicleAppContainer::bccontrolBarPositionChanged);

    disconnectAppToBCControlBar(app);
    bccontrolBarHardwareInterface = newBCControlBarHardwareInterface;
    connectAppToBCControlBar(app);
    emit bccontrolBarHardwareInterfaceChanged(newBCControlBarHardwareInterface);
}

void VehicleAppContainer::setBCControlBarOpacity(double newBCControlBarOpacity)
{
    bccontrolBarOpacity = newBCControlBarOpacity;
    emit bccontrolBarOpacityChanged(newBCControlBarOpacity);
}

void VehicleAppContainer::bccontrolBarPositionChanged(double position)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    qreal controlBarY = position - bccontrolBarHardwareInterface->height();
    qreal topY = y();
    qreal bottomY = topY + height();
    if( topY < controlBarY && controlBarY < bottomY )
    {
        app->getBCControlBar()->setVisible(true);
        //qDebug() << "New position inside app:" << topY << " < " << controlBarY << " < " << bottomY;
    }
    else
    {
        app->getBCControlBar()->setVisible(false);
        //qDebug() << "New position outside app:" << position;
    }
}

void VehicleAppContainer::disconnectAppToBCControlBar(VehicleApp* app)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    if(bccontrolBarHardwareInterface == NULL)
        return;

    disconnect(this, &QQuickItem::widthChanged, this, &VehicleAppContainer::updateControlBarWidth);
}

void VehicleAppContainer::connectAppToBCControlBar(VehicleApp* app)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    if(bccontrolBarHardwareInterface == NULL)
        return;

    connect(this, &QQuickItem::widthChanged, this, &VehicleAppContainer::updateControlBarWidth);
    bccontrolBarHardwareInterface->setWidth(width());

    QVariant link = QVariant::fromValue<BCControlBarHardwareInterface*>(bccontrolBarHardwareInterface);
    app->getBCControlBar()->setProperty("parent", link);
    app->getBCControlBar()->property("anchors").value<QObject*>()->setProperty("fill", link);
}

void VehicleAppContainer::updateControlBarWidth()
{
    bccontrolBarHardwareInterface->setWidth(width());
}

