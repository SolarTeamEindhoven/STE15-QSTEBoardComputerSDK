#ifndef VEHICLELAUNCHER_H
#define VEHICLELAUNCHER_H

#include <QQuickItem>

class VehicleApp;

class VehicleLauncher : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(VehicleLauncher)

    Q_PROPERTY(QQmlListProperty<VehicleApp> apps READ getApps NOTIFY appsChanged)

public:
    explicit VehicleLauncher(QQuickItem* parent = NULL);
    ~VehicleLauncher();

    const QList<VehicleApp*>& getAppList() const;
    Q_INVOKABLE void addApp(VehicleApp* app);
    Q_INVOKABLE void removeApp(VehicleApp* app);

signals:
    void appsChanged();
    void appAdded(VehicleApp*);
    void appRemoved(VehicleApp*);

public slots:

private:
    QList<VehicleApp*> apps;

    QQmlListProperty<VehicleApp> getApps();
    static int CountFunction(QQmlListProperty<VehicleApp>* list);
    static VehicleApp* AtFunction(QQmlListProperty<VehicleApp>* list, int index);
};

#endif // VEHICLELAUNCHER_H
