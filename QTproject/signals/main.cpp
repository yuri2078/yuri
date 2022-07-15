#include <QApplication>
#include "mainwindow.h"

//研究信号和槽 对应练习 test_2

int main (int argc, char** argv)
{
	QApplication app(argc, argv);
	mainwindow w;
	w.show();
	return app.exec();
}
