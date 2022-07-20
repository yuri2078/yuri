#include "Keyboard.h"


Keyboard::Keyboard(QWidget *parent) : QDialog(parent)
{
    this->resize(800, 800);
    label = new QLabel("", this);
    label->resize(50, 50);
    label->setStyleSheet("background-color: rgba(222,33,55,0.6);border-radius: 25px;");
}

Keyboard::~Keyboard()
{

}

void Keyboard::keyPressEvent(QKeyEvent *ev)
{
    qDebug() << ev->key();
    switch (ev->key())
    {
    case Qt::Key_A:
    case Qt::Key_Left:
        this->label->move(label->x() - 10, label->y());
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        this->label->move(label->x(), label->y() + 10);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        this->label->move(label->x() + 10, label->y());
        break;
    case Qt::Key_W:
    case Qt::Key_Up:
        this->label->move(label->x(), label->y() - 10);
        break;
    
    default:
        break;
    }
    
}