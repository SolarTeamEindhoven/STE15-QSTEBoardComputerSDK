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
