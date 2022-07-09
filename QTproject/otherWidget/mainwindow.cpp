#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qlabel.h>
#include <qpixmap.h>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->button_1, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->button_2, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->button_3, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    QLabel *qlabel_1 = new QLabel("你好", this);
    qlabel_1->move(100, 100);

    QLabel *qlabel_2 = new QLabel("拆入图片",this);
    QLabel *qlabel_3 = new QLabel("拆入gif",this);
    qlabel_2->resize(100, 100);
    qlabel_2->setPixmap(QPixmap(":/imgaes/2.jpg"));

    QMovie *movie_1 = new QMovie(":/imgaes/1.gif");
    
    qlabel_3->setMovie(movie_1); 
    movie_1->start(); //开始播放
    qlabel_3->move(300, 300);
    qlabel_3->resize(200, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

