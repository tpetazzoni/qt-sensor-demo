// SPDX-License-Identifier: MIT
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class Values;

class Window : public QWidget
{
    Q_OBJECT

public slots:
    void handleValueChanged(float temp, float pressure, float humidity);

public:
    Window();

private:
    Values *values;
};

#endif
