#ifndef BCLAUNCHERDESCRIPTOR_H
#define BCLAUNCHERDESCRIPTOR_H

#include <QObject>
#include <BCVehicleLauncher>

class BCLauncherDescriptor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString identifier READ getIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QUrl entryPoint READ getEntryPoint NOTIFY entryPointChanged)
    Q_PROPERTY(QList<QString> dynLibFiles READ getDynLibFiles NOTIFY dynamicLibraryFilesChanged)
public:
    explicit BCLauncherDescriptor(const QString& identifier,
                                  const QString& name,
                                  const QString& description,
                                  const QUrl& entrypoint,
                                  const QList<QString>& dynLibFiles,
                                  QObject *parent = 0);
    explicit BCLauncherDescriptor(QObject *parent = 0);
    ~BCLauncherDescriptor();

    BCLauncherDescriptor(const BCLauncherDescriptor& origin);
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
     * @brief getEntryPoint Obtain the entry point of the app
     * @return
     */
    const QUrl& getEntryPoint() const;

    /**
     * @brief getDynLibFiles Obtain the dynamic library files list from the app
     * @return The dynamic library files list
     */
    const QList<QString>& getDynLibFiles() const;

signals:
    void identifierChanged();
    void nameChanged();
    void descriptionChanged();
    void entryPointChanged();
    void dynamicLibraryFilesChanged();

private:
    QString identifier;
    QString name;
    QString description;
    QUrl entryPoint;
    QList<QString> dynLibFiles;

    void setIdentifier(const QString&);
    void setName(const QString&);
    void setDescription(const QString&);
    void setEntryPoint(const QUrl&);
    void setDynLibFiles(const QList<QString>&);

    friend class BCLauncherManager;
    friend class BCVAPParser;
};

#endif // BCLAUNCHERDESCRIPTOR_H
