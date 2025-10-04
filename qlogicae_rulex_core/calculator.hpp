#pragma once

#include "utilities.hpp"

namespace QLogicaeRulexCore
{
    class Calculator
    {
    public:
        bool is_within_bounds(
            const FuzzyExpertSystemAIInputRange& range,
            const double& value
        );

        double calculate_degree_of_membership(
            const FuzzyExpertSystemAIInputRange& range,
            const double& value
        );

        double calculate_defuzzification(
            const FuzzyExpertSystemAIInputRange& range,
            const double& value
        );
        
        double calculate_centroid(
            const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& ranges,
            const std::unordered_map<std::string, double>& values
        );

        static Calculator& get_instance();

    protected:
        Calculator() = default;

        ~Calculator() = default;

        Calculator(const Calculator&) = delete;

        Calculator(Calculator&&) noexcept = delete;

        Calculator& operator = (Calculator&&) = delete;

        Calculator& operator = (const Calculator&) = delete;

    };

    inline static Calculator& CALCULATOR =
        Calculator::get_instance();
}

