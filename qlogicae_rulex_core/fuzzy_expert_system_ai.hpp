#pragma once

namespace QLogicaeRulexCore
{
    class FuzzyExpertSystemAI
    {
    public:        
        static FuzzyExpertSystemAI& get_instance();

    private:
        FuzzyExpertSystemAI();
        ~FuzzyExpertSystemAI() = default;
        FuzzyExpertSystemAI(const FuzzyExpertSystemAI&) = delete;
        FuzzyExpertSystemAI(FuzzyExpertSystemAI&&) noexcept = delete;
        FuzzyExpertSystemAI& operator = (FuzzyExpertSystemAI&&) = delete;
        FuzzyExpertSystemAI& operator = (const FuzzyExpertSystemAI&) = delete;
    };

    inline static FuzzyExpertSystemAI& UTILITIES =
        FuzzyExpertSystemAI::get_instance();
}
