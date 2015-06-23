#include "bcvapmanager.h"

#include <QVector>
#include <QUrl>

BCVAPManager::BCVAPManager(QObject* parent)
    : QObject(parent)
{
    instances.append(this);
}

BCVAPManager::~BCVAPManager()
{
    instances.removeAll(this);
}

QQmlListProperty<BCVAPDescriptor> BCVAPManager::getAvailableVAPs()
{
    return QQmlListProperty<BCVAPDescriptor>(this, NULL, &BCVAPManager::CountFunction, &BCVAPManager::AtFunction);
}

BCVAPDescriptor* BCVAPManager::installVAP(const QUrl& filename)
{
    QString name = filename.fileName();
    name.truncate(name.length()-4);

    return appendVAP(name, QString::null, filename.fileName(), BCVAPDescriptor::InstallPending); // TODO: replce filename
}

void BCVAPManager::deinstallVAP(BCVAPDescriptor* VAP)
{
    VAP->setStatus(BCVAPDescriptor::DeinstallPending);
}

QString BCVAPManager::uniqueIdentifier(const QString& name)
{
    QString identifier = name;
    unsigned int suffixCount = 2;
    std::vector<BCVAPDescriptor>::const_iterator it = descriptors.begin();

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

int BCVAPManager::CountFunction(QQmlListProperty<BCVAPDescriptor>*)
{
    return BCVAPManager::descriptors.size();
}

BCVAPDescriptor* BCVAPManager::AtFunction(QQmlListProperty<BCVAPDescriptor>*, int index)
{
    return &BCVAPManager::descriptors.at(index);
}

BCVAPDescriptor* BCVAPManager::appendVAP(const QString& name, const QString& description, const QString& updateUrl, BCVAPDescriptor::Status status)
{
    return appendVAP(uniqueIdentifier(name), name, description, updateUrl, status);
}

BCVAPDescriptor* BCVAPManager::appendVAP(const QString& identifier, const QString& name, const QString& description, const QString& updateUrl, BCVAPDescriptor::Status status)
{
    BCVAPDescriptor* result;

    descriptors.emplace_back(identifier, name, description, updateUrl, status);
    result = &descriptors.back();

    foreach(BCVAPManager* instance, instances)
        emit instance->availableVAPsChanged();

    return result;
}

BCVAPDescriptor* BCVAPManager::appendVAP(const BCVAPDescriptor& newVAP)
{
    BCVAPDescriptor* result;

    descriptors.push_back(newVAP);
    result = &descriptors.back();

    foreach(BCVAPManager* instance, instances)
        emit instance->availableVAPsChanged();

    return result;
}

QVector<BCVAPManager*> BCVAPManager::instances;
std::vector<BCVAPDescriptor> BCVAPManager::descriptors;
