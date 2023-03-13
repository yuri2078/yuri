#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QDebug>

mainwindow::mainwindow(QWidget *parent) : QDialog(parent)
{
	resize(800,800);
	QPushButton *button_1 = new QPushButton("点击关闭",this);
	button_1->resize(200,30);
	button_1->move(300,300);
	mainwindow::connect(this,&mainwindow::laugh,this,&mainwindow::myClose);
	mainwindow::connect(button_1,&QPushButton::clicked,[=](){
		emit this->laugh(); //emit 表示信号的发生，没有意义
		});

	QPushButton  *button_2 = new QPushButton("点我关闭下面那个东西",this);
	button_2->resize(200,30);
	button_2->move(300,600);

	QPushButton  *button_3 = new QPushButton("点我可以关闭窗口",this);
	button_3->resize(200,30);
	button_3->move(300,200);

	QLabel *label = new QLabel("yuri is yes",this);
	label->move(300,640);
	label->resize(200,30);
	
	QPushButton  *button_4 = new QPushButton("点我可打开另一个窗口",this);
	button_4->resize(200,30);
	button_4->move(300,400);

	mainwindow::connect(button_2,&QPushButton::clicked,[=](){
		label->close();	
		});

	mainwindow::connect(button_3,&QPushButton::clicked,button_1,&QPushButton::clicked);
	mainwindow::connect(button_4,&QPushButton::clicked,[=](){
		button_4->setText("hello");	
	});
	QSlider *slider = new QSlider(Qt::Horizontal,this);
	slider->move(10,10);
	slider->setRange(10,100);
	slider->resize(100,30);
	QSpinBox *box = new QSpinBox(this);
	box->resize(60,30);
	box->move(130,10);
	box->setRange(10,100);
	
	mainwindow::connect(slider,&QSlider::valueChanged,[=](int value){
			box->setValue(value);	
		});

	mainwindow::connect(box,QOverload<int>::of(&QSpinBox::valueChanged),[=](){
		slider->setValue(box->value());	
	});
}

mainwindow::~mainwindow()
{

}

void mainwindow::myClose()
{
	this->close();	
}
