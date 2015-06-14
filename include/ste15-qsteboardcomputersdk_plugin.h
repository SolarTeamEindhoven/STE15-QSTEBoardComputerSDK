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

#ifndef STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H
#define STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H

#include <QQmlExtensionPlugin>

#include <QtCore/qglobal.h>

#if defined(STE15QSTEBOARDCOMPUTERSDK_LIBRARY)
#  define STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT Q_DECL_EXPORT
#else
#  define STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT Q_DECL_IMPORT
#endif

class STE15QSTEBOARDCOMPUTERSDKSHARED_EXPORT STE15_QSTEBoardComputerSDKPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);

    static constexpr int version_major = 1;
    static constexpr int version_minor = 0;
};

#endif // STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H

