#ifndef SNAKE_H
#define SNAKE_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <QAbstractButton>

#include "snake_label.h"
#include "ui_Snake.h"

class Snake  :public QDialog
{
private:
    QVector<snake_label *> snake;

    snake_label *head;
    snake_label *food;

    QTimer *time_gameStart;

    bool have_food;
    bool key_onlick;

    int move_x;
    int move_y;
    int score;
    int spead;

    Ui::Snake *ui;

public:
    Snake(QWidget *parent = nullptr, int spead = 300);
    ~Snake();

    void keyPressEvent(QKeyEvent *ev); //键盘接收
    int gameOver(int pos_x, int pos_y); //判断游戏是否结束
    void getScore(int pos_x, int pos_y); //判断是否吃到食物（分数）
    void moveSnake(int pos_x, int pos_y); //移动蛇蛇
    void gameOver_box(); //设置游戏结束弹出窗口

public slots:
    
};

#endif