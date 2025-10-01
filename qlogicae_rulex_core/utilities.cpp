#include "pch.hpp"

#include "utilities.hpp"

namespace QLogicaeRulexCore
{
    Utilities::Utilities()
    {
        
    }

    Utilities& Utilities::get_instance()
    {
        static Utilities instance;

        return instance;
    }
}
