#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char **argv)
{
	//创建qt的应用程序对象
	QApplication app(argc,argv);
	QLabel *label_1 = new QLabel("你好，谢谢!");
	label_1->resize(800,800);
	QLabel *label_1 = new QLabel("你好，谢谢!");
	label_1->show();
	QPushButton *button_1 = new QPushButton("我是按钮");
	button_1->show();
	return app.exec(); //让应用程序进入事件循环
}
