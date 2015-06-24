#ifndef BCQMLCREATOR_H
#define BCQMLCREATOR_H

// Qt includes
#include <QObject>

// STE includes
#include <BCAppDescriptor>
#include <BCLauncherDescriptor>

class BCQMLCreator
{
public:
    BCQMLCreator();
    ~BCQMLCreator();

    static QObject* constructQMLAppObject(QQmlEngine *engine,
                                       const BCAppDescriptor& description);

private:
    static bool loadDLFiles(const BCAppDescriptor& description);
};

#endif // BCQMLCREATOR_H
