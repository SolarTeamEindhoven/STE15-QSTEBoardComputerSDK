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

#ifndef VEHICLELAUNCHER_H
#define VEHICLELAUNCHER_H

#include "ste15-qsteboardcomputersdk_plugin.h"

#include <QQuickItem>

class VehicleApp;

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT VehicleLauncher : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(VehicleLauncher)

    Q_PROPERTY(QQmlListProperty<VehicleApp> apps READ getApps NOTIFY appsChanged)

public:
    explicit VehicleLauncher(QQuickItem* parent = NULL);
    ~VehicleLauncher();

    const QList<VehicleApp*>& getAppList() const;
    Q_INVOKABLE void addApp(VehicleApp* app);
    Q_INVOKABLE void removeApp(VehicleApp* app);

signals:
    void appsChanged();
    void appAdded(VehicleApp*);
    void appRemoved(VehicleApp*);

public slots:

private:
    QList<VehicleApp*> apps;

    QQmlListProperty<VehicleApp> getApps();
    static int CountFunction(QQmlListProperty<VehicleApp>* list);
    static VehicleApp* AtFunction(QQmlListProperty<VehicleApp>* list, int index);
};

#endif // VEHICLELAUNCHER_H
