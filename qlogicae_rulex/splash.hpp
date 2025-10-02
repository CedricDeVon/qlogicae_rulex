#pragma once

#include <QWidget>
#include "ui_splash.h"

class Splash : public QWidget
{
	Q_OBJECT

public:
	Splash(QWidget *parent = nullptr);
	~Splash();

private:
	Ui::SplashClass ui;
};

