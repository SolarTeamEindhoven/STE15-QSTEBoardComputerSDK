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

#include <BCControlBarButton>
#include <BCControlBarScrollWheel>
#include <BCControlBar>
#include <BCVehicleApp>
#include <BCVehicleLauncher>
#include <BCControlBarHardwareInterface>
#include <BCVehicleAppContainer>
#include <BCCARSensor>

static constexpr char uri[] = "nl.solarteameindhoven.sdk";
static constexpr int version_major = 1;
static constexpr int version_minor = 0;
//#define REGISTER(TYPE) qmlRegisterType<TYPE>(uri, version_major, version_minor, QT_STRINGIFY(TYPE))
#define REGISTER(TYPE) qmlRegisterType<TYPE>("nl.solarteameindhoven.sdk", version_major, version_minor, QT_STRINGIFY(TYPE))

//*
void STE15_QSTEBoardComputerSDKPlugin::registerTypes(const char *uri)
{
    // @uri nl.solarteameindhoven.sdk
    REGISTER(BCControlBarButton);
    REGISTER(BCControlBarScrollWheel);
    REGISTER(BCControlBar);
    REGISTER(BCVehicleApp);
    REGISTER(BCVehicleLauncher);
    REGISTER(BCControlBarHardwareInterface);
    REGISTER(BCVehicleAppContainer);
    REGISTER(BCCARSensor);
}
//*/

void STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT registerBCSDKQMLTypes()
{
    qDebug() << "Hoi 1";

    // @uri nl.solarteameindhoven.sdk
    REGISTER(BCCARSensor);
    REGISTER(BCControlBarButton);
    REGISTER(BCControlBarHardwareInterface);
    REGISTER(BCControlBarScrollWheel);
    REGISTER(BCControlBar);
    REGISTER(BCVehicleApp);
    REGISTER(BCVehicleLauncher);
    REGISTER(BCVehicleAppContainer);

    qWarning() << "Hoi 2";
}

/*
struct STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT registerQMLTypes_s
{
    registerQMLTypes_s()
    {
        registerBCSDKQMLTypes();
    }
};
static STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT registerQMLTypes_s registerQMLTypes;
//*/
