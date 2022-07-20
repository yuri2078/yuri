#ifndef SNAKE_H
#define SNAKE_H

#include <QDialog>
#include "ui_Snake.h"
#include <QLabel>
#include <QPushButton>
#include "snake_label.h"
#include <QKeyEvent>


class Snake  :public QDialog
{
private:
    Ui::Snake *ui;
    snake_label *snake_1;
    snake_label *snake_2;
    snake_label *snake_3;
    snake_label *snake_4;
    snake_label *snake_5;
    snake_label *snake_6;

    snake_label *head;
    
    snake_label *tial;

    int move_x;
    int move_y;

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
    void keyPressEvent(QKeyEvent *ev);

public slots:
    void snakeMove(void);
};

#endif