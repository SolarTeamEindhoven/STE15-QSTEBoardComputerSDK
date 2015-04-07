#ifndef STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H
#define STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H

#include <QQmlExtensionPlugin>

class STE15_QSTEBoardComputerSDKPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);

    static constexpr int version_major = 1;
    static constexpr int version_minor = 0;
};

#endif // STE15_QSTEBOARDCOMPUTERSDK_PLUGIN_H

