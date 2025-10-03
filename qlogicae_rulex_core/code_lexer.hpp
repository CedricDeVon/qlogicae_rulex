#pragma once

namespace QLogicaeRulexCore
{
    struct CodeLexerInput
    {
        std::string text = "";
    };

    struct CodeLexerOutput
    {
        bool is_successful = true;
        std::string message = "";
        double line_count = 0;
        double longest_line_size = 0;
    };

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
    };

    inline static CodeLexer& CODE_LEXER =
        CodeLexer::get_instance();
}
