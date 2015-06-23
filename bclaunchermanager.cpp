#include "bclaunchermanager.h"

#include <QVector>
#include <QUrl>

BCLauncherManager::BCLauncherManager(QObject* parent)
    : QObject(parent)
{
    instances.append(this);
}

BCLauncherManager::~BCLauncherManager()
{
    instances.remove(this);
}

QQmlListProperty<BCLauncherDescriptor> BCLauncherManager::getAvailableLaunchers()
{
    return QQmlListProperty<BCLauncherDescriptor>(this, NULL, &BCLauncherManager::CountFunction, &BCLauncherManager::AtFunction);
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

BCLauncherDescriptor* BCLauncherManager::appendLauncher(const QString& name, const QString& description)
{
    return appendLauncher(uniqueIdentifier(name), name, description);
}

BCLauncherDescriptor* BCLauncherManager::appendLauncher(const QString& identifier, const QString& name, const QString& description)
{
    BCLauncherDescriptor* result;

    descriptors.emplace_back(identifier, name, description);
    result = &descriptors.back();

    foreach(BCLauncherManager* instance, instances)
        emit instance->availableLaunchersChanged();

    return result;
}

BCLauncherDescriptor* BCLauncherManager::appendLauncher(const BCLauncherDescriptor& newVAP)
{
    BCLauncherDescriptor* result;

    descriptors.push_back(newVAP);
    result = &descriptors.back();

    foreach(BCLauncherManager* instance, instances)
        emit instance->availableLaunchersChanged();

    return result;
}

QVector<BCLauncherManager*> BCLauncherManager::instances;
std::vector<BCLauncherDescriptor> BCLauncherManager::descriptors;
