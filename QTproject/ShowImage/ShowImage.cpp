#include "ShowImage.h"
#include <QPainter>
#include <QImage>
#include <QDebug>


ShowImage::ShowImage(QWidget *parent) : QDialog(parent)
{
    ui = new Ui::ShowImage;
    ui->setupUi(this);

    this->img_index = 1;

    connect(ui->before, &QPushButton::clicked, this, &ShowImage::on_before_clicked);
    connect(ui->next, &QPushButton::clicked, this, &ShowImage::on_next_clicked);
}

ShowImage::~ShowImage()
{
    delete ui;
}

void ShowImage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect = ui->frame->frameRect();
    rect.translate(ui->frame->pos());

    QImage img(":/" + QString::number(img_index) + ".jpg");


    this->resize(img.size());
    ui->frame->resize(img.size());

    painter.drawImage(rect, img);
    qDebug() << img.size() << this->img_index;
}
void ShowImage::on_before_clicked()
{
    qDebug() << "这是前一张按钮";
    if (--img_index == 0)
        img_index = 4;
    update();
}

void ShowImage::on_next_clicked()
{
    qDebug() << "这是后一张按钮" << this->img_index; 
    if (++this->img_index == 5)
        this->img_index = 1;
    update();
}
