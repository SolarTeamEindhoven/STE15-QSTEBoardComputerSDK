#include <bcvapdescriptor.h>

BCVAPDescriptor::BCVAPDescriptor(const QString &identifier, const QString &name, const QString &description, const QString &updateUrl, Status status, QObject *parent)
    : QObject(parent)
    , identifier(identifier)
    , name(name)
    , description(description)
    , updateUrl(updateUrl)
    , status(status)
{
    ;
}


BCVAPDescriptor::BCVAPDescriptor(QObject *parent)
    : QObject(parent)
    , identifier(QString::null)
    , name(QString::null)
    , description(QString::null)
    , updateUrl(QString::null)
    , status(Status::None)
{
    ;
}

BCVAPDescriptor::~BCVAPDescriptor()
{
    ;
}

BCVAPDescriptor::BCVAPDescriptor(const BCVAPDescriptor& origin)
    : QObject(origin.parent())
    , name(origin.name)
    , description(origin.description)
    , updateUrl(origin.updateUrl)
    , status(origin.status)
{
    ;
}

const QString& BCVAPDescriptor::getIdentifier() const
{
    return identifier;
}

const QString& BCVAPDescriptor::getName() const
{
    return name;
}

const QString& BCVAPDescriptor::getDescription() const
{
    return description;
}

const QString& BCVAPDescriptor::getUpdateUrl() const
{
    return updateUrl;
}

BCVAPDescriptor::Status BCVAPDescriptor::getStatus() const
{
    return status;
}

void BCVAPDescriptor::setIdentifier(const QString& newIdentifier)
{
    if(identifier == newIdentifier)
        return;

    identifier = newIdentifier;
    emit identifierChanged();
}

void BCVAPDescriptor::setName(const QString& newName)
{
    if(name == newName)
        return;

    name = newName;
    emit nameChanged();
}

void BCVAPDescriptor::setDescription(const QString& newDescription)
{
    if(description == newDescription)
        return;

    description = newDescription;
    emit descriptionChanged();
}

void BCVAPDescriptor::setUpdateUrl(const QString& newUpdateUrl)
{
    if(updateUrl == newUpdateUrl)
        return;

    updateUrl = newUpdateUrl;
    emit updateUrlChanged();
}

void BCVAPDescriptor::setStatus(Status newStatus)
{
    if(status == newStatus)
        return;

    status = newStatus;
    emit statusChanged();
}
