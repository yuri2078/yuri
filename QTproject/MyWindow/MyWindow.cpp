#include "MyWindow.h"
#include <QDebug>
MyWindow::MyWindow(QWidget *parent) : 
	QDialog(parent)
{
	this->setWindowTitle("mywindow");
	button = new QPushButton("这是按钮",this);
	button->resize(200,30);
	button->move(350,500);
	connect(button,&QPushButton::clicked,[=](){
		this->close();
		qDebug() << "hello,你好!";	
			});
	QPushButton *button_2 = new QPushButton("点击更换标题",this);
	button_2->resize(200,30);
	button_2->move(200,200);
	connect(button_2,&QPushButton::clicked,[=](){
		this->setWindowTitle("孙 展 盆 ");
			});
	resize(800,800);
}

MyWindow::~MyWindow()
{

}
