#include <QApplication>
#include "Keyboard.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Keyboard keyboard;
    keyboard.show();

    return app.exec();
}
