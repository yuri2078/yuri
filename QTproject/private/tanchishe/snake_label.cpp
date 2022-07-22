#include "snake_label.h"

snake_label::snake_label(QWidget *parent, int pos_x, int pos_y,  snake_label *front_snake, snake_label *back_snake) : QLabel(parent)
{

    this->front_snake = front_snake;
    if(front_snake != nullptr)
    {
        front_snake->back_snake = this;
    }
    
    this->back_snake = back_snake;
    // this->label = new QLabel(parent);
    setStyleSheet("background-color: rgb(87, 227, 137);");
    resize(50, 50);
    move(pos_x, pos_y);
    setFrameStyle(QFrame::Box | QFrame::Raised);
}

snake_label::snake_label(QWidget *parent) : QLabel(parent)
{

    setStyleSheet("background-color: rgb(87, 227, 137);");
    resize(50, 50);
    setFrameStyle(QFrame::Box | QFrame::Raised);
    close();
}

snake_label::~snake_label()
{
    
}