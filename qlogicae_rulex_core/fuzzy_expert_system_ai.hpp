#pragma once

#include "utilities.hpp"
#include "code_lexer.hpp"
#include "calculator.hpp"

namespace QLogicaeRulexCore
{    
    class FuzzyExpertSystemAI
    {
    public:
        FuzzyExpertSystemAIOutput evaluate(const FuzzyExpertSystemAIInput& input);

        std::future<FuzzyExpertSystemAIOutput> evaluate_async(const FuzzyExpertSystemAIInput& input);

        static FuzzyExpertSystemAI& get_instance();

    protected:
        std::unordered_map<std::string, FuzzyExpertSystemAIInputRange> _line_count_level_input_variables;

        std::unordered_map<std::string, FuzzyExpertSystemAIInputRange> _longest_line_size_level_input_variables;

        std::unordered_map<std::string, FuzzyExpertSystemAIInputRange> _organization_level_output_variables;

        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> _organization_level_output_variable_fuzzy_ruleset;

        FuzzyExpertSystemAI();
        
        ~FuzzyExpertSystemAI() = default;
        
        FuzzyExpertSystemAI(const FuzzyExpertSystemAI&) = delete;
        
        FuzzyExpertSystemAI(FuzzyExpertSystemAI&&) noexcept = delete;
        
        FuzzyExpertSystemAI& operator = (FuzzyExpertSystemAI&&) = delete;
        
        FuzzyExpertSystemAI& operator = (const FuzzyExpertSystemAI&) = delete;

        const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& get_line_count_level_input_variables();

        const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& get_longest_line_size_level_input_variables();

        const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& get_organization_level_output_variables();

        const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& get_organization_level_output_variable_fuzzy_ruleset();

        void _extract_code_lexer_data(
            const FuzzyExpertSystemAIInput& input,
            CodeLexerOutput& code_lexer_output
        );

        void _evaluate_membership_function(
            CodeLexerOutput& code_lexer_output,
            std::vector<std::string>& selected_line_count_level_input_variables,
            std::vector<std::string>& selected_longest_line_size_level_input_variables
        );

        void _evaluate_degree_of_memberships(
            CodeLexerOutput& code_lexer_output,
            std::vector<std::string>& selected_line_count_level_input_variables,
            std::vector<std::string>& selected_longest_line_size_level_input_variables,
            std::vector<double>& selected_line_count_level_input_variable_degree_of_memberships,
            std::vector<double>& selected_longest_line_size_level_input_variable_degree_of_memberships
        );

        void _evaluate_fuzzification_rules(
            CodeLexerOutput& code_lexer_output,
            std::vector<std::string>& selected_line_count_level_input_variables,
            std::vector<std::string>& selected_longest_line_size_level_input_variables,
            std::vector<double>& selected_line_count_level_input_variable_degree_of_memberships,
            std::vector<double>& selected_longest_line_size_level_input_variable_degree_of_memberships,
            std::unordered_map<std::string, double>& selected_organized_level_outptut_variables
        );

        void _evaluate_defuzzification(
            std::unordered_map<std::string, double>& selected_organized_level_outptut_variables,
            std::unordered_map<std::string, double>& defuzzified_organized_level_outptut_results
        );

        void _evaluate_centroid(
            double& centroid,
            std::unordered_map<std::string, double>& defuzzified_organized_level_outptut_results
        );

        void _evaluate_final_results(
            double& centroid,
            double& final_organized_level_outptut_value,
            std::string& final_organized_level_outptut_variable,
            std::unordered_map<std::string, double>& degree_of_truths,
            std::unordered_map<std::string, double>& selected_organized_level_outptut_variables
        );
    };

    inline static FuzzyExpertSystemAI& FUZZY_EXPERT_SYSTEM_AI =
        FuzzyExpertSystemAI::get_instance();
}
