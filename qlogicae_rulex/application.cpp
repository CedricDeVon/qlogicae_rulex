#include "stdafx.h"

#include "application.hpp"

#ifndef x64_MASM_ASSEMBLY

extern "C" void qlogicae_rulex__assembly();

#endif

namespace QLogicaeRulex
{
    Application::Application(QWidget* parent)
        : QMainWindow(parent)
    {
        ui.setupUi(this);
    }

    Application::~Application()
    {

    }
}
