#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("画图捏");
    resize(2160, 1440);

    update(); //更新画图
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *paint)
{
    QPainter painter(this); //设置 画画的设备
    QPen pen(QColor(222, 222, 222, 255)); //设置笔的颜色
    QBrush brush(Qt::blue); //设置画刷
    brush.setStyle(Qt::Dense7Pattern); //设置画刷样式

    pen.setWidth(1); //设置画笔宽度
    pen.setStyle(Qt::DashLine); //设置笔画样式

    painter.setPen(pen); //设置画笔
    painter.setBrush(brush); //设置画刷
    painter.setRenderHint(QPainter::Antialiasing); //设置抗锯齿

    painter.save(); //保存画家状态
    painter.translate(20, 0); //改变画家的位置
    painter.restore(); //回复画家状态

    painter.drawLine(QPoint(0, 0), QPoint(100, 100)); //画直线
    painter.drawEllipse(QPoint(100, 100), 100, 100); //从 100 100 的位置画一个横宽100 纵宽 100的椭圆
    painter.drawRect(200, 200, 100, 100); //从200 200 的位置画一个长100 宽100的矩形
    
    
    painter.drawText(QPoint(230, 50), "轻声密语"); //从230 50  的位置画一段话
    painter.drawPixmap(0, 0, QPixmap(":/image/1.jpg"));
}

