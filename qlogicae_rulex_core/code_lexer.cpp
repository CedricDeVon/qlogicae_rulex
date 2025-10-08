#include "pch.hpp"

#include "code_lexer.hpp"

namespace QLogicaeRulexCore
{
    CodeLexer::CodeLexer()
    {

    }

    CodeLexerOutput CodeLexer::evaluate(
        const CodeLexerInput& input
    )
    {
        try
        {
            CodeLexerOutput output;

            std::ifstream file(input.file_path);
            if (!file.is_open())
            {
                return
                {
                    .is_successful = false
                };
            }

            std::string line;
            while (std::getline(file, line))
            {
                if (output.longest_line_size < line.size())
                {
                    output.longest_line_size = line.size();
                }

                output.average_line_size += line.size();
                ++output.line_count;
            }
            output.average_line_size /= output.line_count;

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

    CodeLexer& CodeLexer::get_instance()
    {
        static CodeLexer instance;

        return instance;
    }
}
