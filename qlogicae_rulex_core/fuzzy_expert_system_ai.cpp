#include "pch.hpp"

#include "fuzzy_expert_system_ai.hpp"

namespace QLogicaeRulexCore
{
    FuzzyExpertSystemAI::FuzzyExpertSystemAI()
    {
        _line_count_level_input_variables =
        {
            { "small", { 0, 50, 125 } },
            { "medium", { 75, 250, 525 } },
            { "large", { 475, 2000, 3525 } }
        };

        _longest_line_size_level_input_variables =
        {
            { "short", { 0, 20, 50 } },
            { "medium", { 30, 60, 90 } },
            { "long", { 70, 500, 1010 } }
        };

        _organization_level_output_variables =
        {
            { "organized", { 0, 10, 25 } },
            { "mixed", { 15, 30, 45 } },
            { "unorganized", { 35, 60, 85 } }
        };

        _organization_level_output_variable_fuzzy_ruleset =
        {
            {
                "small",
                {
                    { "short", "organized" },
                    { "medium", "mixed" },
                    { "long", "mixed" }
                }
            },
            {
                "medium",
                {
                    { "short", "mixed" },
                    { "medium", "mixed" },
                    { "long", "unorganized" }
                }
            },
            {
                "large",
                {
                    { "short", "unorganized" },
                    { "medium", "unorganized" },
                    { "long", "unorganized" }
                }
            }
        };
    }

    const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& 
        FuzzyExpertSystemAI::get_line_count_level_input_variables()
    {
        return _line_count_level_input_variables;
    }

    const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& 
        FuzzyExpertSystemAI::get_longest_line_size_level_input_variables()
    {
        return _longest_line_size_level_input_variables;
    }

    const std::unordered_map<std::string, FuzzyExpertSystemAIInputRange>& 
        FuzzyExpertSystemAI::get_organization_level_output_variables()
    {
        return _organization_level_output_variables;
    }

    const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& 
        FuzzyExpertSystemAI::get_organization_level_output_variable_fuzzy_ruleset()
    {
        return _organization_level_output_variable_fuzzy_ruleset;
    }

    FuzzyExpertSystemAIOutput FuzzyExpertSystemAI::evaluate(
        const FuzzyExpertSystemAIInput& input
    )
    {
        try
        {
            FuzzyExpertSystemAIOutput output;

            CodeLexerOutput& code_lexer_output =
                output.code_lexer_output;
            std::vector<std::string>& selected_line_count_level_input_variables =
                output.selected_line_count_level_input_variables;
            std::vector<std::string>& selected_longest_line_size_level_input_variables =
                output.selected_longest_line_size_level_input_variables;
            std::vector<double>& selected_line_count_level_input_variable_degree_of_memberships =
                output.selected_line_count_level_input_variable_degree_of_memberships;
            std::vector<double>& selected_longest_line_size_level_input_variable_degree_of_memberships =
                output.selected_longest_line_size_level_input_variable_degree_of_memberships;
            std::unordered_map<std::string, double>& selected_organized_level_outptut_variables =
                output.selected_organized_level_outptut_variables;
            std::unordered_map<std::string, double>& defuzzified_organized_level_outptut_results =
                output.defuzzified_organized_level_outptut_results;
            double& centroid = output.centroid;
            double& final_organized_level_outptut_value =
                output.final_organized_level_outptut_value;
            std::string& final_organized_level_outptut_variable =
                output.final_organized_level_outptut_variable;
            std::unordered_map<std::string, double>& degree_of_truths =
                output.degree_of_truths;

            _extract_code_lexer_data(
                input,
                code_lexer_output
            );

            _evaluate_membership_function(
                code_lexer_output,
                selected_line_count_level_input_variables,
                selected_longest_line_size_level_input_variables
            );

            _evaluate_degree_of_memberships(
                code_lexer_output,
                selected_line_count_level_input_variables,
                selected_longest_line_size_level_input_variables,
                selected_line_count_level_input_variable_degree_of_memberships,
                selected_longest_line_size_level_input_variable_degree_of_memberships
            );

            _evaluate_fuzzification_rules(
                code_lexer_output,
                selected_line_count_level_input_variables,
                selected_longest_line_size_level_input_variables,
                selected_line_count_level_input_variable_degree_of_memberships,
                selected_longest_line_size_level_input_variable_degree_of_memberships,
                selected_organized_level_outptut_variables
            );

            _evaluate_defuzzification(
                selected_organized_level_outptut_variables,
                defuzzified_organized_level_outptut_results
            );

            _evaluate_centroid(
                centroid,
                defuzzified_organized_level_outptut_results
            );

            _evaluate_final_results(
                centroid,
                final_organized_level_outptut_value,
                final_organized_level_outptut_variable,
                degree_of_truths,
                selected_organized_level_outptut_variables
            );

            return output;
        }
        catch (const std::exception& exception)
        {
            return
            {
                .is_successful = false,
                .message = exception.what()
            };
        }
    }


    std::future<FuzzyExpertSystemAIOutput> FuzzyExpertSystemAI::evaluate_async(
        const FuzzyExpertSystemAIInput& input
    )
    {
        return std::async(std::launch::async, [this, input]() -> FuzzyExpertSystemAIOutput
            {
                return evaluate(input);
            }
        );
    }
    
    void FuzzyExpertSystemAI::_extract_code_lexer_data(
        const FuzzyExpertSystemAIInput& input,
        CodeLexerOutput& code_lexer_output
    )
    {
        code_lexer_output = CODE_LEXER.evaluate({
            .file_path = input.file_path
        });
    }

    void FuzzyExpertSystemAI::_evaluate_membership_function(
        CodeLexerOutput& code_lexer_output,
        std::vector<std::string>& selected_line_count_level_input_variables,
        std::vector<std::string>& selected_longest_line_size_level_input_variables
    )
    {
        for (const auto& [key, value] :
            _line_count_level_input_variables
        )
        {
            if (CALCULATOR.is_within_bounds(
                value,
                code_lexer_output.line_count
                )
            )
            {
                selected_line_count_level_input_variables.push_back(
                    key
                );
            }
        }

        for (const auto& [key, value] :
            _longest_line_size_level_input_variables
        )
        {            
            if (CALCULATOR.is_within_bounds(
                value,
                code_lexer_output.longest_line_size
            )
                )
            {
                selected_longest_line_size_level_input_variables.push_back(
                    key
                );
            }
        }
    }

    void FuzzyExpertSystemAI::_evaluate_degree_of_memberships(
        CodeLexerOutput& code_lexer_output,
        std::vector<std::string>& selected_line_count_level_input_variables,
        std::vector<std::string>& selected_longest_line_size_level_input_variables,
        std::vector<double>& selected_line_count_level_input_variable_degree_of_memberships,
        std::vector<double>& selected_longest_line_size_level_input_variable_degree_of_memberships
    )
    {        
        for (const auto& line_count_level_input_variable :
            selected_line_count_level_input_variables)
        {
            selected_line_count_level_input_variable_degree_of_memberships.push_back(
                CALCULATOR.calculate_degree_of_membership(
                    _line_count_level_input_variables[line_count_level_input_variable],
                    code_lexer_output.line_count
                )
            );
        }

        for (const auto& longest_line_size_level_input_variable :
            selected_longest_line_size_level_input_variables)
        {
            selected_longest_line_size_level_input_variable_degree_of_memberships.push_back(
                CALCULATOR.calculate_degree_of_membership(
                    _longest_line_size_level_input_variables[longest_line_size_level_input_variable],
                    code_lexer_output.longest_line_size
                )
            );
        }
    }

    void FuzzyExpertSystemAI::_evaluate_fuzzification_rules(
        CodeLexerOutput& code_lexer_output,
        std::vector<std::string>& selected_line_count_level_input_variables,
        std::vector<std::string>& selected_longest_line_size_level_input_variables,
        std::vector<double>& selected_line_count_level_input_variable_degree_of_memberships,
        std::vector<double>& selected_longest_line_size_level_input_variable_degree_of_memberships,
        std::unordered_map<std::string, double>& selected_organized_level_outptut_variables
    )
    {        
        size_t line_count_level_input_variable_index,
            longest_line_size_level_input_variable_index,
            line_count_level_input_variables_size =
                selected_line_count_level_input_variables.size(),
            longest_line_size_level_input_variables_size =
                selected_longest_line_size_level_input_variables.size();

        for (line_count_level_input_variable_index = 0;
            line_count_level_input_variable_index <
                line_count_level_input_variables_size;
            ++line_count_level_input_variable_index)
        {
            double selected_line_count_level_input_variable_degree_of_membership =
                selected_line_count_level_input_variable_degree_of_memberships
                    [line_count_level_input_variable_index];
            std::string selected_line_count_level_input_variable_name =
                selected_line_count_level_input_variables
                    [line_count_level_input_variable_index];
            for (longest_line_size_level_input_variable_index = 0;
                longest_line_size_level_input_variable_index <
                    longest_line_size_level_input_variables_size;
                ++longest_line_size_level_input_variable_index)
            {
                double selected_longest_line_size_level_input_variable_degree_of_membership =
                    selected_longest_line_size_level_input_variable_degree_of_memberships
                        [longest_line_size_level_input_variable_index];
                double minimum_degree_of_membership = std::min(
                    selected_line_count_level_input_variable_degree_of_membership,
                    selected_longest_line_size_level_input_variable_degree_of_membership
                );
                std::string selected_longest_line_size_name =
                    selected_longest_line_size_level_input_variables
                        [longest_line_size_level_input_variable_index];
                std::string selected_organized_level_output_variable =
                    _organization_level_output_variable_fuzzy_ruleset
                        [selected_line_count_level_input_variable_name]
                        [selected_longest_line_size_name];

                if (!selected_organized_level_outptut_variables
                    .contains(
                        selected_organized_level_output_variable
                    )
                )
                {
                    selected_organized_level_outptut_variables
                        [selected_organized_level_output_variable] =
                            minimum_degree_of_membership;
                }
                else
                {
                    selected_organized_level_outptut_variables
                        [selected_organized_level_output_variable] =
                            std::min(
                                minimum_degree_of_membership,
                                selected_organized_level_outptut_variables
                                    [selected_organized_level_output_variable]
                            );
                }
            }
        }
    }

    void FuzzyExpertSystemAI::_evaluate_defuzzification(
        std::unordered_map<std::string, double>& selected_organized_level_outptut_variables,
        std::unordered_map<std::string, double>& defuzzified_organized_level_outptut_results
    )
    {        
        for (auto& [key, value] :
            selected_organized_level_outptut_variables)
        {
            defuzzified_organized_level_outptut_results[key] =
                CALCULATOR.calculate_defuzzification(
                    _organization_level_output_variables[key],
                    value
                );
        }
    }

    void FuzzyExpertSystemAI::_evaluate_centroid(
        double& centroid,
        std::unordered_map<std::string, double>& defuzzified_organized_level_outptut_results
    )
    {           
        centroid = CALCULATOR.calculate_centroid(
            _organization_level_output_variables,
            defuzzified_organized_level_outptut_results
        );
    }

    void FuzzyExpertSystemAI::_evaluate_final_results(
        double& centroid,
        double& final_organized_level_outptut_value,
        std::string& final_organized_level_outptut_variable,
        std::unordered_map<std::string, double>& degree_of_truths,
        std::unordered_map<std::string, double>& selected_organized_level_outptut_variables
    )
    {
        for (auto& [key, value] :
            selected_organized_level_outptut_variables)
        {
            double degree_of_membership =
                CALCULATOR.calculate_degree_of_membership(
                    _organization_level_output_variables[key],
                    centroid
                );
            degree_of_truths[key] = degree_of_membership;
            if (final_organized_level_outptut_value < degree_of_membership)
            {
                final_organized_level_outptut_value = degree_of_membership;
                final_organized_level_outptut_variable = key;
            }
        }
    }

    FuzzyExpertSystemAI& FuzzyExpertSystemAI::get_instance()
    {
        static FuzzyExpertSystemAI instance;

        return instance;
    }
}
