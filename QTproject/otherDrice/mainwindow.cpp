#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //pixmap 会为各平台做优化
    QPixmap pix(600, 600); //创建一个 600 600 的图
    pix.fill(Qt::white); //设置填充是白色
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::green)); //设置颜色
    painter.drawEllipse(QPoint(300, 300), 200, 200); //画一个圆
    pix.save("E:/vscode/画图.png"); //设置保存

    QPicture pic;
    QPainter temp;
    temp.begin(&pic); //从这里开始画画
    temp.setPen(QPen(QColor(qRgb(222, 33, 100)))); //设置画笔颜色
    temp.drawEllipse(QPoint(100, 100), 100, 100); //先画一个圆
    temp.end(); //结束画画
    pic.save("E:/vscode/pic.txt"); //保存文件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    //优势，可以修改像素点
    QImage img(1920, 1080, QImage::Format_RGB32); //设置颜色格式为rgb
    img.load(":/image/(15).jpg");
    QPainter painter(&img);
    for (int i = 0; i < 100;i++)
    {
        for (int j = 0; j < 100;j++)
        {
            img.setPixel(QPoint(i, j), qRgb(222,33,0)); //修改像素点
        }
    }
    painter.drawImage(QPoint(0, 0), img);
    img.save("E:/vscode/img.png");

    QPicture pic; //加载记录
    QPainter temp(this);
    pic.load("E:/vscode/pic.txt");
    temp.drawPicture(QPoint(0, 0), pic);
}

