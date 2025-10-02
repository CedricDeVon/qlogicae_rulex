#include "pch.hpp"

#include "fuzzy_expert_system_ai.hpp"

namespace QLogicaeRulexCore
{
    FuzzyExpertSystemAI::FuzzyExpertSystemAI()
    {

    }

    FuzzyExpertSystemAI& FuzzyExpertSystemAI::get_instance()
    {
        static FuzzyExpertSystemAI instance;

        return instance;
    }
}
