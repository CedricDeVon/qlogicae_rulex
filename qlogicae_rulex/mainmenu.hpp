#pragma once

#include <QWidget>
#include "ui_mainmenu.h"

class MainMenu : public QWidget
{
	Q_OBJECT

public:
	MainMenu(QWidget *parent = nullptr);
	~MainMenu();

private:
	Ui::MainMenuClass ui;
};

