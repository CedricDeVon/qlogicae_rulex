#include "stdafx.h"

#include "main.hpp"

int main(int argc, char *argv[])
{
    QLogicaeCore::APPLICATION.setup();
    QLogicaeRulexCore::UTILITIES.setup();

    QApplication app(argc, argv);
    QLogicaeRulex::Application window;

    window.show();

    return app.exec();
}
