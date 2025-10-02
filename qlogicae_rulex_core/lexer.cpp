#include "pch.hpp"

#include "lexer.hpp"

namespace QLogicaeRulexCore
{
    Lexer::Lexer()
    {

    }

    Lexer& Lexer::get_instance()
    {
        static Lexer instance;

        return instance;
    }
}
