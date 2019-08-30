// SPDX-License-Identifier: MIT
#ifndef VALUES_H
#define VALUES_H

#include <QWidget>

class QLabel;

class Values : public QWidget
{
    Q_OBJECT

public:
    Values();

public slots:
    void handleValueChanged(float temp, float pressure, float humidity);

private:
    QLabel *temperature_v;
    QLabel *pressure_v;
    QLabel *humidity_v;
};

#endif /* VALUES_H */
