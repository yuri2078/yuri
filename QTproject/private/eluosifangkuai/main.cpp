#include <QApplication>

#include "Welcome.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Welcome welcome;
    welcome.show();

    return app.exec();
}