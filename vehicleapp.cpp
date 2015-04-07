#include "vehicleapp.h"

#include <BCControlBar>

VehicleApp::VehicleApp(QQuickItem *parent)
    : QQuickItem(parent)
    , bccontrolbar(NULL)
{
    ;
}

VehicleApp::~VehicleApp()
{
    ;
}

const QString& VehicleApp::getName() const
{
    return name;
}

const QString& VehicleApp::getDescription() const
{
    return description;
}

const QString& VehicleApp::getCategory() const
{
    return category;
}

BCControlBar* VehicleApp::getBCControlBar()
{
    return bccontrolbar;
}

void VehicleApp::setBCControlBar(BCControlBar* newBCControlbar)
{
    bccontrolbar = newBCControlbar;
    emit bccontrolbarChanged(newBCControlbar);
}

