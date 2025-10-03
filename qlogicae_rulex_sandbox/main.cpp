#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{            
    QLogicaeRulexCore::FuzzyExpertSystemAIOutput output =
        QLogicaeRulexCore::FUZZY_EXPERT_SYSTEM_AI.evaluate({
            .text = "aaaaaaaaaaaaaaaaaaaa\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\n"
        });

    std::cout << "Enter to exit...\n";

    bool exit_code;
    std::cin >> exit_code;

    return 0;
}
