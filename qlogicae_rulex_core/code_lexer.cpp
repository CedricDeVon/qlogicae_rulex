#include "pch.hpp"

#include "code_lexer.hpp"

namespace QLogicaeRulexCore
{
    CodeLexer::CodeLexer()
    {

    }

    CodeLexerResult CodeLexer::evaluate(const std::string& text)
    {
        try
        {
            CodeLexerResult result;

            if (!text.size())
            {
                return result;
            }

            for (const auto& line : absl::StrSplit(text, '\n'))
            {
                if (result.longest_line_size < line.size())
                {
                    result.longest_line_size = line.size();
                }

                ++result.line_count;
            }

            return result;
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
