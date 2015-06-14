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

#ifndef CONTROLBARBUTTON_H
#define CONTROLBARBUTTON_H

#include "ste15-qsteboardcomputersdk_plugin.h"

#include <QQuickItem>

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT ControlBarButton : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ControlBarButton)

public:
    explicit ControlBarButton(QQuickItem *parent = 0);
    virtual ~ControlBarButton();

signals:

public slots:

private:
};

#endif // CONTROLBARBUTTON_H
