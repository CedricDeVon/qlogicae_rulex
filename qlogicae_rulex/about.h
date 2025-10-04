#pragma once

#include "ui_about.h"

namespace QLogicaeRulex
{
	class About : public QWidget
	{
		Q_OBJECT

	public:
		explicit About(QWidget* parent = nullptr);
		~About();

	private:
		Ui::AboutClass _ui;
	};
}
