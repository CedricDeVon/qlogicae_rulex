#pragma once

namespace QLogicaeRulexCore
{
    struct CodeLexerResult
    {
        bool is_successful = true;
        std::string message = "";
        uint64_t line_count = 0;
        uint64_t longest_line_size = 0;
    };

    class CodeLexer
    {
    public:
        CodeLexerResult evaluate(const std::string& text);

        static CodeLexer& get_instance();

    private:
        CodeLexer();
        ~CodeLexer() = default;
        CodeLexer(const CodeLexer&) = delete;
        CodeLexer(CodeLexer&&) noexcept = delete;
        CodeLexer& operator = (CodeLexer&&) = delete;
        CodeLexer& operator = (const CodeLexer&) = delete;
    };

    inline static CodeLexer& CODE_LEXER =
        CodeLexer::get_instance();
}
