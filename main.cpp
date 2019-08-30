// SPDX-License-Identifier: MIT
#include <QApplication>
#include <QPushButton>
#include "data-provider.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QPushButton hello("Hello world!");
    DataProvider dp;
    hello.resize(100,30);
    hello.show();
    return app.exec();
}
