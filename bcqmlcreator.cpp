#include "bcqmlcreator.h"

#include <QLibrary>
#include <QQmlContext>
#include <QQmlEngine>

BCQMLCreator::BCQMLCreator()
{

}

BCQMLCreator::~BCQMLCreator()
{

}

bool BCQMLCreator::loadDLFiles(const BCAppDescriptor& description)
{
    foreach(const QString& fileUrl, description.getDynLibFiles())
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

QObject* BCQMLCreator::constructQMLAppObject(QQmlEngine *engine,
                                          const BCAppDescriptor& description)
{
    bool succesLoadingDLFiles = loadDLFiles(description);
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

    return component.create(context);
}
