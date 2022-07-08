#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QImage>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QImage img(":/images/fly.png");
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), img);
}

