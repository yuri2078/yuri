#include <QApplication>
#include "loginWidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    LoginWidget loginwidget;
    loginwidget.show();

    return app.exec();
}
