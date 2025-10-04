#pragma once

#include "ui_settings.h"

namespace QLogicaeRulex
{
	class Settings : public QWidget
	{
		Q_OBJECT

	public:
		explicit Settings(QWidget* parent = nullptr);
		~Settings();

	private:
		Ui::SettingsClass _ui;
	};
}
