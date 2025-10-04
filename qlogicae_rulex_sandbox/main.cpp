#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{            
    QLogicaeRulexCore::FuzzyExpertSystemAIOutput output =
        QLogicaeRulexCore::FUZZY_EXPERT_SYSTEM_AI.evaluate({
            .text = "aaaaaaaaaaaaaaaaaaaa\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\n"
        });
    std::cout << output.code_lexer_output.line_count << "\n";
    std::cout << output.code_lexer_output.longest_line_size << "\n";
    for (const auto& value :
        output.selected_longest_line_size_level_input_variables)
    {
        std::cout << value << "\n";
    }
    std::cout << "\n";
    for (const auto& value :
        output.selected_longest_line_size_level_input_variables)
    {
        std::cout << value << "\n";
    }
    std::cout << "\n";
    for (const auto& value :
        output.selected_line_count_level_input_variable_degree_of_memberships)
    {
        std::cout << value << "\n";
    }
    std::cout << "\n";
    for (const auto& value :
        output.selected_longest_line_size_level_input_variable_degree_of_memberships)
    {
        std::cout << value << "\n";
    }
    std::cout << "\n";
    for (auto& [key, value] :
        output.selected_organized_level_outptut_variables)
    {
        std::cout << key << " : " << value << "\n";
    }
    std::cout << "\n";
    for (auto& [key, value] :
        output.defuzzified_organized_level_outptut_results)
    {
        std::cout << key << " : " << value << "\n";
    }
    std::cout << "\n";

    std::cout << output.centroid << "\n";
    std::cout << output.final_organized_level_outptut_value << "\n";
    std::cout << output.final_organized_level_outptut_variable << "\n";
    std::cout << "\n";

    for (auto& [key, value] :
        output.degree_of_truths)
    {
        std::cout << key << " : " << value << "\n";
    }
    std::cout << "\n";

    std::cout << "Enter to exit...\n";

    bool exit_code;
    std::cin >> exit_code;

    return 0;
}
