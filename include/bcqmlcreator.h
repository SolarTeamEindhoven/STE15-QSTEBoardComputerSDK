#ifndef BCQMLCREATOR_H
#define BCQMLCREATOR_H

// Qt includes
#include <QObject>

// STE includes
#include <BCAppDescriptor>
#include <BCLauncherDescriptor>
#include <BCVehicleApp>
#include <BCVehicleLauncher>
#include <QQmlEngine>

class BCQMLCreator
{
public:
    BCQMLCreator();
    ~BCQMLCreator();

    static BCVehicleApp* constructQMLAppObject(const BCAppDescriptor& description);
    static BCVehicleLauncher* constructQMLLauncherObject(const BCLauncherDescriptor& description);
    static void setEngine(QQmlEngine* engine);
private:
    static bool loadDLFiles(QList<QString> dynLibFiles);
    static QQmlEngine* engine;
};

#endif // BCQMLCREATOR_H
