#include "bcappmanager.h"

#include <QVector>
#include <QUrl>
#include <BCQMLCreator>

BCAppManager::BCAppManager(QObject* parent)
    : QObject(parent)
{
    instances.append(this);
}

BCAppManager::~BCAppManager()
{
    instances.removeAll(this);
}

QQmlListProperty<BCAppDescriptor> BCAppManager::getAvailableApps()
{
    return QQmlListProperty<BCAppDescriptor>(this, NULL, &BCAppManager::CountFunction, &BCAppManager::AtFunction);
}

BCVehicleApp* BCAppManager::createApp(BCAppDescriptor* descriptor)
{
    return BCQMLCreator::constructQMLAppObject(*descriptor);
}

QString BCAppManager::uniqueIdentifier(const QString& name)
{
    QString identifier = name;
    unsigned int suffixCount = 2;
    std::vector<BCAppDescriptor>::const_iterator it = descriptors.begin();

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

int BCAppManager::CountFunction(QQmlListProperty<BCAppDescriptor>*)
{
    return BCAppManager::descriptors.size();
}

BCAppDescriptor* BCAppManager::AtFunction(QQmlListProperty<BCAppDescriptor>*, int index)
{
    return &BCAppManager::descriptors.at(index);
}

BCAppDescriptor* BCAppManager::appendApp(const BCAppDescriptor& newApp)
{
    BCAppDescriptor* result;

    descriptors.push_back(newApp);
    result = &descriptors.back();

    foreach(BCAppManager* instance, instances)
        emit instance->availableAppsChanged();

    return result;
}

QVector<BCAppManager*> BCAppManager::instances;
std::vector<BCAppDescriptor> BCAppManager::descriptors;
