#ifndef VEHICLEAPPCONTAINER_H
#define VEHICLEAPPCONTAINER_H

#include <QQuickItem>

#include <BCControlBarHardwareInterface>

class VehicleApp;

class VehicleAppContainer : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(VehicleApp* app READ getApp WRITE setApp NOTIFY appChanged)
    Q_PROPERTY(BCControlBarHardwareInterface* bccontrolBarHardwareInterface READ getBCControlBarHardwareInterface WRITE setBCControlBarHardwareInterface NOTIFY bccontrolBarHardwareInterfaceChanged)
    Q_PROPERTY(double bccontrolBarOpacity READ getBCControlBarOpacity WRITE setBCControlBarOpacity NOTIFY bccontrolBarOpacityChanged)

public:
    explicit VehicleAppContainer(QQuickItem* parent = NULL);
    ~VehicleAppContainer();

    VehicleApp* getApp();
    BCControlBarHardwareInterface* getBCControlBarHardwareInterface();
    double getBCControlBarOpacity() const;

    void setApp(VehicleApp*);
    void setBCControlBarHardwareInterface(BCControlBarHardwareInterface*);
    void setBCControlBarOpacity(double);

signals:
    void appChanged(VehicleApp*);
    void bccontrolBarHardwareInterfaceChanged(BCControlBarHardwareInterface*);
    void bccontrolBarOpacityChanged(double);

public slots:

private slots:
    void bccontrolBarPositionChanged(double position);

private:
    VehicleApp* app;
    BCControlBarHardwareInterface* bccontrolBarHardwareInterface;
    double bccontrolBarOpacity;

    void disconnectAppToBCControlBar(VehicleApp* app);
    void connectAppToBCControlBar(VehicleApp* app);
};

#endif // VEHICLEAPPCONTAINER_H
