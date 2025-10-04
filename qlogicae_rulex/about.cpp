#include "stdafx.h"

#include "about.hpp"

namespace QLogicaeRulex
{
	About::About(QWidget* parent)
		: QWidget(parent),
		_ui(new Ui::AboutClass)
	{
		_ui->setupUi(this);
	}

	About::~About()
	{
		delete _ui;
	}

	void About::showEvent(QShowEvent* event)
	{
		_ui->label_7->setText(
			QString::fromStdString(
				QLogicaeCore::APPLICATION.get_qlogicae_version()
			)
		);
		_ui->label_5->setText(
			QString::fromStdString(
				QLogicaeCore::APPLICATION.get_qlogicae_id()
			)
		);
		_ui->label_3->setText(
			QString::fromStdString(
				QLogicaeCore::APPLICATION.get_environment_name()
			)
		);
	}
}
