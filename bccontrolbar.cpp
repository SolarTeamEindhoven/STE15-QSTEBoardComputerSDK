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

#include "bccontrolbar.h"

#include <cmath>
#include <limits>

#include <QVariant>
#include <QQuickWindow>
#include <QScreen>

#include <BCControlBarButton>
#include <BCControlBarScrollWheel>

static constexpr double inch2mmh = 25.4;

BCControlBar::BCControlBar(QQuickItem *parent)
    : QQuickItem(parent)
    , leftButton(NULL)
    , middleButton(NULL)
    , rightButton(NULL)
    , leftScrollWheel(NULL)
    , rightScrollWheel(NULL)
{
    connect(this, &QQuickItem::windowChanged, this, &BCControlBar::handleWindowChanged);
    connect(this, &QQuickItem::parentChanged, this, &BCControlBar::handleParentChanged);
}

BCControlBar::~BCControlBar()
{
    ;
}

BCControlBarButton* BCControlBar::getLeftButton()
{
    return leftButton;
}

BCControlBarButton* BCControlBar::getMiddleButton()
{
    return middleButton;
}

BCControlBarButton* BCControlBar::getRightButton()
{
    return rightButton;
}

BCControlBarScrollWheel* BCControlBar::getLeftScrollWheel()
{
    return leftScrollWheel;
}

BCControlBarScrollWheel* BCControlBar::getRightScrollWheel()
{
    return rightScrollWheel;
}

void BCControlBar::setLeftButton(BCControlBarButton* newLeftButton)
{
    setParentToThis(newLeftButton);

    QObject* anchors = newLeftButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateLeftButtonProperties(getDpmm());

    leftButton = newLeftButton;
    emit leftButtonChanged(newLeftButton);
}

void BCControlBar::setMiddleButton(BCControlBarButton* newMiddleButton)
{
    setParentToThis(newMiddleButton);

    QObject* anchors = newMiddleButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateMiddleButtonProperties(getDpmm());

    middleButton = newMiddleButton;
    emit middleButtonChanged(newMiddleButton);
}

void BCControlBar::setRightButton(BCControlBarButton* newRightButton)
{
    setParentToThis(newRightButton);

    QObject* anchors = newRightButton->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateRightButtonProperties(getDpmm());

    rightButton = newRightButton;
    emit rightButtonChanged(newRightButton);
}

void BCControlBar::setLeftScrollWheel(BCControlBarScrollWheel* newLeftScrollWheel)
{
    setParentToThis(newLeftScrollWheel);

    QObject* anchors = newLeftScrollWheel->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateLeftScrollWheelProperties(getDpmm());

    leftScrollWheel = newLeftScrollWheel;
    emit leftScrollWheelChanged(newLeftScrollWheel);
}

void BCControlBar::setRightScrollWheel(BCControlBarScrollWheel* newRightScrollWheel)
{
    setParentToThis(newRightScrollWheel);

    QObject* anchors = newRightScrollWheel->property("anchors").value<QObject*>();
    anchors->setProperty("verticalCenter", this->property("top"));
    anchors->setProperty("horizontalCenter", this->property("left"));

    updateRightScrollWheelProperties(getDpmm());

    rightScrollWheel = newRightScrollWheel;
    emit rightScrollWheelChanged(newRightScrollWheel);
}

void BCControlBar::handleWindowChanged(QQuickWindow*)
{
    updateDpiProperties();
}

void BCControlBar::handleParentChanged(QQuickItem* newParent)
{
    disconnect(parentItem(), &QQuickItem::widthChanged, this, &BCControlBar::updateWidth);
    connect(newParent, &QQuickItem::widthChanged, this, &BCControlBar::updateWidth);

    updateWidth();
}

void BCControlBar::updateWidth()
{
    setWidth(parentItem()->width());
    updateDpiProperties();
}

double BCControlBar::getDpmm()
{
    QQuickWindow* window = this->window();

    if(window == NULL)
        return std::numeric_limits<double>::quiet_NaN();

    return window->screen()->physicalDotsPerInchY() / inch2mmh;
}

void BCControlBar::updateLeftButtonProperties(double dpmm)
{
    updateButtonDpiProperties(leftButton,   width() * 1 / 6, dpmm);
}

void BCControlBar::updateMiddleButtonProperties(double dpmm)
{
    updateButtonDpiProperties(middleButton, width() * 3 / 6, dpmm);
}

void BCControlBar::updateRightButtonProperties(double dpmm)
{
    updateButtonDpiProperties(rightButton,  width() * 5 / 6, dpmm);
}

void BCControlBar::updateLeftScrollWheelProperties(double dpmm)
{
    updateScrollWheelDpiProperties(leftScrollWheel, LeftScrollWheelLocationX_mm * dpmm, dpmm);
}

void BCControlBar::updateRightScrollWheelProperties(double dpmm)
{
    updateScrollWheelDpiProperties(rightScrollWheel, RightScrollWheelLocationX_mm * dpmm, dpmm);
}

void BCControlBar::updateDpiProperties()
{
    double dpmm = getDpmm();

    if(std::isnan(dpmm))
        return;

    updateLeftButtonProperties(dpmm);
    updateMiddleButtonProperties(dpmm);
    updateRightButtonProperties(dpmm);
    updateLeftScrollWheelProperties(dpmm);
    updateRightScrollWheelProperties(dpmm);
}

void BCControlBar::setParentToThis(QQuickItem* item)
{
    QVariant link = QVariant::fromValue<BCControlBar*>(this);
    item->setProperty("parent", link);
}

void BCControlBar::updateButtonDpiProperties(BCControlBarButton* button, double location, double dpmm)
{
    if(button == NULL)
        return;

    QObject* anchors = button->property("anchors").value<QObject*>();
    anchors->setProperty("horizontalCenterOffset", location);
    button->setProperty("width", ButtonRadius_mm * dpmm);
    button->setProperty("height", ButtonRadius_mm * dpmm);
}

void BCControlBar::updateScrollWheelDpiProperties(BCControlBarScrollWheel* scrollWheel, double location, double dpmm)
{
    if(scrollWheel == NULL)
        return;

    QObject* anchors = scrollWheel->property("anchors").value<QObject*>();
    anchors->setProperty("horizontalCenterOffset", location);
    anchors->setProperty("verticalCenterOffset", ScrollWheelLocationY_mm * dpmm);
    scrollWheel->setProperty("width", ScrollWheelRadius_mm * dpmm);
    scrollWheel->setProperty("height", ScrollWheelRadius_mm * dpmm);
}
