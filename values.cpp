// SPDX-License-Identifier: MIT
#include <QtWidgets>
#include "values.h"

Values::Values()
{
    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *temperature_l = new QLabel(tr("Temperature (°C)"));
    QLabel *pressure_l = new QLabel(tr("Pressure (hPa)"));
    QLabel *humidity_l = new QLabel(tr("Humidity (%)"));

    temperature_v = new QLabel();
    pressure_v = new QLabel();
    humidity_v = new QLabel();

    QFont f = temperature_v->font();
    f.setPointSize(28);
    f.setBold(true);
    temperature_v->setFont(f);
    pressure_v->setFont(f);
    humidity_v->setFont(f);
    temperature_v->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    pressure_v->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    humidity_v->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    layout->addWidget(temperature_l);
    layout->addWidget(temperature_v);
    layout->addWidget(pressure_l);
    layout->addWidget(pressure_v);
    layout->addWidget(humidity_l);
    layout->addWidget(humidity_v);

    setLayout(layout);
}

void Values::handleValueChanged(float temp, float pressure, float humidity)
{
    temperature_v->setText(QString::number(temp, 'f', 2));
    pressure_v->setText(QString::number(pressure, 'f', 1));
    humidity_v->setText(QString::number(humidity, 'f', 1));
}
