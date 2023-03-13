#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMovie>
#include <QImage>
#include <QPainter>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setTextColor(QColor(4));
    connect(ui->open_file, &QAction::triggered, [this](){
        QString str = QFileDialog::getOpenFileName(this,"请打开一个文件","/home/yuri","");
        QFile file(str,this);
        file.open(QFile::ReadWrite);
        auto file_txt = file.readAll();
        ui->textEdit->setText(file_txt);
        file.close();
    });

    connect(ui->kurseni_file, &QAction::triggered, [this](){
        QString str = QFileDialog::getSaveFileName(this,"请打开一个文件","/home/yuri","");
        QFile file(str,this);
        file.open(QFile::ReadWrite);
        QString new_txt = ui->textEdit->toPlainText();
        file.write(new_txt.toUtf8());
        file.close();
    });

    auto movie = new QMovie(":/images/QQ/back.gif",QByteArray(),this);
    auto image = new QImage(":/images/QQ/back.gif");
    ui->label->resize(image->width(),image->height());
    movie->start();
    ui->label->setMovie(movie);




}
void MainWindow::paintEvent(QPaintEvent *)
{
    QImage img(":/images/login.png");
    this->resize(img.width() / 2 ,img.height() / 2);
    this->move((2560 - this->width()) / 2, (1600 - this->height()) / 2);
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), img);
}

MainWindow::~MainWindow()
{
    delete ui;
}


