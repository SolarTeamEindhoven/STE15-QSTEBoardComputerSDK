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

#include "bccontrolbarhardwareinterface.h"

#include <QQuickWindow>
#include <QScreen>

static constexpr double inch2mmh = 25.4;

QVector<BCControlBarHardwareInterface*> BCControlBarHardwareInterface::bccontrolBarHardwareInterfaceList;
std::function<void(const QList<double>&)> BCControlBarHardwareInterface::feedbackPositionsChangedCallback;

double BCControlBarHardwareInterface::position = 0;
double BCControlBarHardwareInterface::topPosition = 0;
double BCControlBarHardwareInterface::bottomPosition = 0;
QList<double> BCControlBarHardwareInterface::feedbackPositions;

BCControlBarHardwareInterface::BCControlBarHardwareInterface(QQuickItem* parent)
    : QQuickItem(parent)
{
    /*
    connect(this, &BCControlBarHardwareInterface::positionChanged, this, &BCControlBarHardwareInterface::updateY);
    connect(this, &QQuickItem::windowChanged, this, &BCControlBarHardwareInterface::handleWindowChanged);

    bccontrolBarHardwareInterfaceList.append(this);
    */
}

BCControlBarHardwareInterface::~BCControlBarHardwareInterface()
{
    bccontrolBarHardwareInterfaceList.removeAll(this);
}

const QList<double>& BCControlBarHardwareInterface::getFeedbackPositions() const
{
    return feedbackPositions;
}

void BCControlBarHardwareInterface::setFeedbackPositions(const QList<double>& newFeedbackPositions)
{
    feedbackPositions = newFeedbackPositions;

    if(feedbackPositionsChangedCallback)
        feedbackPositionsChangedCallback(newFeedbackPositions);

    foreach(BCControlBarHardwareInterface* entry, bccontrolBarHardwareInterfaceList)
    {
        emit entry->feedbackPositionsChanged(newFeedbackPositions);
    }
}

double BCControlBarHardwareInterface::getTopPosition() const
{
    return topPosition;
}
void BCControlBarHardwareInterface::setTopPosition(double newTopPosition)
{
    topPosition = newTopPosition;
    foreach(BCControlBarHardwareInterface* entry, bccontrolBarHardwareInterfaceList)
    {
        emit entry->topPositionChanged(newTopPosition);
    }
}

double BCControlBarHardwareInterface::getBottomPosition() const
{
    return bottomPosition;
}
void BCControlBarHardwareInterface::setBottomPosition(double newBottomPosition)
{
    bottomPosition = newBottomPosition;
    foreach(BCControlBarHardwareInterface* entry, bccontrolBarHardwareInterfaceList)
    {
        emit entry->bottomPositionChanged(newBottomPosition);
    }
}

void BCControlBarHardwareInterface::handleWindowChanged(QQuickWindow* window)
{
    if(window == NULL)
        return;

    QScreen* screen = window->screen();
    double dpmm = screen->physicalDotsPerInchY() / inch2mmh; // Dots Per MiliMeter

    this->setHeight(barHeight_mm * dpmm);
    this->setWidth(screen->size().width());
}

double BCControlBarHardwareInterface::getPosition() const
{
    return position;
}

void BCControlBarHardwareInterface::setPosition(double position)
{
    foreach(BCControlBarHardwareInterface* entry, bccontrolBarHardwareInterfaceList)
    {
        entry->position = position;
        emit entry->positionChanged(position);
    }
}

void BCControlBarHardwareInterface::updateY()
{
    setY(position - height());
}

