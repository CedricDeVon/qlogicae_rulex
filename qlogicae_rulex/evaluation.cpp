#include "stdafx.h"

#include "evaluation.hpp"

namespace QLogicaeRulex
{
	Evaluation::Evaluation(QWidget* parent)
		: QWidget(parent),
		    _ui(new Ui::EvaluationClass)
	{
		_ui->setupUi(this);

        QLineSeries* series_1_1 = new QLineSeries();
        series_1_1->append(0, 1);
        series_1_1->append(50, 1);
        series_1_1->append(110, 0);
        series_1_1->setPen(QPen(QColor(0, 200, 0), 2));

        QLineSeries* series_1_2 = new QLineSeries();
        series_1_2->append(90, 0);
        series_1_2->append(130, 1);
        series_1_2->append(370, 1);
        series_1_2->append(410, 0);
        series_1_2->setPen(QPen(QColor(0, 210, 0), 2));

        QLineSeries* series_1_3 = new QLineSeries();
        series_1_3->append(390, 0);
        series_1_3->append(440, 1);
        series_1_3->append(1570, 1);
        series_1_3->append(1610, 0);
        series_1_3->setPen(QPen(QColor(0, 220, 0), 2));


        QLineSeries* vLine_1 = new QLineSeries();
        vLine_1->append(5, 0);  
        vLine_1->append(5, 1); 
        QPen vPen_1(Qt::red);
        vPen_1.setStyle(Qt::SolidLine);
        vPen_1.setWidth(2);
        vLine_1->setPen(vPen_1);

        QChart* chart_1 = new QChart();
        chart_1->legend()->hide();
        chart_1->addSeries(series_1_1);
        chart_1->addSeries(series_1_2);
        chart_1->addSeries(series_1_3);
        chart_1->addSeries(vLine_1);
        chart_1->createDefaultAxes();
        chart_1->setTitle("Line Count");

        vLine_1->attachAxis(chart_1->axes(Qt::Horizontal).first());
        vLine_1->attachAxis(chart_1->axes(Qt::Vertical).first());

        chart_1->setBackgroundVisible(false);
        chart_1->setPlotAreaBackgroundVisible(false);
        chart_1->setBackgroundPen(QPen(Qt::lightGray));

        QBrush textBrush_1(Qt::lightGray);
        chart_1->setTitleBrush(textBrush_1);
        chart_1->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_1);
        chart_1->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_1);

        QChartView* chartView_1 = new QChartView(chart_1);
        chartView_1->setRenderHint(QPainter::Antialiasing);
        chartView_1->setFixedSize(400, 250);

        _ui->horizontalLayout_9->addWidget(chartView_1);



        QLineSeries* series_2 = new QLineSeries();
        series_2->append(0, 6);
        series_2->append(2, 4);
        series_2->append(3, 8);
        series_2->append(7, 4);
        series_2->append(10, 5);

        series_2->setPen(QPen(QColor(0, 200, 0), 2));

        QLineSeries* vLine_2 = new QLineSeries();
        vLine_2->append(5, 0);
        vLine_2->append(5, 10);
        QPen vPen_2(Qt::red);
        vPen_2.setStyle(Qt::SolidLine);
        vPen_2.setWidth(2);
        vLine_2->setPen(vPen_2);

        QChart* chart_2 = new QChart();
        chart_2->legend()->hide();
        chart_2->addSeries(series_2);
        chart_2->addSeries(vLine_2);
        chart_2->createDefaultAxes();
        chart_2->setTitle("Longest Line Size");

        vLine_2->attachAxis(chart_2->axes(Qt::Horizontal).first());
        vLine_2->attachAxis(chart_2->axes(Qt::Vertical).first());

        chart_2->setBackgroundVisible(false);
        chart_2->setPlotAreaBackgroundVisible(false);
        chart_2->setBackgroundPen(QPen(Qt::lightGray));

        QBrush textBrush_2(Qt::lightGray);
        chart_2->setTitleBrush(textBrush_2);
        chart_2->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_2);
        chart_2->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_2);

        QChartView* chartView_2 = new QChartView(chart_2);
        chartView_2->setRenderHint(QPainter::Antialiasing);
        chartView_2->setFixedSize(400, 250);

        _ui->horizontalLayout_9->addWidget(chartView_2);


        QLineSeries* series_3 = new QLineSeries();
        series_3->append(0, 6);
        series_3->append(2, 4);
        series_3->append(3, 8);
        series_3->append(7, 4);
        series_3->append(10, 5);

        series_3->setPen(QPen(QColor(0, 200, 0), 2));

        QLineSeries* vLine_3 = new QLineSeries();
        vLine_3->append(5, 0);
        vLine_3->append(5, 10);
        QPen vPen_3(Qt::red);
        vPen_3.setStyle(Qt::SolidLine);
        vPen_3.setWidth(2);
        vLine_3->setPen(vPen_3);

        QChart* chart_3 = new QChart();
        chart_3->legend()->hide();
        chart_3->addSeries(series_3);
        chart_3->addSeries(vLine_3);
        chart_3->createDefaultAxes();
        chart_3->setTitle("Organization");

        vLine_3->attachAxis(chart_3->axes(Qt::Horizontal).first());
        vLine_3->attachAxis(chart_3->axes(Qt::Vertical).first());

        chart_3->setBackgroundVisible(false);
        chart_3->setPlotAreaBackgroundVisible(false);
        chart_3->setBackgroundPen(QPen(Qt::lightGray));

        QBrush textBrush_3(Qt::lightGray);
        chart_3->setTitleBrush(textBrush_3);
        chart_3->axes(Qt::Horizontal).first()->setLabelsBrush(textBrush_3);
        chart_3->axes(Qt::Vertical).first()->setLabelsBrush(textBrush_3);

        QChartView* chartView_3 = new QChartView(chart_3);
        chartView_3->setRenderHint(QPainter::Antialiasing);
        chartView_3->setFixedSize(400, 250);

        _ui->horizontalLayout_7->addWidget(chartView_3);
	}

	Evaluation::~Evaluation()
	{
        delete _ui;
	}

	void Evaluation::showEvent(QShowEvent* event)
	{

        /*
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Open File",
            "",
            "All Files (*);;Text Files (*.txt)"
        );

        if (!fileName.isEmpty())
        {
            _ui->label->setText(fileName);
        }

        
        */
	}
}
