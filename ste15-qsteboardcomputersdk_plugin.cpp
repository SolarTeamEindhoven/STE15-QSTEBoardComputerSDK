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


