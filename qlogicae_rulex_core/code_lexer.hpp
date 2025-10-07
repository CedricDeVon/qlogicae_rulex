#pragma once

#include "utilities.hpp"

namespace QLogicaeRulexCore
{    
    class CodeLexer
    {
    public:
        CodeLexerOutput evaluate(const CodeLexerInput& input);

        static CodeLexer& get_instance();

    private:
        CodeLexer();

        ~CodeLexer() = default;

        CodeLexer(const CodeLexer&) = delete;

        CodeLexer(CodeLexer&&) noexcept = delete;

        CodeLexer& operator = (CodeLexer&&) = delete;

        CodeLexer& operator = (const CodeLexer&) = delete;

        QLogicaeCore::TextFileIO _file;
    };

    inline static CodeLexer& CODE_LEXER =
        CodeLexer::get_instance();
}
