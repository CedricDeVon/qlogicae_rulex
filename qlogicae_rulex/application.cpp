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
        _ui.setupUi(this);

        _setup_window_screen();
        // _setup_assets();
        // _setup_widgets();
    }

    Application::~Application()
    {

    }

    void Application::_setup_window_screen()
    {
        this->setWindowIcon(
            QIcon(
                QString::fromStdString(
                    QLogicaeRulexCore::UTILITIES.APPLICATION_LOGO
                )
            )
        );
        this->setWindowTitle(
            QString::fromStdString(
                QLogicaeCore::APPLICATION.get_qlogicae_name()
            )
        );
        _change_screen_type(
            0
        );
    }

    void Application::_change_screen_type(uint8_t index)
    {
        switch (index)
        {
            case (0): this->showNormal(); break;
            case (1): this->showFullScreen(); break;
            case (2): this->setWindowState(Qt::WindowMinimized); break;
            case (3): this->showMaximized(); break;
            default: this->showNormal(); break;
        }
    }
}
