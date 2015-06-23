#ifndef BCAPPMANAGER_H
#define BCAPPMANAGER_H

// Qt includes
#include <QObject>
#include <QQmlListProperty>

// C++ includes
#include <vector>

// STE includes
#include <BCAppDescriptor>

template <typename T>
class QVector;
class QUrl;

class BCAppManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(BCAppManager)

    Q_PROPERTY(QQmlListProperty<BCLauncherDescriptor> availableApps READ getAvailableApps NOTIFY availableAppsChanged)

public:
    explicit BCAppManager(QObject* parent = 0);
    ~BCAppManager();

    QQmlListProperty<BCAppDescriptor> getAvailableApps();
signals:
    void availableAppsChanged();

private slots:
    static BCAppDescriptor* appendApp(const QString& name, const QString& description);
    static BCAppDescriptor* appendApp(const QString& identifier, const QString& name, const QString& description);
    static BCAppDescriptor* appendApp(const BCAppDescriptor&);

private:
    static QVector<BCAppManager*> instances;
    static std::vector<BCAppDescriptor> descriptors;

    static QString uniqueIdentifier(const QString& name);

    static int CountFunction(QQmlListProperty<BCAppDescriptor>* list);
    static BCAppDescriptor* AtFunction(QQmlListProperty<BCAppDescriptor>* list, int index);

    friend class BCVAPParser;
};

#endif // BCAPPMANAGER_H
