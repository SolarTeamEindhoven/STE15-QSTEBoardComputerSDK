#ifndef BCLAUNCHERMANAGER_H
#define BCLAUNCHERMANAGER_H

// Qt includes
#include <QObject>
#include <QQmlListProperty>
#include <QQmlEngine>

// C++ includes
#include <vector>

// STE includes
#include <BCLauncherDescriptor>

template <typename T>
class QVector;
class QUrl;

class BCLauncherManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(BCLauncherManager)

    Q_PROPERTY(QQmlListProperty<BCLauncherDescriptor> availableLaunchers READ getAvailableLaunchers NOTIFY availableLaunchersChanged)

public:
    explicit BCLauncherManager(QObject* parent = 0);
    ~BCLauncherManager();

    QQmlListProperty<BCLauncherDescriptor> getAvailableLaunchers();

    /**
     * @brief getLauncher Obtain a launcher from the description
     * @return The launcher
     */
    Q_INVOKABLE BCVehicleLauncher* createLauncher(BCLauncherDescriptor*);
signals:
    void availableLaunchersChanged();

private slots:
    static BCLauncherDescriptor* appendLauncher(const BCLauncherDescriptor&);

private:
    static QVector<BCLauncherManager*> instances;
    static std::vector<BCLauncherDescriptor> descriptors;

    static QString uniqueIdentifier(const QString& name);

    static int CountFunction(QQmlListProperty<BCLauncherDescriptor>* list);
    static BCLauncherDescriptor* AtFunction(QQmlListProperty<BCLauncherDescriptor>* list, int index);

    friend class BCVAPParser;
};

#endif // BCLAUNCHERMANAGER_H
