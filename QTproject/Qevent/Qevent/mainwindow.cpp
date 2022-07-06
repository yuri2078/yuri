#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *button_1 = new QPushButton("清空日志", this);
    connect(button_1,&QPushButton::clicked,[](){
        
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

