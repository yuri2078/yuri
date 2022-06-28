#include "widget.h"
#include "./ui_widget.h"
#include <qpushbutton.h>

Widget::Widget(QWidget *parent) : QWidget(parent) //初始化窗口类
{
    ui = new Ui::Widget; //
    ui->setupUi(this);

    //按钮
    QPushButton * button_1;
    button_1 = new QPushButton;
    button_1->setText("按钮"); //设置按钮文本
    button_1->setParent(this); //设置依赖于哪个窗口
    button_1->show(); //在顶点显示一个按钮，默认新开一个窗口

    QPushButton * button_2 = new QPushButton("点击关闭窗口", this); //直接指定依附的窗口和文字 并且直接显示
    button_2->move(230, 230); //移动按钮
    resize(800, 800); //刷新窗口
    setWindowTitle("第一个窗口!"); //设置窗口标题
    setFixedSize(500, 500); //固定窗口大小

    connect(button_2, &QPushButton::clicked, this, &Widget::close); //点击关闭窗口
}


Widget::~Widget()
{
    delete ui;
}

