#pragma once

#include "ui_evaluation.h"

namespace QLogicaeRulex
{
	class Evaluation : public QWidget
	{
		Q_OBJECT

	public:
		explicit Evaluation(QWidget* parent = nullptr);
		~Evaluation();

	private:
		Ui::EvaluationClass _ui;
	};
}
