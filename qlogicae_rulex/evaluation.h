#pragma once

#include <QWidget>
#include "ui_evaluation.h"

class Evaluation : public QWidget
{
	Q_OBJECT

public:
	Evaluation(QWidget *parent = nullptr);
	~Evaluation();

private:
	Ui::EvaluationClass ui;
};

