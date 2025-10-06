#pragma once

#include "ui_evaluation.h"

namespace Ui
{
	class EvaluationClass;
}

namespace QLogicaeRulex
{
	class Evaluation : public QWidget
	{
		Q_OBJECT

	public:
		explicit Evaluation(QWidget* parent = nullptr);
		~Evaluation();

	protected:
		void showEvent(QShowEvent* event) override;
		void _setup_widgets();
		void _on_input_changed();

	private:
		Ui::EvaluationClass* _ui;
	};
}

