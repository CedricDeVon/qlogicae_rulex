#include "stdafx.h"

#include "evaluation.hpp"

namespace QLogicaeRulex
{
	Evaluation::Evaluation(QWidget* parent)
		: QWidget(parent),
		    _ui(new Ui::EvaluationClass)
	{
		_ui->setupUi(this);

        _setup_widgets();
	}

    void Evaluation::_setup_widgets()
    {        
        _ui->verticalWidget_2->hide();
        _ui->verticalWidget_2->setVisible(false);

        QLineSeries* series_1_1 = new QLineSeries();
        series_1_1->append(0, 0);
        series_1_1->append(50, 1);
        series_1_1->append(125, 0);
        series_1_1->setPen(QPen(QColor("#208A3C"), 2));

        QLineSeries* series_1_2 = new QLineSeries();
        series_1_2->append(75, 0);
        series_1_2->append(250, 1);
        series_1_2->append(525, 0);
        series_1_2->setPen(QPen(QColor("#3574F0"), 2));

        QLineSeries* series_1_3 = new QLineSeries();
        series_1_3->append(475, 0);
        series_1_3->append(2000, 1);
        series_1_3->append(3525, 0);
        series_1_3->setPen(QPen(QColor("#DB3B4B"), 2));

        _vLine_1 = new QLineSeries();
        QPen vPen_1(QColor("#FFAF0F"));
        vPen_1.setStyle(Qt::SolidLine);
        vPen_1.setWidth(2);
        _vLine_1->setPen(vPen_1);

        QChart* chart_1 = new QChart();
        chart_1->legend()->hide();
        chart_1->addSeries(series_1_1);
        chart_1->addSeries(series_1_2);
        chart_1->addSeries(series_1_3);
        chart_1->addSeries(_vLine_1);
        chart_1->createDefaultAxes();
        chart_1->setTitle("Line Count");

        _vLine_1->attachAxis(chart_1->axes(Qt::Horizontal).first());
        _vLine_1->attachAxis(chart_1->axes(Qt::Vertical).first());

        chart_1->setBackgroundVisible(false);
        chart_1->setPlotAreaBackgroundVisible(false);
        chart_1->setBackgroundPen(QPen(QColor("#9DA0A8")));

        QBrush textBrush_1(QColor("#9DA0A8"));
        chart_1->setTitleBrush(textBrush_1);
        chart_1->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_1);
        chart_1->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_1);

        QChartView* chartView_1 = new QChartView(chart_1);
        chartView_1->setRenderHint(QPainter::Antialiasing);
        chartView_1->setFixedSize(400, 250);

        _ui->horizontalLayout_9->addWidget(chartView_1);



        QLineSeries* series_2_1 = new QLineSeries();
        series_2_1->append(0, 0);
        series_2_1->append(20, 1);
        series_2_1->append(50, 0);
        series_2_1->setPen(QPen(QColor("#208A3C"), 2));

        QLineSeries* series_2_2 = new QLineSeries();
        series_2_2->append(30, 0);
        series_2_2->append(60, 1);
        series_2_2->append(90, 0);
        series_2_2->setPen(QPen(QColor("#3574F0"), 2));

        QLineSeries* series_2_3 = new QLineSeries();
        series_2_3->append(70, 0);
        series_2_3->append(500, 1);
        series_2_3->append(1010, 0);
        series_2_3->setPen(QPen(QColor("#DB3B4B"), 2));

        _vLine_2 = new QLineSeries();
        QPen vPen_2(QColor("#FFAF0F"));
        vPen_2.setStyle(Qt::SolidLine);
        vPen_2.setWidth(2);
        _vLine_2->setPen(vPen_2);

        QChart* chart_2 = new QChart();
        chart_2->legend()->hide();
        chart_2->addSeries(series_2_1);
        chart_2->addSeries(series_2_2);
        chart_2->addSeries(series_2_3);
        chart_2->addSeries(_vLine_2);
        chart_2->createDefaultAxes();
        chart_2->setTitle("Longest Line Size");

        _vLine_2->attachAxis(chart_2->axes(Qt::Horizontal).first());
        _vLine_2->attachAxis(chart_2->axes(Qt::Vertical).first());

        chart_2->setBackgroundVisible(false);
        chart_2->setPlotAreaBackgroundVisible(false);
        chart_2->setBackgroundPen(QPen(QColor("#9DA0A8")));

        QBrush textBrush_2(QColor("#9DA0A8"));
        chart_2->setTitleBrush(textBrush_2);
        chart_2->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_2);
        chart_2->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_2);

        QChartView* chartView_2 = new QChartView(chart_2);
        chartView_2->setRenderHint(QPainter::Antialiasing);
        chartView_2->setFixedSize(400, 250);

        _ui->horizontalLayout_9->addWidget(chartView_2);



        QLineSeries* series_3_1 = new QLineSeries();
        series_3_1->append(0, 0);
        series_3_1->append(10, 1);
        series_3_1->append(25, 0);
        series_3_1->setPen(QPen(QColor("#208A3C"), 2));

        QLineSeries* series_3_2 = new QLineSeries();
        series_3_2->append(15, 0);
        series_3_2->append(30, 1);
        series_3_2->append(45, 0);
        series_3_2->setPen(QPen(QColor("#3574F0"), 2));

        QLineSeries* series_3_3 = new QLineSeries();
        series_3_3->append(35, 0);
        series_3_3->append(60, 1);
        series_3_3->append(85, 0);
        series_3_3->setPen(QPen(QColor("#DB3B4B"), 2));

        _vLine_3 = new QLineSeries();
        QPen vPen_3(QColor("#FFAF0F"));
        vPen_3.setStyle(Qt::SolidLine);
        vPen_3.setWidth(2);
        _vLine_3->setPen(vPen_3);

        QChart* chart_3 = new QChart();
        chart_3->legend()->hide();
        chart_3->addSeries(series_3_1);
        chart_3->addSeries(series_3_2);
        chart_3->addSeries(series_3_3);
        chart_3->addSeries(_vLine_3);
        chart_3->createDefaultAxes();
        chart_3->setTitle("Organization");

        _vLine_3->attachAxis(chart_3->axes(Qt::Horizontal).first());
        _vLine_3->attachAxis(chart_3->axes(Qt::Vertical).first());

        chart_3->setBackgroundVisible(false);
        chart_3->setPlotAreaBackgroundVisible(false);
        chart_3->setBackgroundPen(QPen(QColor("#9DA0A8")));

        QBrush textBrush_3(QColor("#9DA0A8"));
        chart_3->setTitleBrush(textBrush_3);
        chart_3->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_3);
        chart_3->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_3);

        QChartView* chartView_3 = new QChartView(chart_3);
        chartView_3->setRenderHint(QPainter::Antialiasing);
        chartView_3->setFixedSize(400, 250);

        _ui->horizontalLayout_7->addWidget(chartView_3);

        connect(_ui->pushButton_10, &QPushButton::pressed,
            this, [this]()
            {
                _on_input_changed();
            }
        );
    }

    void Evaluation::_on_input_changed()
    {        
        _ui->verticalWidget_2->hide();
        _ui->verticalWidget_2->setVisible(false);

        std::string style_1 =
            "QLabel{"
            "color: #EBECF0;"
            "background: #208A3C;"
            "padding: 2px 8px;"
            "border-radius: 4px;"
            "}";

        std::string style_2 =
            "QLabel{"
            "color: #EBECF0;"
            "background: #3574F0;"
            "padding: 2px 8px;"
            "border-radius: 4px;"
            "}";

        std::string style_3 =
            "QLabel{"
            "color: #EBECF0;"
            "background: #DB3B4B;"
            "padding: 2px 8px;"
            "border-radius: 4px;"
            "}";

        std::string style_4 =
            "QLabel{"
            "color: #1E1F22;"
            "background: #FFAF0F;"
            "padding: 2px 8px;"
            "border-radius: 4px;"
            "}";

        QString file_name = QFileDialog::getOpenFileName(
            this,
            "Open File",
            "",
            "All Files (*);;Text Files (*.txt)"
        );

        if (file_name.isEmpty())
        {
            return;
        }

        QLogicaeRulexCore::FuzzyExpertSystemAIOutput output =
            QLogicaeRulexCore::FUZZY_EXPERT_SYSTEM_AI.evaluate({
                .file_path = file_name.toStdString()
            });

        _ui->label_15->setText(file_name);

        std::string label_text, value_text;
        size_t index_a,
            size_a = output.selected_line_count_level_input_variables.size(),
            size_b = size_a - 1;
        label_text = "";
        for (index_a = 0; index_a < size_a; ++index_a)
        {
            label_text += output.selected_line_count_level_input_variables[index_a];
            if (index_a < size_b)
            {
                label_text += ", ";
            }
        }
        _ui->label_31->setText(QString::fromStdString(label_text));
        _ui->label_30->setText(QString::fromStdString(absl::StrCat(output.code_lexer_output.line_count)));
        if (size_a > 1)
        {
            _ui->label_31->setStyleSheet(QString::fromStdString(style_4));
            _ui->label_30->setStyleSheet(QString::fromStdString(style_4));
        }
        else if (size_a == 1)
        {
            std::string variable = output.selected_line_count_level_input_variables[0];
            if (variable == "small")
            {
                _ui->label_31->setStyleSheet(QString::fromStdString(style_1));
                _ui->label_30->setStyleSheet(QString::fromStdString(style_1));
            }
            else if (variable == "medium")
            {
                _ui->label_31->setStyleSheet(QString::fromStdString(style_2));
                _ui->label_30->setStyleSheet(QString::fromStdString(style_2));
            }
            else if (variable == "large")
            {
                _ui->label_31->setStyleSheet(QString::fromStdString(style_3));
                _ui->label_30->setStyleSheet(QString::fromStdString(style_3));
            }
        }

        _vLine_1->clear();
        _vLine_1->append(output.code_lexer_output.line_count, 0);
        _vLine_1->append(output.code_lexer_output.line_count, 1);

        _vLine_2->clear();
        _vLine_2->append(output.code_lexer_output.longest_line_size, 0);
        _vLine_2->append(output.code_lexer_output.longest_line_size, 1);

        _vLine_3->clear();
        _vLine_3->append(output.centroid, 0);
        _vLine_3->append(output.centroid, 1);

        size_a = output.selected_longest_line_size_level_input_variables.size(),
        size_b = size_a - 1;
        label_text = "";
        for (index_a = 0; index_a < size_a; ++index_a)
        {
            label_text += output.selected_longest_line_size_level_input_variables[index_a];
            if (index_a < size_b)
            {
                label_text += ", ";
            }
        }
        _ui->label_34->setText(QString::fromStdString(label_text));
        _ui->label_33->setText(QString::fromStdString(absl::StrCat(output.code_lexer_output.longest_line_size)));
        if (size_a > 1)
        {
            _ui->label_34->setStyleSheet(QString::fromStdString(style_4));
            _ui->label_33->setStyleSheet(QString::fromStdString(style_4));
        }
        else if (size_a == 1)
        {
            std::string variable = output.selected_longest_line_size_level_input_variables[0];
            if (variable == "short")
            {
                _ui->label_34->setStyleSheet(QString::fromStdString(style_1));
                _ui->label_33->setStyleSheet(QString::fromStdString(style_1));
            }
            else if (variable == "medium")
            {
                _ui->label_34->setStyleSheet(QString::fromStdString(style_2));
                _ui->label_33->setStyleSheet(QString::fromStdString(style_2));
            }
            else if (variable == "long")
            {
                _ui->label_34->setStyleSheet(QString::fromStdString(style_3));
                _ui->label_33->setStyleSheet(QString::fromStdString(style_3));
            }
        }

        _ui->label_35->setText(QString::fromStdString(output.final_organized_level_outptut_variable));
        _ui->label_16->setText(QString::fromStdString(absl::StrCat(output.centroid)));
        if (output.final_organized_level_outptut_variable == "organized")
        {
            _ui->label_35->setStyleSheet(QString::fromStdString(style_1));
            _ui->label_16->setStyleSheet(QString::fromStdString(style_1));
        }
        else if (output.final_organized_level_outptut_variable == "mixed")
        {
            _ui->label_35->setStyleSheet(QString::fromStdString(style_2));
            _ui->label_16->setStyleSheet(QString::fromStdString(style_2));
        }
        else if (output.final_organized_level_outptut_variable == "unorganized")
        {
            _ui->label_35->setStyleSheet(QString::fromStdString(style_3));
            _ui->label_16->setStyleSheet(QString::fromStdString(style_3));
        }

        size_a = output.selected_line_count_level_input_variables.size(),
            size_b = size_a - 1;
        label_text = "";
        for (index_a = 0; index_a < size_a; ++index_a)
        {
            label_text += absl::StrCat(output.selected_line_count_level_input_variables[index_a], " (", output.selected_line_count_level_input_variable_degree_of_memberships[index_a],")");
            if (index_a < size_b)
            {
                label_text += ", ";
            }
        }
        _ui->label_19->setText(QString::fromStdString(label_text));
        if (size_a > 1)
        {
            _ui->label_19->setStyleSheet(QString::fromStdString(style_4));
        }
        else if (size_a == 1)
        {
            std::string variable = output.selected_line_count_level_input_variables[0];
            if (variable == "small")
            {
                _ui->label_19->setStyleSheet(QString::fromStdString(style_1));
            }
            else if (variable == "medium")
            {
                _ui->label_19->setStyleSheet(QString::fromStdString(style_2));
            }
            else if (variable == "large")
            {
                _ui->label_19->setStyleSheet(QString::fromStdString(style_3));
            }
        }

        size_a = output.selected_longest_line_size_level_input_variables.size(),
            size_b = size_a - 1;
        label_text = "";
        for (index_a = 0; index_a < size_a; ++index_a)
        {
            label_text += absl::StrCat(output.selected_longest_line_size_level_input_variables[index_a], " (", output.selected_longest_line_size_level_input_variable_degree_of_memberships[index_a], ")");
            if (index_a < size_b)
            {
                label_text += ", ";
            }
        }
        _ui->label_20->setText(QString::fromStdString(label_text));
        if (size_a > 1)
        {
            _ui->label_20->setStyleSheet(QString::fromStdString(style_4));
        }
        else if (size_a == 1)
        {
            std::string variable = output.selected_longest_line_size_level_input_variables[0];
            if (variable == "short")
            {
                _ui->label_20->setStyleSheet(QString::fromStdString(style_1));
            }
            else if (variable == "medium")
            {
                _ui->label_20->setStyleSheet(QString::fromStdString(style_2));
            }
            else if (variable == "long")
            {
                _ui->label_20->setStyleSheet(QString::fromStdString(style_3));
            }
        }

        index_a = 0;
        size_a = output.defuzzified_organized_level_outptut_results.size(),
            size_b = size_a - 1;
        label_text = "";
        for (const auto& [key, value] : output.defuzzified_organized_level_outptut_results)
        {
            label_text += absl::StrCat(key, " (", value, ")");
            if (index_a < size_b)
            {
                label_text += ", ";
            }
            ++index_a;
        }        
        _ui->label_29->setText(QString::fromStdString(label_text));        
        _ui->label_28->setText(QString::fromStdString(absl::StrCat(output.centroid)));
        
        index_a = 0;
        size_a = output.degree_of_truths.size(),
            size_b = size_a - 1;
        label_text = "";
        for (const auto& [key, value] : output.degree_of_truths)
        {
            label_text += absl::StrCat(key, " (", value, ")");
            if (index_a < size_b)
            {
                label_text += ", ";
            }
            ++index_a;
        }
        _ui->label_27->setText(QString::fromStdString(label_text));
        if (size_a > 1)
        {
            _ui->label_29->setStyleSheet(QString::fromStdString(style_4));
            _ui->label_28->setStyleSheet(QString::fromStdString(style_4));
            _ui->label_27->setStyleSheet(QString::fromStdString(style_4));
        }
        else if (size_a == 1)
        {
            for (const auto& [key, value] : output.defuzzified_organized_level_outptut_results)
            {
                if (key == "organized")
                {
                    _ui->label_29->setStyleSheet(QString::fromStdString(style_1));
                    _ui->label_28->setStyleSheet(QString::fromStdString(style_1));
                    _ui->label_27->setStyleSheet(QString::fromStdString(style_1));
                    break;
                }
                else if (key == "mixed")
                {
                    _ui->label_29->setStyleSheet(QString::fromStdString(style_2));
                    _ui->label_28->setStyleSheet(QString::fromStdString(style_2));
                    _ui->label_27->setStyleSheet(QString::fromStdString(style_2));
                    break;
                }
                else if (key == "unorganized")
                {
                    _ui->label_29->setStyleSheet(QString::fromStdString(style_3));
                    _ui->label_28->setStyleSheet(QString::fromStdString(style_3));
                    _ui->label_27->setStyleSheet(QString::fromStdString(style_3));
                    break;
                }
            }
        }

        _ui->label_25->setText(QString::fromStdString(output.final_organized_level_outptut_variable));
        _ui->label_26->setText(QString::fromStdString(absl::StrCat(output.final_organized_level_outptut_value)));

        if (output.final_organized_level_outptut_variable == "organized")
        {
            _ui->label_25->setStyleSheet(QString::fromStdString(style_1));
            _ui->label_26->setStyleSheet(QString::fromStdString(style_1));
        }
        else if (output.final_organized_level_outptut_variable == "mixed")
        {
            _ui->label_25->setStyleSheet(QString::fromStdString(style_2));
            _ui->label_26->setStyleSheet(QString::fromStdString(style_2));
        }
        else if (output.final_organized_level_outptut_variable == "unorganized")
        {
            _ui->label_25->setStyleSheet(QString::fromStdString(style_3));
            _ui->label_26->setStyleSheet(QString::fromStdString(style_3));
        }

        _ui->verticalWidget_2->show();
        _ui->verticalWidget_2->setVisible(true);
    }
	Evaluation::~Evaluation()
	{
        delete _ui;
	}

	void Evaluation::showEvent(QShowEvent* event)
	{

	}
}
