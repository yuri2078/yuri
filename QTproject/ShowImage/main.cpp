#include <QApplication>
#include "ShowImage.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ShowImage showimage;
    
    showimage.show();

    return app.exec();
}
