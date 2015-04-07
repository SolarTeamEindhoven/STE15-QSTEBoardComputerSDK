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

    qDebug() << "Should disconnect stuff now...";
    // TODO: Actual disconnect...
}

void VehicleAppContainer::connectAppToBCControlBar(VehicleApp* app)
{
    if(app == NULL)
        return;

    if(app->getBCControlBar() == NULL)
        return;

    if(bccontrolBarHardwareInterface == NULL)
        return;

    QVariant link = QVariant::fromValue<BCControlBarHardwareInterface*>(bccontrolBarHardwareInterface);
    app->getBCControlBar()->setProperty("parent", link);
    app->getBCControlBar()->property("anchors").value<QObject*>()->setProperty("fill", link);
}

