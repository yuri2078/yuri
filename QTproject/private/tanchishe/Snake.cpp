#include "Snake.h"


Snake::Snake(QWidget *parent , int spead) : QDialog(parent)
{
    //界面ui初始化

    ui = new Ui::Snake;
    ui->setupUi(this);
    resize(1000, 800);

    key_onlick = false;

    this->spead = spead;

    setFocusPolicy(Qt::StrongFocus); //设置控件焦点，防止接收不到方向键输入

    //设置默认移动方向 向右移动
    move_x = snake_label(this).width();
    move_y = 0;
    
    //初始化食物
    have_food = true;
    score = 0;
    food = new snake_label(this, 400, 400);
    food ->setStyleSheet("background-color: rgb(255, 100, 137);");

    //初始化蛇身体
    this->head = new snake_label(this, 0, 0);
    this->snake.push_back(head);
    for (int i = 0; i < 6; i++)
    {
        this->snake.push_back(new snake_label(this, snake.back()->x() + snake_label(this).width(), snake.back()->y(),snake.back()));
    }


    //设置定时器
    time_gameStart = new QTimer(this);
    time_gameStart->start(this->spead);

    //游戏开始 定时器
    connect(time_gameStart, &QTimer::timeout, [this]()
    {
        //保存需要移动的蛇的新位置
        int pos_x = snake.back()->x() + move_x;
        int pos_y = snake.back()->y() + move_y;

        //判断游戏是否结束
        if(gameOver(pos_x, pos_y))
        {
            //暂停定时器
            time_gameStart->stop();

            //弹出窗口
            gameOver_box();

        }

        //移动蛇蛇
        if(this->key_onlick == false)
        {
            moveSnake(pos_x, pos_y);
        }
        else
        {
            this->key_onlick = false;
        }

        

        //初始化食物
        if(have_food == false)
        {
            qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
            food->move((qrand() % this->ui->widget->width() / snake_label(this).width()) * snake_label(this).width(), (qrand() % this->ui->widget->height() / snake_label(this).height()) * snake_label(this).height());
            for (int i = 0; i < snake.length();i++)
            {
                if(snake[i]->x() == food->x() && snake[i]->y() == food->y())
                {
                    food->move((qrand() % this->ui->widget->width() / snake_label(this).width()) * snake_label(this).width(), (qrand() % this->ui->widget->height() / snake_label(this).height()) * snake_label(this).height());
                    i = -1;
                }
            }
                
            have_food = true;
        }
    });

    //暂停
    connect(ui->stop_button, &QPushButton::clicked, [this](){
            static bool btn = true;
            if(btn)
            {
                time_gameStart->stop();
                ui->stop_button->setText("继续");
                btn = false;
            }
            else
            {
                time_gameStart->start();
                ui->stop_button->setText("暂停");
                btn = true;
            }
            
        });

    //结束
    connect(ui->over_button, &QPushButton::clicked, [this](){
                this->close();
            });
}

//控制蛇移动方向
void Snake::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_Down: //下
    case Qt::Key_S:
        move_x = 0;
        move_y = snake.back()->height();
        key_onlick = true;
        moveSnake(snake.back()->x() + move_x, snake.back()->y() + move_y);
        break;
    case Qt::Key_Up: //上
    case Qt::Key_W:
        move_x = 0;
        move_y = -snake.back()->height();
        key_onlick = true;
        moveSnake(snake.back()->x() + move_x, snake.back()->y() + move_y);
        break;
    case Qt::Key_Left: //左
    case Qt::Key_A: 
        move_x = -snake.back()->width();
        move_y = 0;
        key_onlick = true;
        moveSnake(snake.back()->x() + move_x, snake.back()->y() + move_y);
        break;
    case Qt::Key_Right: //右
    case Qt::Key_D:
        move_x = snake.back()->width();
        move_y = 0;
        key_onlick = true;
        moveSnake(snake.back()->x() + move_x, snake.back()->y() + move_y);
        break;
    default:
        break;
    }
    
}

//判断游戏是否结束
int Snake::gameOver(int pos_x, int pos_y)
{
    int over = 0; //初始化结果

    //判断是否出届
    if (pos_x + snake_label(this).width() > this->ui->widget->width() || pos_x < 0 || pos_y + snake_label(this).height()> this->ui->widget->height() || pos_y < 0)
    {
        time_gameStart->stop();
        over = 1;
    }

    for (int i = 0; i < snake.length();i++)
    {
        //判断是不是碰到自己的身体
        if(snake[i]->x() == pos_x && snake[i]->y() == pos_y)
        {
            qDebug()  << " i  " << i << snake[i]->pos();
            qDebug()  << " -- " << snake.back()->pos();
            over = 2;
            break;
        }
    }

    return over; //返回游戏结束代码
}


void Snake::getScore(int pos_x, int pos_y)
{
    //判断是不是吃到了食物
    if(pos_x == food->x() && pos_y == food->y())
    {
        snake_label *temp = new snake_label(this, snake.front()->x(), snake.front()->y());
        temp->back_snake = snake.front();
        snake.front()->front_snake = temp;
        snake.push_front(temp);
        temp->show();
        have_food = false;

        score++;
        this->ui->score->setText(QString::number(score));
    }
}


void Snake::moveSnake(int pos_x, int pos_y)
{
    //将蛇头移动到新的地方
    snake.front()->move(pos_x,pos_y); 
    //设置蛇尾的下一条蛇
    snake.back()->back_snake = snake.front();
    //设置蛇头的上一条蛇
    snake.front()->front_snake = snake.back();
    //将蛇尾改成新的蛇头
    snake.back() = snake.front();
    //将蛇头改称原来的第二条蛇
    snake.front() = snake.front()->back_snake;

    //判断是不是吃到了食物
    getScore(pos_x, pos_y);
}

void Snake::gameOver_box()
{
    QPushButton *ok = new QPushButton("确定", this);
    QPushButton *cancle = new QPushButton("不行，再来一把!", this);
    QMessageBox *over = new QMessageBox;

    over->setText("这么菜就别玩了!");
    over->setWindowTitle("游戏已经结束捏！");

    //添加按钮
    over->addButton(ok,QMessageBox::ButtonRole::YesRole);
    over->addButton(cancle,QMessageBox::ButtonRole::NoRole);
    over->show();

    connect(ok, &QPushButton::clicked, [this]() {
        qDebug() << "选择ok";
        this->close();
    });

    connect(cancle, &QPushButton::clicked, [this]() {
        qDebug() << "选择取消";
        this->close();
        Snake *newGame = new Snake(nullptr,this->spead);
        newGame->show();
    });
}

Snake::~Snake()
{
    
}