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

#include "bcvehicleapp.h"

#include <BCControlBar>

BCVehicleApp::BCVehicleApp(QQuickItem *parent)
    : QQuickItem(parent)
    , bccontrolbar(NULL)
{
    ;
}

BCVehicleApp::~BCVehicleApp()
{
    ;
}

const QString& BCVehicleApp::getName() const
{
    return name;
}

const QString& BCVehicleApp::getDescription() const
{
    return description;
}

const QString& BCVehicleApp::getCategory() const
{
    return category;
}

BCControlBar* BCVehicleApp::getBCControlBar()
{
    return bccontrolbar;
}

void BCVehicleApp::setBCControlBar(BCControlBar* newBCControlbar)
{
    bccontrolbar = newBCControlbar;
    emit bccontrolbarChanged(newBCControlbar);
}

