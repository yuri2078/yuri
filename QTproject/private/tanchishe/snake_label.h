#ifndef SNAKELABEL_H
#define SNAKELABEL_H

#include <QLabel>

class snake_label : public QLabel
{

public:
    snake_label *front_snake;
    snake_label *back_snake;

public:
    snake_label(QWidget *parent, int pos_x, int pos_y, snake_label *front_snake = nullptr, snake_label *back_snake = nullptr);

    ~snake_label();
};



#endif