// SPDX-License-Identifier: MIT
#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include <QtCore/QTimer>

class DataProvider: public QObject
{
    Q_OBJECT

public:
    DataProvider();

private slots:
    void handleTimer();

signals:
    void valueChanged(float temp, float pressure, float humidity);

private:
    QTimer timer;
};

#endif /* DATA_PROVIDER_H */
