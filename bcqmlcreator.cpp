#include "bcqmlcreator.h"

#include <QLibrary>
#include <QQmlContext>

QQmlEngine* BCQMLCreator::engine;

BCQMLCreator::BCQMLCreator()
{

}

BCQMLCreator::~BCQMLCreator()
{

}

bool BCQMLCreator::loadDLFiles(QList<QString> dynLibFiles)
{
    foreach(const QString& fileUrl, dynLibFiles)
    {
        QLibrary library(fileUrl);
        typedef bool (*InitFunction) ();
        InitFunction initFunction = (InitFunction) library.resolve("STEVehicleApp_initfunc");

        if(initFunction == NULL)
            return false;

        bool result = initFunction();
        if(!result)
            return false;
    }

    return true;
}

BCVehicleApp* BCQMLCreator::constructQMLAppObject(const BCAppDescriptor& description)
{
    bool succesLoadingDLFiles = loadDLFiles(description.getDynLibFiles());
    if(!succesLoadingDLFiles)
    {
        qDebug() << "Did not succesfully load dynamic library files";
        return NULL;
    }
    QQmlContext* context = new QQmlContext(engine->rootContext());
    QQmlComponent component(engine, description.getEntryPoint());
    QVariantMap appData;

    appData.insert("name", description.getName());
    appData.insert("description", description.getDescription());
    appData.insert("category", description.getCategory());
    context->setContextProperty("app", appData);

    if( component.status() != QQmlComponent::Ready )
    {
        if( component.status() == QQmlComponent::Error )
        {
            qDebug() << "Error:" << component.errorString();
            return NULL;
        }
    }

    return qobject_cast<BCVehicleApp*>(component.create(context));
}


BCVehicleLauncher* BCQMLCreator::constructQMLLauncherObject(const BCLauncherDescriptor& description)
{
    bool succesLoadingDLFiles = loadDLFiles(description.getDynLibFiles());
    if(!succesLoadingDLFiles)
    {
        qDebug() << "Did not succesfully load dynamic library files";
        return NULL;
    }
    QQmlContext* context = new QQmlContext(engine->rootContext());
    QQmlComponent component(engine, description.getEntryPoint());
    QVariantMap appData;

    appData.insert("name", description.getName());
    appData.insert("description", description.getDescription());
    appData.insert("category", "launcher");
    context->setContextProperty("app", appData);

    if( component.status() != QQmlComponent::Ready )
    {
        if( component.status() == QQmlComponent::Error )
        {
            qDebug() << "Error:" << component.errorString();
            return NULL;
        }
    }
    return qobject_cast<BCVehicleLauncher*>(component.create(context));
}

void BCQMLCreator::setEngine(QQmlEngine* newEngine)
{
    engine = newEngine;
}
