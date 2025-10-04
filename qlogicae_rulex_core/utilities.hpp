#pragma once

namespace QLogicaeRulexCore
{    
    enum class FuzzyExpertSystemAILineCounLevelVariable : uint8_t
    {
        SMALL,
        MEDIUM,
        LARGE
    };

    enum class FuzzyExpertSystemAILongestLineSizeLevelVariable : uint8_t
    {
        SHORT,
        MEDIUM,
        LONG
    };

    enum class FuzzyExpertSystemAIOrganizationLevelClassification : uint8_t
    {
        ORGANIZED,
        MIXED,
        UNORGANIZED
    };

    struct CodeLexerInput
    {
        std::string text = "";
    };

    struct CodeLexerOutput
    {
        bool is_successful = true;

        std::string message = "";

        double line_count = 0;

        double longest_line_size = 0;
    };

    struct FuzzyExpertSystemAIInputRange
    {
        double minimum = 0;

        double middle = 0;

        double maximum = 0;
    };

    struct FuzzyExpertSystemAIInput
    {
        std::string text = "";
    };

    struct FuzzyExpertSystemAIOutput
    {
        CodeLexerOutput code_lexer_output;
        
        std::vector<std::string> selected_line_count_level_input_variables;
        
        std::vector<std::string> selected_longest_line_size_level_input_variables;
        
        std::vector<double> selected_line_count_level_input_variable_degree_of_memberships;

        std::vector<double> selected_longest_line_size_level_input_variable_degree_of_memberships;

        std::unordered_map<std::string, double> selected_organized_level_outptut_variables;

        std::unordered_map<std::string, double> defuzzified_organized_level_outptut_results;

        double centroid = 0;

        double final_organized_level_outptut_value = 0;

        std::string final_organized_level_outptut_variable = "";

        std::unordered_map<std::string, double> degree_of_truths;

        bool is_successful = true;
        
        std::string message = "";
    };

    class Utilities
    {
    public:        
        QLogicaeCore::RocksDBDatabase APPLICATION_SETTINGS_CACHE;
        
        const std::string APPLICATION_LOGO =
            ":/Application/qlogicae/application/assets/application.ico";

        const std::unordered_map<FuzzyExpertSystemAILineCounLevelVariable, std::string> FUZZY_EXPERT_SYSTEM_AI_LINE_COUNT_LEVEL_VARIABLE_ENUMS =
        {
            { FuzzyExpertSystemAILineCounLevelVariable::SMALL, "small" },
            { FuzzyExpertSystemAILineCounLevelVariable::MEDIUM, "medium" },
            { FuzzyExpertSystemAILineCounLevelVariable::LARGE, "large" }
        };

        const std::unordered_map<std::string, FuzzyExpertSystemAILineCounLevelVariable> FUZZY_EXPERT_SYSTEM_AI_LINE_COUNT_LEVEL_VARIABLE_STRINGS =
        {
            { "small", FuzzyExpertSystemAILineCounLevelVariable::SMALL},
            { "medium", FuzzyExpertSystemAILineCounLevelVariable::MEDIUM},
            { "large", FuzzyExpertSystemAILineCounLevelVariable::LARGE}
        };

        const std::unordered_map<FuzzyExpertSystemAILongestLineSizeLevelVariable, std::string> FUZZY_EXPERT_SYSTEM_AI_LONGEST_LINE_SIZE_LEVEL_VARIABLE_ENUMS =
        {
            { FuzzyExpertSystemAILongestLineSizeLevelVariable::SHORT, "short" },
            { FuzzyExpertSystemAILongestLineSizeLevelVariable::MEDIUM, "medium" },
            { FuzzyExpertSystemAILongestLineSizeLevelVariable::LONG, "long" }
        };

        const std::unordered_map<std::string, FuzzyExpertSystemAILongestLineSizeLevelVariable> FUZZY_EXPERT_SYSTEM_AI_LONGEST_LINE_SIZE_LEVEL_VARIABLE_STRINGS =
        {
            { "short", FuzzyExpertSystemAILongestLineSizeLevelVariable::SHORT },
            { "medium", FuzzyExpertSystemAILongestLineSizeLevelVariable::MEDIUM },
            { "long", FuzzyExpertSystemAILongestLineSizeLevelVariable::LONG }
        };

        const std::unordered_map<FuzzyExpertSystemAIOrganizationLevelClassification, std::string> FUZZY_EXPERT_SYSTEM_AI_ORGANIZATION_LEVEL_CLASSIFICATOIN_ENUMS =
        {
            { FuzzyExpertSystemAIOrganizationLevelClassification::ORGANIZED, "organized" },
            { FuzzyExpertSystemAIOrganizationLevelClassification::MIXED, "mixed" },
            { FuzzyExpertSystemAIOrganizationLevelClassification::UNORGANIZED, "unorganized" }
        };

        const std::unordered_map<std::string, FuzzyExpertSystemAIOrganizationLevelClassification> FUZZY_EXPERT_SYSTEM_AI_ORGANIZATION_LEVEL_CLASSIFICATOIN_STRINGS =
        {
            { "organized", FuzzyExpertSystemAIOrganizationLevelClassification::ORGANIZED },
            { "mixed", FuzzyExpertSystemAIOrganizationLevelClassification::MIXED },
            { "unorganized", FuzzyExpertSystemAIOrganizationLevelClassification::UNORGANIZED }
        };

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
