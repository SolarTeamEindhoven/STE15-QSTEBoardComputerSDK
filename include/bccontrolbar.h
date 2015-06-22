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

#ifndef BCCONTROLBAR_H
#define BCCONTROLBAR_H

#include <bcsdkcommon.h>

#include <QQuickItem>

class BCControlBarButton;
class BCControlBarScrollWheel;

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT BCControlBar : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(BCControlBar)

    Q_PROPERTY(BCControlBarButton* leftButton READ getLeftButton WRITE setLeftButton NOTIFY leftButtonChanged)
    Q_PROPERTY(BCControlBarButton* middleButton READ getMiddleButton WRITE setMiddleButton NOTIFY middleButtonChanged)
    Q_PROPERTY(BCControlBarButton* rightButton READ getRightButton WRITE setRightButton NOTIFY rightButtonChanged)

    Q_PROPERTY(BCControlBarScrollWheel* leftScrollWheel READ getLeftScrollWheel WRITE setLeftScrollWheel NOTIFY leftScrollWheelChanged)
    Q_PROPERTY(BCControlBarScrollWheel* rightScrollWheel READ getRightScrollWheel WRITE setRightScrollWheel NOTIFY rightScrollWheelChanged)

    Q_CLASSINFO("DefaultProperty", "null")

public:
    static constexpr double ButtonRadius_mm = 20;
    //static constexpr double LeftButtonLocationX_mm = 30;
    //static constexpr double MiddleButtonLocationX_mm = 70;
    //static constexpr double RightButtonLocationX_mm = 110;

    static constexpr double ScrollWheelRadius_mm = 35;
    static constexpr double ScrollWheelLocationY_mm = -20;
    static constexpr double LeftScrollWheelLocationX_mm = -10;
    static constexpr double RightScrollWheelLocationX_mm = 100;

    explicit BCControlBar(QQuickItem *parent = 0);
    ~BCControlBar();

    BCControlBarButton* getLeftButton();
    BCControlBarButton* getMiddleButton();
    BCControlBarButton* getRightButton();

    BCControlBarScrollWheel* getLeftScrollWheel();
    BCControlBarScrollWheel* getRightScrollWheel();

    void setLeftButton(BCControlBarButton* newLeftButton);
    void setMiddleButton(BCControlBarButton* newMiddleButton);
    void setRightButton(BCControlBarButton* newRightButton);

    void setLeftScrollWheel(BCControlBarScrollWheel* newLeftScrollWheel);
    void setRightScrollWheel(BCControlBarScrollWheel* newRightScrollWheel);

signals:
    void leftButtonChanged(BCControlBarButton* newLeftButton);
    void middleButtonChanged(BCControlBarButton* newMiddleButton);
    void rightButtonChanged(BCControlBarButton* newRightButton);

    void leftScrollWheelChanged(BCControlBarScrollWheel* newLeftScrollWheel);
    void rightScrollWheelChanged(BCControlBarScrollWheel* newRightScrollWheel);

public slots:

private slots:
    void handleWindowChanged(QQuickWindow*);
    void handleParentChanged(QQuickItem*);
    void updateWidth();

private:
    BCControlBarButton* leftButton;
    BCControlBarButton* middleButton;
    BCControlBarButton* rightButton;

    BCControlBarScrollWheel* leftScrollWheel;
    BCControlBarScrollWheel* rightScrollWheel;

    void setParentToThis(QQuickItem* item);

    double getDpmm();

    void updateLeftButtonProperties(double dpmm);
    void updateMiddleButtonProperties(double dpmm);
    void updateRightButtonProperties(double dpmm);
    void updateLeftScrollWheelProperties(double dpmm);
    void updateRightScrollWheelProperties(double dpmm);

    void updateDpiProperties();
    void updateButtonDpiProperties(BCControlBarButton* button, double location, double dpmm);
    void updateScrollWheelDpiProperties(BCControlBarScrollWheel* scrollWheel, double location, double dpmm);
};

#endif // BCCONTROLBAR_H
