###########################################################################
##
## Copyright 2015 Solar Team Eindhoven. All rights reserved.
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##   http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
##
###########################################################################

TARGET = STE15-QSTEBoardComputerSDK
TEMPLATE = lib
QT += qml quick
CONFIG += qt c++11
#CONFIG += plugin

#TARGET = $$qtLibraryTarget($$TARGET)
uri = nl.solarteameindhoven.sdk

# Input
SOURCES += \
    ste15-qsteboardcomputersdk_plugin.cpp \
    vehicleapp.cpp \
    bccontrolbar.cpp \
    controlbarbutton.cpp \
    controlbarscrollwheel.cpp \
    vehiclelauncher.cpp \
    vehicleappcontainer.cpp \
    bccontrolbarhardwareinterface.cpp \
    carsensor.cpp

HEADERS += \
    ste15-qsteboardcomputersdk_plugin.h \
    vehicleapp.h \
    VehicleApp \
    bccontrolbar.h \
    BCControlBar \
    controlbarbutton.h \
    ControlBarButton \
    controlbarscrollwheel.h \
    ControlBarScrollWheel \
    vehiclelauncher.h \
    VehicleLauncher \
    vehicleappcontainer.h \
    bccontrolbarhardwareinterface.h \
    carsensor.h \
    CARSensor

DISTFILES = qmldir

STE_BUILD_PATH_PREFIX = $$relative_path($$OUT_PWD)
win32:CONFIG(release, debug|release): STE_BUILD_PATH_PREFIX = $$STE_BUILD_PATH_PREFIX/release
else:win32:CONFIG(debug, debug|release): STE_BUILD_PATH_PREFIX = $$STE_BUILD_PATH_PREFIX/debug/

LIBS += \
        -L$$PWD/../STE15-QSTECANMessage/$$STE_BUILD_PATH_PREFIX -lSTE15-QSTECANMessage

INCLUDEPATH += \
        $$PWD/../STE15-QSTECANMessage/include

DEFINES += STE15QSTEBOARDCOMPUTERSDK_LIBRARY

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = /usr/lib
    INSTALLS += target qmldir
}

