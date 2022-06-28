#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) //初始化窗口类
{
    ui = new Ui::Widget; //
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

