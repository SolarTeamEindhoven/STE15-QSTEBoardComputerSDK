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

#include "ste15-qsteboardcomputersdk_plugin.h"

#include <qglobal.h>
#include <qqml.h>

#include <ControlBarButton>
#include <ControlBarScrollWheel>
#include <BCControlBar>
#include <VehicleApp>
#include <VehicleLauncher>
#include <BCControlBarHardwareInterface>
#include <VehicleAppContainer>
#include <CARSensor>

#define REGISTER(TYPE) qmlRegisterType<TYPE>(uri, version_major, version_minor, QT_STRINGIFY(TYPE))

void STE15_QSTEBoardComputerSDKPlugin::registerTypes(const char *uri)
{
    // @uri nl.solarteameindhoven.sdk
    REGISTER(ControlBarButton);
    REGISTER(ControlBarScrollWheel);
    REGISTER(BCControlBar);
    REGISTER(VehicleApp);
    REGISTER(VehicleLauncher);
    REGISTER(BCControlBarHardwareInterface);
    REGISTER(VehicleAppContainer);
    REGISTER(CARSensor);
}


