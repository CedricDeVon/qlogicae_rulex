#include "pch.hpp"

#include "fuzzy_expert_system_ai.hpp"

namespace QLogicaeRulexCore
{
    FuzzyExpertSystemAIVariable::FuzzyExpertSystemAIVariable(
        const double& minimum,
        const double& middle,
        const double& maximum,
        const std::string& name
    )
    {
        _name = name;
        _minimum = minimum;
        _middle = middle;
        _maximum = maximum;
    }

    std::string FuzzyExpertSystemAIVariable::get_name()
    {
        return _name;
    }

    double FuzzyExpertSystemAIVariable::get_minimum()
    {
        return _minimum;
    }

    double FuzzyExpertSystemAIVariable::get_middle()
    {
        return _middle;
    }

    double FuzzyExpertSystemAIVariable::get_maximum()
    {
        return _maximum;
    }

    double FuzzyExpertSystemAIVariable::calculate_degree_of_membership(
        const double& value
    )
    {
        if (value > _middle)
        {
            return (_maximum - value) / (_maximum - _middle);
        }
        else if (value == _middle)
        {
            return 1;
        }
        else
        {
            return (value - _minimum) / (_middle - _minimum);
        }
    }

    bool FuzzyExpertSystemAIVariable::is_within_bounds(
        const double& value
    )
    {
        return (_minimum <= value && value <= _maximum);
    }

    FuzzyExpertSystemAI::FuzzyExpertSystemAI()
    {
        _line_count_variables =
        {
            FuzzyExpertSystemAIVariable(0, 50, 110, "small"),
            FuzzyExpertSystemAIVariable(90, 200, 410, "medium"),
            FuzzyExpertSystemAIVariable(390, 800, 1610, "large")
        };

        _longest_line_size_variables =
        {
            FuzzyExpertSystemAIVariable(0, 10, 21, "short"),
            FuzzyExpertSystemAIVariable(19, 50, 81, "medium"),
            FuzzyExpertSystemAIVariable(80, 120, 161, "long")
        };

        _organized_classifications =
        {
            { "organized", FuzzyExpertSystemAIVariable(0, 10, 21, "organized")},
            { "mildly-organized", FuzzyExpertSystemAIVariable(19, 30, 41, "mildly-organized") },
            { "unorganized", FuzzyExpertSystemAIVariable(39, 60, 81, "unorganized") }
        };
    }

    FuzzyExpertSystemAIOutput FuzzyExpertSystemAI::evaluate(
        const FuzzyExpertSystemAIInput& input
    )
    {
        try
        {
            FuzzyExpertSystemAIOutput output;

            CodeLexerOutput code_lexer_output = CODE_LEXER.evaluate({
                .text = input.text
                });
            std::cout << code_lexer_output.line_count << "\n";
            std::cout << code_lexer_output.longest_line_size << "\n";


            std::vector<FuzzyExpertSystemAIVariable> selected_line_count_variables;
            for (auto& line_count_variable : _line_count_variables)
            {
                if (line_count_variable.is_within_bounds(code_lexer_output.line_count))
                {
                    selected_line_count_variables.push_back(line_count_variable);
                }
            }

            std::vector<FuzzyExpertSystemAIVariable> selected_longest_line_size_variables;
            for (auto& longest_line_size_variable : _longest_line_size_variables)
            {
                if (longest_line_size_variable.is_within_bounds(code_lexer_output.longest_line_size))
                {
                    selected_longest_line_size_variables.push_back(longest_line_size_variable);
                }
            }

            std::vector<double> selected_line_count_degree_of_membership_results;
            for (auto& line_count_variable : selected_line_count_variables)
            {
                selected_line_count_degree_of_membership_results.push_back(
                    line_count_variable.calculate_degree_of_membership(
                        code_lexer_output.line_count
                    )
                );
            }

            std::vector<double> selected_longest_line_size_degree_of_membership_results;
            for (auto& longest_line_size_variable : selected_longest_line_size_variables)
            {
                selected_longest_line_size_degree_of_membership_results.push_back(
                    longest_line_size_variable.calculate_degree_of_membership(
                        code_lexer_output.longest_line_size
                    )
                );
            }

            size_t line_count_variable_index,
                longest_line_size_variable_index,
                line_count_variable_size = selected_line_count_variables.size(),
                longest_line_size_variable_size = selected_longest_line_size_variables.size();
            std::unordered_map<std::string, double> selected_outptut_variables;
            for (line_count_variable_index = 0;
                line_count_variable_index < line_count_variable_size;
                ++line_count_variable_index)
            {
                double selected_line_count_degree_of_membership =
                    selected_line_count_degree_of_membership_results[line_count_variable_index];
                std::string selected_line_count_name =
                    selected_line_count_variables[line_count_variable_index].get_name();
                for (longest_line_size_variable_index = 0;
                    longest_line_size_variable_index < longest_line_size_variable_size;
                    ++longest_line_size_variable_index)
                {
                    double selected_longest_line_size_degree_of_membership =
                        selected_longest_line_size_degree_of_membership_results[longest_line_size_variable_index];
                    std::string selected_longest_line_size_name =
                        selected_longest_line_size_variables[longest_line_size_variable_index].get_name();
                    
                    if (selected_line_count_name == "small" && selected_longest_line_size_name == "short")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("organized"))
                        {
                            selected_outptut_variables["organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["organized"] = std::min(value, selected_outptut_variables["organized"]);
                        }
                    }
                    else if (selected_line_count_name == "small" && selected_longest_line_size_name == "medium")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("organized"))
                        {
                            selected_outptut_variables["organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["organized"] = std::min(value, selected_outptut_variables["organized"]);
                        }
                    }
                    else if (selected_line_count_name == "small" && selected_longest_line_size_name == "long")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("mildly-organized"))
                        {
                            selected_outptut_variables["mildly-organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["mildly-organized"] = std::min(value, selected_outptut_variables["mildly-organized"]);
                        }
                    }
                    else if (selected_line_count_name == "medium" && selected_longest_line_size_name == "short")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("organized"))
                        {
                            selected_outptut_variables["organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["organized"] = std::min(value, selected_outptut_variables["organized"]);
                        }
                    }
                    else if (selected_line_count_name == "medium" && selected_longest_line_size_name == "medium")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("mildly-organized"))
                        {
                            selected_outptut_variables["mildly-organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["mildly-organized"] = std::min(value, selected_outptut_variables["mildly-organized"]);
                        }
                    }
                    else if (selected_line_count_name == "medium" && selected_longest_line_size_name == "long")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("unorganized"))
                        {
                            selected_outptut_variables["unorganized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["unorganized"] = std::min(value, selected_outptut_variables["unorganized"]);
                        }
                    }
                    else if (selected_line_count_name == "large" && selected_longest_line_size_name == "short")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("mildly-organized"))
                        {
                            selected_outptut_variables["mildly-organized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["mildly-organized"] = std::min(value, selected_outptut_variables["mildly-organized"]);
                        }
                    }
                    else if (selected_line_count_name == "large" && selected_longest_line_size_name == "medium")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("unorganized"))
                        {
                            selected_outptut_variables["unorganized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["unorganized"] = std::min(value, selected_outptut_variables["unorganized"]);
                        }
                    }
                    else if (selected_line_count_name == "large" && selected_longest_line_size_name == "long")
                    {
                        double value = std::min(selected_line_count_degree_of_membership, selected_longest_line_size_degree_of_membership);
                        if (!selected_outptut_variables.contains("unorganized"))
                        {
                            selected_outptut_variables["unorganized"] = value;
                        }
                        else
                        {
                            selected_outptut_variables["unorganized"] = std::min(value, selected_outptut_variables["unorganized"]);
                        }
                    }
                }
            }


            for (auto& line_count_variable : selected_line_count_variables)
            {
                std::cout << line_count_variable.get_name() << "\n";
            }
            std::cout << "\n";
            for (auto& longest_line_size_variable : selected_longest_line_size_variables)
            {
                std::cout << longest_line_size_variable.get_name() << "\n";
            }
            std::cout << "\n";
            for (auto& value : selected_line_count_degree_of_membership_results)
            {
                std::cout << value << "\n";
            }
            std::cout << "\n";
            for (auto& value : selected_longest_line_size_degree_of_membership_results)
            {
                std::cout << value << "\n";
            }
            std::cout << "\n";
            for (auto& [key, value] : selected_outptut_variables)
            {
                std::cout << key << " : " << value << "\n";
            }
            std::cout << "\n";




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

    FuzzyExpertSystemAI& FuzzyExpertSystemAI::get_instance()
    {
        static FuzzyExpertSystemAI instance;

        return instance;
    }
}
