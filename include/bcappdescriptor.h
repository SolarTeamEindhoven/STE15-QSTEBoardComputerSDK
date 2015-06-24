#ifndef BCAPPDESCRIPTOR_H
#define BCAPPDESCRIPTOR_H

#include <QObject>
#include <QList>
#include <QUrl>

class BCAppDescriptor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString identifier READ getIdentifier NOTIFY identifierChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ getDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString category READ getCategory NOTIFY categoryChanged)
    Q_PROPERTY(QUrl entryPoint READ getEntryPoint NOTIFY entryPointChanged)
    Q_PROPERTY(QList<QString> dynLibFiles READ getDynLibFiles NOTIFY dynamicLibraryFilesChanged)
public:
    explicit BCAppDescriptor(const QString& identifier,
                             const QString& name,
                             const QString& description,
                             const QString& category,
                             const QUrl& entrypoint,
                             const QList<QString>& dynLibFiles,
                             QObject *parent = 0);
    explicit BCAppDescriptor(QObject *parent = 0);
    ~BCAppDescriptor();

    BCAppDescriptor(const BCAppDescriptor& origin);
    /**
     * @brief getIdentifier Obtain the unique identifier of the app.
     * @return The unique identifier
     */
    const QString& getIdentifier() const;

    /**
     * @brief getName Obtain the name of the app
     * @return The name
     */
    const QString& getName() const;

    /**
     * @brief getDescription Obtain the description of the app
     * @return The description
     */
    const QString& getDescription() const;

    /**
     * @brief getCategory Obtain the category of the app
     * @return The category
     */
    const QString& getCategory() const;

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
    void categoryChanged();
    void descriptionChanged();
    void entryPointChanged();
    void dynamicLibraryFilesChanged();

private:
    QString identifier;
    QString name;
    QString description;
    QString category;
    QUrl entryPoint;
    QList<QString> dynLibFiles;

    void setIdentifier(const QString&);
    void setName(const QString&);
    void setDescription(const QString&);
    void setCategory(const QString&);
    void setEntryPoint(const QUrl&);
    void setDynLibFiles(const QList<QString>&);

    friend class BCAppManager;
    friend class BCVAPParser;
};


#endif // BCAPPDESCRIPTOR_H
