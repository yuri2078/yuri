#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *bot;
    bot = new QPushButton;
    bot->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

