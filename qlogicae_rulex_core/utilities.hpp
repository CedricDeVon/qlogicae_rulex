#pragma once

namespace QLogicaeRulexCore
{    
    enum class FuzzyExpertSystemAILineCountVariable : uint8_t
    {
        SMALL,
        MEDIUM,
        LARGE
    };

    enum class FuzzyExpertSystemAILongestLineSizeVariable : uint8_t
    {
        SHORT,
        MEDIUM,
        LONG
    };

    enum class FuzzyExpertSystemAIOrganizedClassification : uint8_t
    {
        ORGANIZED,
        MILDLY_ORGANIZED,
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
