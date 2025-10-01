#pragma once

namespace QLogicaeRulexCore
{    
    class Utilities
    {
    public:        
        // QLogicaeCore::RocksDBDatabase APPLICATION_SETTINGS_CACHE;
        
        const std::string APPLICATION_LOGO =
            ":/Application/qlogicae/application/assets/application.ico";

        static Utilities& get_instance();

    private:
        Utilities();
        ~Utilities() = default;
        Utilities(const Utilities&) = delete;
        Utilities(Utilities&&) noexcept = delete;
        Utilities& operator = (Utilities&&) = delete;
        Utilities& operator = (const Utilities&) = delete;
    };

    inline static Utilities& UTILITIES =
        Utilities::get_instance();
}
