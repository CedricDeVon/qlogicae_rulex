#include "stdafx.h"

#include "application.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLogicaeRulex::Application window;
    window.show();

    return app.exec();
}
