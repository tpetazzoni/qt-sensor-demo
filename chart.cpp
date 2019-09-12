// SPDX-License-Identifier: MIT
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include "chart.h"

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    xpos(0)
{
    m_series = new QSplineSeries(this);
    QPen pen(Qt::red);
    pen.setWidth(2);
    m_series->setPen(pen);
    m_series->append(xpos, 30);

    addSeries(m_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(5);
    m_axisX->setRange(0, 60);
    m_axisY->setRange(0, 50);

    QFont f = m_axisX->labelsFont();
    f.setPointSize(8);
    m_axisX->setLabelsFont(f);
    m_axisY->setLabelsFont(f);

    setMargins(QMargins(0,0,0,0));

    setTitle("Temperature (°C)");
    legend()->hide();
}

void Chart::handleValueChanged(float temp, float pressure, float humidity)
{
    Q_UNUSED(pressure);
    Q_UNUSED(humidity);
    m_series->append(xpos, temp);
    xpos++;
    if (xpos >= 60)
      scroll(plotArea().width() / 60, 0);
}
