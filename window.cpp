// SPDX-License-Identifier: MIT
#include <QtWidgets>

#include "window.h"
#include "values.h"
#include "chart.h"

Window::Window()
{
    values = new Values;
    chart = new Chart;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;

    QPushButton *values_button = new QPushButton("Values");
    QPushButton *chart_button = new QPushButton("Chart");

    QObject::connect(chart_button, &QPushButton::clicked,
		     this, &Window::chartButtonClicked);
    QObject::connect(values_button, &QPushButton::clicked,
		     this, &Window::valuesButtonClicked);

    buttons->addWidget(values_button);
    buttons->addWidget(chart_button);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(values);
    layout->addWidget(chartView);
    layout->addLayout(buttons);

    setLayout(layout);

    chartView->hide();

    setWindowTitle(tr("Sensors"));
}

void Window::handleValueChanged(float temp, float pressure, float humidity)
{
    values->handleValueChanged(temp, pressure, humidity);
    chart->handleValueChanged(temp, pressure, humidity);
}

void Window::chartButtonClicked()
{
    values->hide();
    chartView->show();
}

void Window::valuesButtonClicked()
{
    values->show();
    chartView->hide();
}
