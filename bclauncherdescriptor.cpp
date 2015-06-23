#include "bclauncherdescriptor.h"


BCLauncherDescriptor::BCLauncherDescriptor(const QString &identifier, const QString &name, const QString &description, QObject *parent)
    : QObject(parent)
    , identifier(identifier)
    , name(name)
    , description(description)
{
    ;
}

BCLauncherDescriptor::~BCLauncherDescriptor()
{
    ;
}

BCLauncherDescriptor::BCLauncherDescriptor(const BCLauncherDescriptor& origin)
    : QObject(origin.parent())
    , identifier(origin.identifier)
    , name(origin.name)
    , description(origin.description)
{
    ;
}

const QString& BCLauncherDescriptor::getIdentifier() const
{
    return identifier;
}

const QString& BCLauncherDescriptor::getName() const
{
    return name;
}

const QString& BCLauncherDescriptor::getDescription() const
{
    return description;
}

void BCLauncherDescriptor::setIdentifier(const QString& newIdentifier)
{
    if(identifier == newIdentifier)
        return;

    identifier = newIdentifier;
    emit identifierChanged();
}

void BCLauncherDescriptor::setName(const QString& newName)
{
    if(name == newName)
        return;

    name = newName;
    emit nameChanged();
}

void BCLauncherDescriptor::setDescription(const QString& newDescription)
{
    if(description == newDescription)
        return;

    description = newDescription;
    emit descriptionChanged();
}
