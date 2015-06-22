#ifndef BCVAPMANAGER_H
#define BCVAPMANAGER_H

#include <QObject>
#include <QQmlListProperty>
#include <bcvapdescriptor.h>

#include <vector>

template <typename T>
class QVector;
class QUrl;

class BCVAPManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(BCVAPManager)

    Q_PROPERTY(QQmlListProperty<BCVAPDescriptor> availableVAPs READ getAvailableVAPs NOTIFY availableVAPsChanged)

public:
    explicit BCVAPManager(QObject* parent = NULL);
    ~BCVAPManager();

    QQmlListProperty<BCVAPDescriptor> getAvailableVAPs();

    Q_INVOKABLE BCVAPDescriptor* installVAP(const QUrl& filename);
    Q_INVOKABLE void deinstallVAP(BCVAPDescriptor*);

signals:
    void availableVAPsChanged();

private slots:
    static BCVAPDescriptor* appendVAP(const QString& name, const QString& description, const QString& updateUrl, BCVAPDescriptor::Status status);
    static BCVAPDescriptor* appendVAP(const QString& identifier, const QString& name, const QString& description, const QString& updateUrl, BCVAPDescriptor::Status status);
    static BCVAPDescriptor* appendVAP(const BCVAPDescriptor&);

private:
    static QVector<BCVAPManager*> instances;
    static std::vector<BCVAPDescriptor> descriptors;

    static QString uniqueIdentifier(const QString& name);

    static int CountFunction(QQmlListProperty<BCVAPDescriptor>* list);
    static BCVAPDescriptor* AtFunction(QQmlListProperty<BCVAPDescriptor>* list, int index);

    friend class BCVAPParser;
};

#endif // BCVAPMANAGER_H
