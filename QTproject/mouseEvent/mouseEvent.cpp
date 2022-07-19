#include "mouseEvent.h"
#include <QDebug>

mouseEvent::mouseEvent(QWidget *parent) : QDialog(parent)
{
    resize(800, 800);
    square = new QWidget(this);
    square->resize(80, 80);
    square->setStyleSheet("background-color: rgb(87, 227, 137)");
    square->move(100, 100);
    click_pos = new QPoint(100, 100);
    widget_pos = new QPoint(100, 100);

    qDebug() << square->pos();
    qDebug() << square->rect();

    is_left = false;
}

mouseEvent::~mouseEvent()
{

}

void mouseEvent::mouseMoveEvent(QMouseEvent *ev)
{
    if(is_left)
    {
        QPoint temp = ev->pos() - *click_pos;
        square->move(*widget_pos + temp);
    }
    
}

void mouseEvent::mousePressEvent(QMouseEvent *ev)
{
    *click_pos = ev->pos();
    *widget_pos = square->pos();
    QRect qrect = square->rect();
    qrect.translate(square->pos());
    qDebug() << qrect;
    if (qrect.contains(ev->pos()))
    {
        is_left = true;
        qDebug() << square->rect().contains(ev->pos());
    }
    else
    {
        is_left = false;
    }

    
}
