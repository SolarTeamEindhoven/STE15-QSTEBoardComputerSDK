#include "bcappdescriptor.h"

BCAppDescriptor::BCAppDescriptor(const QString &identifier, const QString &name, const QString &description, QObject *parent)
    : QObject(parent)
    , identifier(identifier)
    , name(name)
    , description(description)
{
    ;
}

BCAppDescriptor::BCAppDescriptor(QObject *parent)
    : QObject(parent)
    , identifier(QString::null)
    , name(QString::null)
    , description(QString::null)
{
    ;
}

BCAppDescriptor::~BCAppDescriptor()
{
    ;
}

BCAppDescriptor::BCAppDescriptor(const BCAppDescriptor& origin)
    : QObject(origin.parent())
    , identifier(origin.identifier)
    , name(origin.name)
    , description(origin.description)
{
    ;
}

const QString& BCAppDescriptor::getIdentifier() const
{
    return identifier;
}

const QString& BCAppDescriptor::getName() const
{
    return name;
}

const QString& BCAppDescriptor::getDescription() const
{
    return description;
}

const QString& BCAppDescriptor::getCategory() const
{
    return category;
}

const QUrl& BCAppDescriptor::getEntryPoint() const
{
    return entryPoint;
}

const QList<QString>& BCAppDescriptor::getDynLibFiles() const
{
    return dynLibFiles;
}

void BCAppDescriptor::setIdentifier(const QString& newIdentifier)
{
    if(identifier == newIdentifier)
        return;

    identifier = newIdentifier;
    emit identifierChanged();
}

void BCAppDescriptor::setName(const QString& newName)
{
    if(name == newName)
        return;

    name = newName;
    emit nameChanged();
}

void BCAppDescriptor::setDescription(const QString& newDescription)
{
    if(description == newDescription)
        return;

    description = newDescription;
    emit descriptionChanged();
}

void BCAppDescriptor::setCategory(const QString& newCategory)
{
    if(category == newCategory)
        return;

    category = newCategory;
    emit categoryChanged();
}

void BCAppDescriptor::setEntryPoint(const QUrl& newEntryPoint)
{
    if (entryPoint == newEntryPoint)
        return;
    entryPoint = newEntryPoint;
    emit entryPointChanged();
}

void BCAppDescriptor::setDynLibFiles(const QList<QString>& newDynLibFiles)
{
    if (dynLibFiles == newDynLibFiles)
        return;
    dynLibFiles = newDynLibFiles;
    emit dynamicLibraryFilesChanged();
}

