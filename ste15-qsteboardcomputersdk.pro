TEMPLATE = lib
TARGET = STE15-QSTEBoardComputerSDK
QT += qml quick
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
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
    VehicleAppContainer \
    bccontrolbarhardwareinterface.cpp \
    BCControlBarHardwareInterface \
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

LIBS += -lcanlib \
        -L$$PWD/../STE15-QSTECANMessage/build/debug/ -lSTE15-QSTECANMessage \
        -L$$PWD/../STE15-QKvaserInterface/build/debug/ -lSTE15-QKvaserInterface

INCLUDEPATH += \
        $$PWD/../STE15-QSTECANMessage/include \
        $$PWD/../STE15-QKvaserInterface

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
    target.path = $$installPath
    INSTALLS += target qmldir
}

