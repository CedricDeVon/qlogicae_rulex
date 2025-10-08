#pragma once

namespace QLogicaeRulexCore
{    
    enum class FuzzyExpertSystemAILineCounLevelVariable : uint8_t
    {
        SMALL,
        MEDIUM,
        LARGE
    };

    enum class FuzzyExpertSystemAIAverageLineSizeLevelVariable : uint8_t
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
        std::string file_path = "";
    };

    struct CodeLexerOutput
    {
        bool is_successful = true;

        std::string message = "";

        double line_count = 0;

        double longest_line_size = 0;

        double average_line_size = 0;
    };

    struct FuzzyExpertSystemAIInputRange
    {
        double minimum = 0;

        double middle = 0;

        double maximum = 0;
    };

    struct FuzzyExpertSystemAIInput
    {
        std::string file_path = "";
    };

    struct FuzzyExpertSystemAIOutput
    {
        CodeLexerOutput code_lexer_output;
        
        std::vector<std::string> selected_line_count_level_input_variables;
        
        std::vector<std::string> selected_average_line_size_level_input_variables;
        
        std::vector<double> selected_line_count_level_input_variable_degree_of_memberships;

        std::vector<double> selected_average_line_size_level_input_variable_degree_of_memberships;

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

        int APPLICATION_SETTINGS_CACHE_SCREEN_TYPE;
        
        const std::string APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY =
            "APPLICATION_SETTINGS_CACHE_SCREEN_TYPE_KEY";
        
        const std::string APPLICATION_LOGO =
            ":/Application/qlogicae/application/assets/application.ico";

        const std::string APPLICATION_DEFAULT_QT_FONT_REFERENCE =
            ":/Application/qlogicae/application/assets/fonts/Inter/static/Inter_18pt-Regular.ttf";

        const std::string APPLICATION_DEFAULT_QWIDGET_STYLE =
            R"(
                QWidget {
                    font-family: "%1";
                }
            )";

        const std::string APPLICATION_QPUSH_BUTTON_ACTIVE_STYLE =
            "QPushButton {"
            "background: #3574F0;"
            "border: 2px solid transparent;"
            "border-radius: 4px;"
            "}"
            "QPushButton:hover {"
            "background: #366ACF;"
            "}"
            "QPushButton:pressed {"
            "	background: #375FAD;"
            "}";

        const std::string APPLICATION_QPUSH_BUTTON_INACTIVE_STYLE =
            "QPushButton {"
            "background: #2B2D30;"
            "border-radius: 4px;"
            "}"
            "QPushButton:hover {"
            "background: #4E5157;"
            "}"
            "QPushButton:pressed {"
            "background: #2B2D30;"
            "}";

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

        const std::unordered_map<FuzzyExpertSystemAIAverageLineSizeLevelVariable, std::string> FUZZY_EXPERT_SYSTEM_AI_LONGEST_LINE_SIZE_LEVEL_VARIABLE_ENUMS =
        {
            { FuzzyExpertSystemAIAverageLineSizeLevelVariable::SHORT, "short" },
            { FuzzyExpertSystemAIAverageLineSizeLevelVariable::MEDIUM, "medium" },
            { FuzzyExpertSystemAIAverageLineSizeLevelVariable::LONG, "long" }
        };

        const std::unordered_map<std::string, FuzzyExpertSystemAIAverageLineSizeLevelVariable> FUZZY_EXPERT_SYSTEM_AI_LONGEST_LINE_SIZE_LEVEL_VARIABLE_STRINGS =
        {
            { "short", FuzzyExpertSystemAIAverageLineSizeLevelVariable::SHORT },
            { "medium", FuzzyExpertSystemAIAverageLineSizeLevelVariable::MEDIUM },
            { "long", FuzzyExpertSystemAIAverageLineSizeLevelVariable::LONG }
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

        void setup();

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
