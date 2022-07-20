#include "Snake.h"
#include "snake_label.h"
#include <QTimer>

Snake::Snake(QWidget *parent) : QDialog(parent)
{
    //ui文件初始化
    ui = new Ui::Snake;
    ui->setupUi(this);

    resize(800, 800);

    this->snake_1 = new snake_label(this, 10, 10);
    this->snake_2 = new snake_label(this, 60, 10, snake_1);
    this->snake_3 = new snake_label(this, 110, 10, snake_2);
    this->snake_4 = new snake_label(this, 160, 10, snake_3);
    this->snake_5 = new snake_label(this, 210, 10, snake_4);
    this->snake_6 = new snake_label(this, 260, 10, snake_5);

    this->head = snake_1;
    this->tial = snake_6;

    this->move_x = snake_1->width();
    this->move_y = 0;

    QTimer *time_1 = new QTimer(this);
    time_1->start(300);
    connect(time_1, &QTimer::timeout, [this]()
    {
        head->move(tial->x() + move_x, tial->y() + move_y);
        tial->back_snake = head;
        head->front_snake = tial;
        tial = head;
        head = head->back_snake;
    });
}

Snake::~Snake()
{
    delete ui;
}

void Snake::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_Down:
        move_x = 0;
        move_y = snake_1->height();
        break;
    case Qt::Key_Up:
        move_x = 0;
        move_y = - snake_1->height();
        break;
    case Qt::Key_Left:
        move_x = - snake_1->width();
        move_y = 0;
        break;
    case Qt::Key_Right:
        move_x = snake_1->width();
        move_y = 0;
        break;
    default:
        break;
    }
    
}