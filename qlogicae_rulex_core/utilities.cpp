#include "pch.hpp"

#include "utilities.hpp"

namespace QLogicaeRulexCore
{
    Utilities::Utilities()
    {
        
    }

    void Utilities::setup()
    {
        APPLICATION_SETTINGS_CACHE.setup(
            QLogicaeCore::SYSTEM_ACCESS.get_local_appdata_folder_path() +
            "\\" + "QLogicae" +
            "\\" + QLogicaeCore::APPLICATION.get_qlogicae_id() +
            "\\" + QLogicaeCore::APPLICATION.get_environment_id() +
            "\\" + "settings"
        );

        if (APPLICATION_SETTINGS_CACHE.is_key_found(APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY))
        {
            APPLICATION_SETTINGS_CACHE_SCREEN_TYPE = APPLICATION_SETTINGS_CACHE.get_value<int>(APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY);
        }
        else
        {
            APPLICATION_SETTINGS_CACHE_SCREEN_TYPE = 0;
            APPLICATION_SETTINGS_CACHE.begin_batch();
            APPLICATION_SETTINGS_CACHE.batch_set_value<int>(APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY, APPLICATION_SETTINGS_CACHE_SCREEN_TYPE);
            APPLICATION_SETTINGS_CACHE.commit_batch();
        }
    }

    Utilities& Utilities::get_instance()
    {
        static Utilities instance;

        return instance;
    }
}
