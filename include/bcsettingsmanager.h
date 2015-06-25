#ifndef BCSETTINGSMANAGER
#define BCSETTINGSMANAGER

// C(++) includes

// Qt includes
#include <QString>
#include <QVariant>
#include <QSettings>

// STE includes

class BCSettingsManager
{
public:
    /**
     * @brief BCSettingsManager Default constructor
     */
    BCSettingsManager();
    ~BCSettingsManager();

    /**
     * @brief saveSettings Saves settings for a certain application
     * @param app_uid The unique identifier of the application
     * @param key The key of the settings to save
     * @param value The value of the settings to save
     */
    static void saveSettings(QString app_uid,
                      const QString& key,
                      const QVariant& value);

    /**
     * @brief loadSettings Loads settings for a certain application
     * @param app_uid The unique identifier of the application
     * @param key The key of the settings
     * @param defaultValue The default return value
     * @return
     */
    static QVariant loadSettings(QString app_uid,
                          const QString& key,
                          const QVariant& defaultValue = QVariant());
private:
    // Static settings
    static constexpr const char* mCompanyName = "Solar Team Eindhoven";
    static constexpr const char* mApplicationName = "BoardComputer";

    // Private variables
    static QSettings mSettings;
};

#endif // BCSETTINGSMANAGER

