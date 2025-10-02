#pragma once

namespace QLogicaeRulexCore
{
    class Lexer
    {
    public:
        static Lexer& get_instance();

    private:
        Lexer();
        ~Lexer() = default;
        Lexer(const Lexer&) = delete;
        Lexer(Lexer&&) noexcept = delete;
        Lexer& operator = (Lexer&&) = delete;
        Lexer& operator = (const Lexer&) = delete;
    };

    inline static Lexer& LEXER =
        Lexer::get_instance();
}
