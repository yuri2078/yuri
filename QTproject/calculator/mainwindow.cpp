#include "mainwindow.h"
#include <QPushButton>
#include <QDoubleValidator>
#include <QHBoxLayout>
#include <QDebug>
mainwindow::mainwindow(QWidget *parent) : QDialog(parent)
{
	setWindowTitle("计算器");
	resize(800,200);

	QLineEdit *left = new QLineEdit(this);
	left->setAlignment(Qt::AlignRight);
	left->resize(200,40);
	
	QLabel *plus = new QLabel("+",this);	
	plus->resize(40,40);
	
	QLineEdit *right = new QLineEdit(this);
	right->setAlignment(Qt::AlignRight);
	right->resize(200,40);
	
	QPushButton *equal = new QPushButton("=",this);
	equal->setEnabled(false);
	equal->resize(100,40);
	
	QLineEdit *result = new QLineEdit("0",this);
	result->setAlignment(Qt::AlignRight);
	result->setReadOnly(true);
	result->resize(200,40);
	
	//创建验证器 需要包含gui模块
	//必须使用new操作符，不然生存周期结束后，就不起作用了
	QDoubleValidator *validatorLeft = new QDoubleValidator(this);
	QDoubleValidator *validatorRight = new QDoubleValidator(this);

	//设置验证器
	left->setValidator(validatorLeft);
	right->setValidator(validatorRight);

	//创建布局器
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(left); //将控件添加到水平布局器中
	layout->addWidget(plus);
	layout->addWidget(right);
	layout->addWidget(equal);
	layout->addWidget(result);
	this->setLayout(layout); //设置布局器
	
	//别的连接方式，这个方式必须两边都使用这种东西
	//	mainwindow::connect(left,SIGNAL(textChanged(QString)),this,SLOT(resultCheck(void)));
	mainwindow::connect(left,&QLineEdit::textChanged,[=](){
			bool double_left,double_right;
			left->text().toDouble(&double_left);	
			right->text().toDouble(&double_right);
			if(double_left && double_right)
			{
				equal->setEnabled(true);
			}
			else
			{
				equal->setEnabled(false);
			}

			qDebug() << "left -" << double_left << "  right -" << double_right;	
		});

	mainwindow::connect(right,&QLineEdit::textChanged,[=](){
			bool double_left,double_right;
			left->text().toDouble(&double_left);	
			right->text().toDouble(&double_right);
			if(double_left && double_right)
			{
				equal->setEnabled(true);
			}	
			else
			{
				equal->setEnabled(false);
			}

			qDebug() << "left -" << double_left << "  right -" << double_right;	
		});

	
	mainwindow::connect(equal,&QPushButton::clicked,[=](){
			QString rel;
		        double left_rel,right_rel;
			left_rel = left->text().toDouble();	
			right_rel = right->text().toDouble();
			rel = rel.number(left_rel + right_rel);
			result->setText(rel);
		});
}

mainwindow::~mainwindow()
{

}
