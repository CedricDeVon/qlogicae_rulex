#pragma once

#include "code_lexer.hpp"

namespace QLogicaeRulexCore
{
    enum class LineCountLevel : uint8_t
    {
        SMALL,
        MEDIUM,
        LARGE
    };

    enum class LongestLineSizeLevel : uint8_t
    {
        SHORT,
        MEDIUM,
        LONG
    };

    enum class OrganizedLevel : uint8_t
    {
        ORGANIZED,
        MILDLY_ORGANIZED,
        UNORGANIZED
    };

    struct FuzzyExpertSystemAIInput
    {
        std::string text = "";
    };

    struct FuzzyExpertSystemAIOutput
    {
        bool is_successful = true;
        std::string message = "";
    };

    class FuzzyExpertSystemAIVariable
    {
    public:
        FuzzyExpertSystemAIVariable(
            const double& minimum,
            const double& middle,
            const double& maximum,
            const std::string& name = ""
        );
        FuzzyExpertSystemAIVariable() = default;
        ~FuzzyExpertSystemAIVariable() = default;

        double get_middle();
        double get_minimum();
        double get_maximum();
        std::string get_name();
        bool is_within_bounds(const double& value);
        double calculate_degree_of_membership(const double& value);

    protected:
        std::string _name;
        double _minimum;
        double _middle;
        double _maximum;
    };

    class FuzzyExpertSystemAIRuleEvaluation
    {
    public:
        FuzzyExpertSystemAIRuleEvaluation(
            const FuzzyExpertSystemAIVariable& line_count_variable,
            const FuzzyExpertSystemAIVariable& longest_line_size_variable,
            const FuzzyExpertSystemAIVariable& organized_classification
        );
        FuzzyExpertSystemAIRuleEvaluation() = default;
        ~FuzzyExpertSystemAIRuleEvaluation() = default;

        FuzzyExpertSystemAIVariable get_line_count_variable();
        FuzzyExpertSystemAIVariable get_longest_line_size_variable();
        FuzzyExpertSystemAIVariable get_organized_classification();
        bool is_within_bounds(const double& value);
        double calculate_degree_of_membership(const double& value);

    protected:
        FuzzyExpertSystemAIVariable _line_count_variable;
        FuzzyExpertSystemAIVariable _longest_line_size_variable;
        FuzzyExpertSystemAIVariable _organized_classification;
    };


    class FuzzyExpertSystemAI
    {
    public:
        FuzzyExpertSystemAIOutput evaluate(const FuzzyExpertSystemAIInput& input);

        static FuzzyExpertSystemAI& get_instance();

    protected:
        FuzzyExpertSystemAI();
        ~FuzzyExpertSystemAI() = default;
        FuzzyExpertSystemAI(const FuzzyExpertSystemAI&) = delete;
        FuzzyExpertSystemAI(FuzzyExpertSystemAI&&) noexcept = delete;
        FuzzyExpertSystemAI& operator = (FuzzyExpertSystemAI&&) = delete;
        FuzzyExpertSystemAI& operator = (const FuzzyExpertSystemAI&) = delete;

        std::vector<FuzzyExpertSystemAIVariable> _line_count_variables;
        std::vector<FuzzyExpertSystemAIVariable> _longest_line_size_variables;
        std::unordered_map<std::string, FuzzyExpertSystemAIVariable> _organized_classifications;
    };

    inline static FuzzyExpertSystemAI& FUZZY_EXPERT_SYSTEM_AI =
        FuzzyExpertSystemAI::get_instance();
}
