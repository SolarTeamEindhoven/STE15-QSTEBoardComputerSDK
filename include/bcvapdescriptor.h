#ifndef VAPDESCRIPTOR_H
#define VAPDESCRIPTOR_H

#include <QObject>

class BCVAPDescriptor : public QObject
{
    Q_OBJECT
    Q_ENUMS(Status)

    Q_PROPERTY(QString identifier READ getIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString updateUrl READ getUpdateUrl NOTIFY updateUrlChanged)
    Q_PROPERTY(Status status READ getStatus NOTIFY statusChanged)

public:
    enum Status {
        InstallPending,
        Installing,
        Ready,
        DeinstallPending,
        Deinstalling,
        None
    };

    explicit BCVAPDescriptor(const QString& identifier, const QString& name, const QString& description, const QString& updateUrl, Status status, QObject* parent = NULL);
    explicit BCVAPDescriptor(QObject *parent = 0);
    ~BCVAPDescriptor();

    BCVAPDescriptor(const BCVAPDescriptor&); //!< Cause gcc thinks the object if difficult to copy...

    /**
     * @brief getIdentifier Obtain the unique identifier of the VAP.
     * @return The unique identifier
     */
    const QString& getIdentifier() const;

    /**
     * @brief getName Obtain the name of the VAP.
     * @return The name
     */
    const QString& getName() const;

    /**
     * @brief getDescription Obtain the description of the VAP.
     * @return The description
     */
    const QString& getDescription() const;

    /**
     * @brief getUpdateUrl Obtain the update URL of the VAP.
     * @return The update URL
     */
    const QString& getUpdateUrl() const;

    /**
     * @brief getStatus Obtain the satus of the VAP.
     * @return The status
     */
    Status getStatus() const;

signals:
    void identifierChanged();
    void nameChanged();
    void descriptionChanged();
    void updateUrlChanged();
    void statusChanged();

private:
    QString identifier;
    QString name;
    QString description;
    QString updateUrl;
    Status status;

    void setIdentifier(const QString&);
    void setName(const QString&);
    void setDescription(const QString&);
    void setUpdateUrl(const QString&);
    void setStatus(Status);

    friend class BCVAPManager;
    friend class BCVAPParser;
};

#endif // VAPDESCRIPTOR_H

