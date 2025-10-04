#pragma once

#include "ui_about.h"

namespace Ui
{
	class AboutClass;
}

namespace QLogicaeRulex
{
	class About : public QWidget
	{
		Q_OBJECT

	public:
		explicit About(QWidget* parent = nullptr);
		~About();

	protected:
		void showEvent(QShowEvent* event) override;

	private:
		Ui::AboutClass* _ui;
	};
}
