#ifndef VEHICLEAPP_H
#define VEHICLEAPP_H

#include <QQuickItem>

class BCControlBar;

class VehicleApp : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(VehicleApp)

    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString category READ getCategory NOTIFY categoryChanged)

    Q_PROPERTY(BCControlBar* bccontrolbar READ getBCControlBar WRITE setBCControlBar NOTIFY bccontrolbarChanged)

public:
    explicit VehicleApp(QQuickItem *parent = 0);
    ~VehicleApp();

    const QString& getName() const;
    const QString& getDescription() const;
    const QString& getCategory() const;
    BCControlBar* getBCControlBar();

    void setBCControlBar(BCControlBar* bccontrolbar);

signals:
    void nameChanged(const QString& name);
    void descriptionChanged(const QString& description);
    void categoryChanged(const QString& category);
    void bccontrolbarChanged(BCControlBar* bccontrolbar);

public slots:

private:
    QString name;
    QString description;
    QString category;

    BCControlBar* bccontrolbar;
};

#endif // VEHICLEAPP_H

