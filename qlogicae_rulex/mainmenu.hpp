#pragma once

#include "ui_mainmenu.h"

namespace QLogicaeRulex
{
	class MainMenu : public QWidget
	{
		Q_OBJECT

	public:
		explicit MainMenu(QWidget* parent = nullptr);
		~MainMenu();

	private:
		Ui::MainMenuClass _ui;
	};
}
