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

#ifndef VEHICLEAPP_H
#define VEHICLEAPP_H

#include <QQuickItem>

class BCControlBar;

class VehicleApp : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(VehicleApp)

    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString category READ getCategory NOTIFY categoryChanged)

    Q_PROPERTY(BCControlBar* bccontrolbar READ getBCControlBar WRITE setBCControlBar NOTIFY bccontrolbarChanged)

public:
    explicit VehicleApp(QQuickItem *parent = 0);
    ~VehicleApp();

    const QString& getName() const;
    const QString& getDescription() const;
    const QString& getCategory() const;
    BCControlBar* getBCControlBar();

    void setBCControlBar(BCControlBar* bccontrolbar);

signals:
    void nameChanged(const QString& name);
    void descriptionChanged(const QString& description);
    void categoryChanged(const QString& category);
    void bccontrolbarChanged(BCControlBar* bccontrolbar);

public slots:

private:
    QString name;
    QString description;
    QString category;

    BCControlBar* bccontrolbar;
};

#endif // VEHICLEAPP_H

