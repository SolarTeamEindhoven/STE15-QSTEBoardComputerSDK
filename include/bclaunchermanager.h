#ifndef BCLAUNCHERMANAGER_H
#define BCLAUNCHERMANAGER_H

#include <BCLauncherDescriptor>

#include <QObject>
#include <QQmlListProperty>

#include <vector>

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
signals:
    void availableLaunchersChanged();

private slots:
    static BCLauncherDescriptor* appendLauncher(const QString& name, const QString& description);
    static BCLauncherDescriptor* appendLauncher(const QString& identifier, const QString& name, const QString& description);
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
