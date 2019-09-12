// SPDX-License-Identifier: MIT
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtCharts/QChartView>

QT_CHARTS_USE_NAMESPACE

class Values;
class Chart;

class Window : public QWidget
{
    Q_OBJECT

public slots:
    void handleValueChanged(float temp, float pressure, float humidity);

private slots:
    void chartButtonClicked();
    void valuesButtonClicked();

public:
    Window();

private:
    Values *values;
    QChartView *chartView;
    Chart *chart;
};

#endif
