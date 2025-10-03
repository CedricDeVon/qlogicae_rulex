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

            if (!input.text.size())
            {
                return output;
            }

            for (const auto& line : absl::StrSplit(input.text, '\n'))
            {
                if (output.longest_line_size < line.size())
                {
                    output.longest_line_size = line.size();
                }

                ++output.line_count;
            }

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
