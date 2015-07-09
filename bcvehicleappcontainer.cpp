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

#include "bcvehicleappcontainer.h"

#include "bccontrolbar.h"
#include "bcvehicleapp.h"

BCVehicleAppContainer::BCVehicleAppContainer(QQuickItem *parent)
    : QQuickItem(parent)
    , app(NULL)
    , bccontrolBarHardwareInterface(NULL)
    , bccontrolBarOpacity(0)
{
    setFlags(ItemClipsChildrenToShape);
    setClip(true);
}

BCVehicleAppContainer::~BCVehicleAppContainer()
{
    ;
}

BCVehicleApp* BCVehicleAppContainer::getApp()
{
    return app;
}

BCControlBarHardwareInterface* BCVehicleAppContainer::getBCControlBarHardwareInterface()
{
    return bccontrolBarHardwareInterface;
}

double BCVehicleAppContainer::getBCControlBarOpacity() const
{
    return bccontrolBarOpacity;
}

void BCVehicleAppContainer::setApp(BCVehicleApp* newApp)
{
    disconnectAppToBCControlBar(app);
    if (newApp == NULL)
    {
        return;
    }
    newApp->setParentItem(this);
    app = newApp;

//    QVariant linkToThis = QVariant::fromValue<BCVehicleAppContainer*>(this);
//    app->setProperty("parent", linkToThis);
//    app->property("anchors").value<QObject*>()->setProperty("fill", linkToThis);

    connectAppToBCControlBar(newApp);

    emit appChanged(newApp);
}

void BCVehicleAppContainer::setBCControlBarHardwareInterface(BCControlBarHardwareInterface* newBCControlBarHardwareInterface)
{
    if(bccontrolBarHardwareInterface)
        disconnect(bccontrolBarHardwareInterface, &BCControlBarHardwareInterface::positionChanged, this, &BCVehicleAppContainer::bccontrolBarPositionChanged);

    connect(newBCControlBarHardwareInterface, &BCControlBarHardwareInterface::positionChanged, this, &BCVehicleAppContainer::bccontrolBarPositionChanged);

    disconnectAppToBCControlBar(app);
    bccontrolBarHardwareInterface = newBCControlBarHardwareInterface;
    connectAppToBCControlBar(app);
    emit bccontrolBarHardwareInterfaceChanged(newBCControlBarHardwareInterface);
}

void BCVehicleAppContainer::setBCControlBarOpacity(double newBCControlBarOpacity)
{
    bccontrolBarOpacity = newBCControlBarOpacity;
    emit bccontrolBarOpacityChanged(newBCControlBarOpacity);
}

void BCVehicleAppContainer::bccontrolBarPositionChanged(double position)
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

void BCVehicleAppContainer::disconnectAppToBCControlBar(BCVehicleApp* app)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    if(bccontrolBarHardwareInterface == NULL)
        return;

    disconnect(this, &QQuickItem::widthChanged, this, &BCVehicleAppContainer::updateControlBarWidth);
}

void BCVehicleAppContainer::connectAppToBCControlBar(BCVehicleApp* app)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    if(bccontrolBarHardwareInterface == NULL)
        return;

    connect(this, &QQuickItem::widthChanged, this, &BCVehicleAppContainer::updateControlBarWidth);
    bccontrolBarHardwareInterface->setWidth(width());

    app->getBCControlBar()->setParentItem(bccontrolBarHardwareInterface);

//    QVariant link = QVariant::fromValue<BCVehicleAppContainer*>(this);
    QVariant link = QVariant::fromValue<BCControlBarHardwareInterface*>(bccontrolBarHardwareInterface);
//    app->getBCControlBar()->setProperty("parent", link);
    app->getBCControlBar()->property("anchors").value<QObject*>()->setProperty("fill", link);
}

void BCVehicleAppContainer::updateControlBarWidth()
{
    bccontrolBarHardwareInterface->setWidth(width());
}

