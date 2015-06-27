#include "bclaunchermanager.h"

// Qt includes
#include <QVector>
#include <QUrl>

// STE Includes
#include <BCQMLCreator>
#include <BCSettingsManager>

BCLauncherManager::BCLauncherManager(QObject* parent)
    : QObject(parent)
{
    instances.append(this);
}

BCLauncherManager::~BCLauncherManager()
{
    instances.removeAll(this);
}

QQmlListProperty<BCLauncherDescriptor> BCLauncherManager::getAvailableLaunchers()
{
    return QQmlListProperty<BCLauncherDescriptor>(this, NULL, &BCLauncherManager::CountFunction, &BCLauncherManager::AtFunction);
}

BCVehicleLauncher* BCLauncherManager::createLauncher(BCLauncherDescriptor* description)
{
    return BCQMLCreator::constructQMLLauncherObject(*description);
}

QString BCLauncherManager::uniqueIdentifier(const QString& name)
{
    QString identifier = name;
    unsigned int suffixCount = 2;
    std::vector<BCLauncherDescriptor>::const_iterator it = descriptors.begin();

    while(it != descriptors.end())
    {
        if( (*it).getIdentifier() == identifier )
        {
            identifier = name + "_" + QString::number(suffixCount);
            suffixCount++;
            it = descriptors.begin();
        }
        else
        {
            it++;
        }
    }

    return identifier;
}

int BCLauncherManager::CountFunction(QQmlListProperty<BCLauncherDescriptor>*)
{
    return BCLauncherManager::descriptors.size();
}

BCLauncherDescriptor* BCLauncherManager::AtFunction(QQmlListProperty<BCLauncherDescriptor>*, int index)
{
    return &BCLauncherManager::descriptors.at(index);
}

BCLauncherDescriptor* BCLauncherManager::appendLauncher(const BCLauncherDescriptor& newLauncher)
{
    BCLauncherDescriptor* result;

    descriptors.push_back(newLauncher);
    result = &descriptors.back();

    foreach(BCLauncherManager* instance, instances)
        emit instance->availableLaunchersChanged();

    return result;
}

QVector<BCLauncherManager*> BCLauncherManager::instances;
std::vector<BCLauncherDescriptor> BCLauncherManager::descriptors;
