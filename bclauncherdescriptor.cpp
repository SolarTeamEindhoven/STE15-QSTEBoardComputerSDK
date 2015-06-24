#include "bclauncherdescriptor.h"


BCLauncherDescriptor::BCLauncherDescriptor(const QString &identifier,
                                           const QString &name,
                                           const QString &description,
                                           const QUrl& entrypoint,
                                           const QList<QString>& dynLibFiles,
                                           QObject *parent)
    : QObject(parent)
    , identifier(identifier)
    , name(name)
    , description(description)
    , entryPoint(entrypoint)
    , dynLibFiles(dynLibFiles)
{
    ;
}

BCLauncherDescriptor::BCLauncherDescriptor(QObject *parent)
    : QObject(parent)
    , identifier(QString::null)
    , name(QString::null)
    , description(QString::null)
    , entryPoint(QUrl())
    , dynLibFiles(QList<QString>())
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
    , entryPoint(origin.entryPoint)
    , dynLibFiles(origin.dynLibFiles)
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

const QUrl& BCLauncherDescriptor::getEntryPoint() const
{
    return entryPoint;
}

const QList<QString>& BCLauncherDescriptor::getDynLibFiles() const
{
    return dynLibFiles;
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

void BCLauncherDescriptor::setEntryPoint(const QUrl& newEntryPoint)
{
    if (entryPoint == newEntryPoint)
        return;
    entryPoint = newEntryPoint;
    emit entryPointChanged();
}

void BCLauncherDescriptor::setDynLibFiles(const QList<QString>& newDynLibFiles)
{
    if (dynLibFiles == newDynLibFiles)
        return;
    dynLibFiles = newDynLibFiles;
    emit dynamicLibraryFilesChanged();
}
