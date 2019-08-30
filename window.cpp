// SPDX-License-Identifier: MIT
#include <QtWidgets>

#include "window.h"
#include "values.h"

Window::Window()
{
    values = new Values;
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;

    QPushButton *values_button = new QPushButton("Values");
    QPushButton *chart_button = new QPushButton("Chart");

    buttons->addWidget(values_button);
    buttons->addWidget(chart_button);

    layout->addWidget(values);
    layout->addLayout(buttons);

    setLayout(layout);

    setWindowTitle(tr("Sensors"));
}

void Window::handleValueChanged(float temp, float pressure, float humidity)
{
    values->handleValueChanged(temp, pressure, humidity);
}
