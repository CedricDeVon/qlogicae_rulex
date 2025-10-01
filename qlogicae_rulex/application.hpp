#pragma once

#include "ui_application.h"

namespace QLogicaeRulex
{
    class Application : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit Application(QWidget *parent = nullptr);
        ~Application();

    private:
        Ui::ApplicationClass _ui;

        // void _setup_assets();
        // void _setup_widgets();
        void _setup_window_screen();
        void _change_screen_type(uint8_t index);
    };
}
