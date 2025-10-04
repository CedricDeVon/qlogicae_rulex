#pragma once

#include "ui_loading.h"

namespace QLogicaeRulex
{
	class Loading : public QWidget
	{
		Q_OBJECT

	public:
		explicit Loading(QWidget* parent = nullptr);
		~Loading();

	private:
		Ui::LoadingClass _ui;
	};
}
