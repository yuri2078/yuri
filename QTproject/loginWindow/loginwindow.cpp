#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include <qpushbutton.h>

loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

loginWindow::~loginWindow()
{
    delete ui;
}

