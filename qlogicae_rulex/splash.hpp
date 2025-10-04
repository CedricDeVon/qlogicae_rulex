#pragma once

#include "ui_splash.h"

namespace QLogicaeRulex
{
	class Splash : public QWidget
	{
		Q_OBJECT

	public:
		explicit Splash(QWidget* parent = nullptr);
		~Splash();

	private:
		Ui::SplashClass _ui;
	};
}
