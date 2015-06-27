#include<BCSettingsManager>

QSettings BCSettingsManager::mSettings(mCompanyName, mApplicationName);

//-----------------------------------------------------------
BCSettingsManager::BCSettingsManager()
{

}

//-----------------------------------------------------------
BCSettingsManager::~BCSettingsManager()
{

}

//-----------------------------------------------------------
void BCSettingsManager::saveSettings(const QString &app_uid,
                                     const QString& key,
                                     const QVariant& value)
{
    QSettings::Status err = mSettings.status();
    if (err == QSettings::Status::NoError)
    {
        // Save settings for the given UID
        mSettings.beginGroup(app_uid);
        mSettings.setValue(key, value);
        mSettings.endGroup();
    }
}

//-----------------------------------------------------------
QVariant BCSettingsManager::loadSettings(const QString& app_uid,
                                         const QString& key,
                                         const QVariant& defaultValue)
{
    QSettings::Status err = mSettings.status();
    QVariant result = QVariant();
    if (err == QSettings::Status::NoError)
    {
        mSettings.beginGroup(app_uid);
        result = mSettings.value(key, defaultValue);
        mSettings.endGroup();
    }
    return result;
}
