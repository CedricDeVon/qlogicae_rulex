#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{        
    QLogicaeRulexCore::CodeLexerResult result = QLogicaeRulexCore::CODE_LEXER.evaluate(
        "First line\nSecond line\nThird line"
    );

    std::cout << result.is_successful << "\n";
    std::cout << result.line_count << "\n";
    std::cout << result.longest_line_size << "\n";
    std::cout << result.message << "\n";

    std::cout << "Enter to exit...\n";

    bool exit_code;
    std::cin >> exit_code;

    return 0;
}
