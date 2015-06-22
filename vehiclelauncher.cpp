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

#include "bcvehiclelauncher.h"

#include <BCVehicleApp>

BCVehicleLauncher::BCVehicleLauncher(QQuickItem *parent)
    : QQuickItem(parent)
{
    ;
}

BCVehicleLauncher::~BCVehicleLauncher()
{
    ;
}

const QList<BCVehicleApp*>& BCVehicleLauncher::getAppList() const
{
    return apps;
}

void BCVehicleLauncher::addApp(BCVehicleApp* app)
{
    apps.append(app);
    emit appAdded(app);
    emit appsChanged();
}

void BCVehicleLauncher::removeApp(BCVehicleApp* app)
{
    apps.removeAll(app);
    emit appRemoved(app);
    emit appsChanged();
}

QQmlListProperty<BCVehicleApp> BCVehicleLauncher::getApps()
{
    return QQmlListProperty<BCVehicleApp>(this, NULL, &BCVehicleLauncher::CountFunction, &BCVehicleLauncher::AtFunction);
}

int BCVehicleLauncher::CountFunction(QQmlListProperty<BCVehicleApp>* list)
{
    BCVehicleLauncher* launcher = qobject_cast<BCVehicleLauncher*>(list->object);
    return launcher->apps.count();
}

BCVehicleApp* BCVehicleLauncher::AtFunction(QQmlListProperty<BCVehicleApp>* list, int index)
{
    BCVehicleLauncher* launcher = qobject_cast<BCVehicleLauncher*>(list->object);
    return launcher->apps.at(index);
}
