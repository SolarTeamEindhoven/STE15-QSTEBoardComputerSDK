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

#include <bcsdkcommon.h>

#include <QQuickItem>

class BCVehicleApp;

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT BCVehicleLauncher : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(BCVehicleLauncher)

    Q_PROPERTY(QQmlListProperty<BCVehicleApp> apps READ getApps NOTIFY appsChanged)

public:
    explicit BCVehicleLauncher(QQuickItem* parent = NULL);
    ~BCVehicleLauncher();

    const QList<BCVehicleApp*>& getAppList() const;
    Q_INVOKABLE void addApp(BCVehicleApp* app);
    Q_INVOKABLE void removeApp(BCVehicleApp* app);

signals:
    void appsChanged();
    void appAdded(BCVehicleApp*);
    void appRemoved(BCVehicleApp*);

public slots:

private:
    QList<BCVehicleApp*> apps;

    QQmlListProperty<BCVehicleApp> getApps();
    static int CountFunction(QQmlListProperty<BCVehicleApp>* list);
    static BCVehicleApp* AtFunction(QQmlListProperty<BCVehicleApp>* list, int index);
};

#endif // VEHICLELAUNCHER_H
