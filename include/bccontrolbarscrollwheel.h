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

#ifndef CONTROLBARSCROLLWHEEL_H
#define CONTROLBARSCROLLWHEEL_H

#include <bcsdkcommon.h>

#include <QQuickItem>

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT BCControlBarScrollWheel : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(BCControlBarScrollWheel)

public:
    static constexpr double singleTickRotationAngle = 20;

    explicit BCControlBarScrollWheel(QQuickItem *parent = 0);
    ~BCControlBarScrollWheel();

signals:
    void rotation(double angle);

public slots:
    void rotateUp();
    void rotateDown();
};

#endif // CONTROLBARSCROLLWHEEL_H
