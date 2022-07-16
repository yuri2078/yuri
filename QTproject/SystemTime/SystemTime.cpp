#include "SystemTime.h"

SystemTime::SystemTime(QWidget *parent) : QDialog(parent)
{
	//设置窗口属性
	this->setWindowTitle("时间");
	this->resize(460,300);
	
	//初始化各控件
	
	showTime = new QLabel("快来获取时间吧",this);
	getTime = new QPushButton("当前系统时间",this);
	layout = new QVBoxLayout(this);
	
	//设置控件属性

	showTime->setAlignment(Qt::AlignHCenter| Qt::AlignVCenter);//设置垂直水平剧中
	showTime->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	showTime->setFont(QFont("微软雅黑",24));

	//设置垂直布局
	layout->addWidget(showTime);
	layout->addWidget(getTime);
	this->setLayout(layout);	
	
	//连接按钮
	
	SystemTime::connect(getTime,&QPushButton::clicked,[=](){
			QTime time =  QTime::currentTime(); //获取时间
			QString str = time.toString("hh:mm:ss"); //格式化输出
			showTime->setText(str);	
		});

}

SystemTime::~SystemTime()
{

}

