// SPDX-License-Identifier: MIT
#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart: public QChart
{
    Q_OBJECT

public:
    Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);

public slots:
    void handleValueChanged(float temp, float pressure, float humidity);

private:
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    int xpos;
};

#endif /* CHART_H */
