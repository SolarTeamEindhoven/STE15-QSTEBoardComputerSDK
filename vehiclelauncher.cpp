#include "vehiclelauncher.h"

#include <VehicleApp>

VehicleLauncher::VehicleLauncher(QQuickItem *parent)
    : QQuickItem(parent)
{
    ;
}

VehicleLauncher::~VehicleLauncher()
{
    ;
}

const QList<VehicleApp*>& VehicleLauncher::getAppList() const
{
    return apps;
}

void VehicleLauncher::addApp(VehicleApp* app)
{
    apps.append(app);
    emit appAdded(app);
    emit appsChanged();
}

void VehicleLauncher::removeApp(VehicleApp* app)
{
    apps.removeAll(app);
    emit appRemoved(app);
    emit appsChanged();
}

QQmlListProperty<VehicleApp> VehicleLauncher::getApps()
{
    return QQmlListProperty<VehicleApp>(this, NULL, &VehicleLauncher::CountFunction, &VehicleLauncher::AtFunction);
}

int VehicleLauncher::CountFunction(QQmlListProperty<VehicleApp>* list)
{
    VehicleLauncher* launcher = qobject_cast<VehicleLauncher*>(list->object);
    return launcher->apps.count();
}

VehicleApp* VehicleLauncher::AtFunction(QQmlListProperty<VehicleApp>* list, int index)
{
    VehicleLauncher* launcher = qobject_cast<VehicleLauncher*>(list->object);
    return launcher->apps.at(index);
}
