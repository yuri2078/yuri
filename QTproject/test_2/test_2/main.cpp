#include "widget.h"

#include <QApplication> //包含一个应用程序类

//argc 命令行变量的数量
//argv 命令行变量的数组
int main(int argc, char *argv[])
{
    //应用程序对象，在qt中，必须且仅仅能有一个引用程序对象
    QApplication a(argc, argv);
    //创建一个窗口类 对象
    Widget w;
    w.show();
    //让引用程序对象，进入到消息循环
    //阻塞程序，此时他仍然会接受数据，但是只有按× 才会停止阻塞
    return a.exec();
}
