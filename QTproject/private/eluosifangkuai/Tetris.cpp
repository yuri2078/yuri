#include "Tetris.h"

Tetris::Tetris(QWidget *parent, int spead) : QDialog(parent)
{
    this->spead = spead;

    ui = new Ui::Tetris;
    ui->setupUi(this);

    this->row = 0;
    this->col = 0;
    this->type = 0;
    this->is_bottom = false;
    this->all_height = 0;

    this->squareStyle = "background-color:red;";
    this->mapStyle = "background-color:rgb(174, 198, 226);";
    this->tempStyle;

    setMap();

    gameStart();

    connect(ui->stop_button, &QPushButton::clicked, [this]() {
        static bool is_clicked = true;
        if(is_clicked)
        {
            is_clicked = false;
            time_start->stop();
            ui->stop_button->setText("继续");
        }
        else
        {
            is_clicked = true;
            time_start->start();
            ui->stop_button->setText("暂停");
        }
    });
    connect(ui->start_button, &QPushButton::clicked, [this]() {
        this->close();
        Tetris *tetris = new Tetris;
        tetris->show();
    });
}

void Tetris::setMap(void)
{
    square = new Square** [ ui->main_widget->height()/Square(this).height()];
    for (int i = 0; i < ui->main_widget->height()/Square(this).height();i++)
    {
        square[i] = new Square *[ui->main_widget->width()/Square(this).width()];
        for (int j = 0; j < ui->main_widget->width()/Square(this).width(); j++)
        {
            square[i][j] = new Square(this);
            square[i][j]->move(j * Square(this).width(), i * Square(this).height());
        }
    }

    next = new Square **[16];
    for (int i = 0; i < 4; i++)
    {
        next[i] = new Square *[4];
        for (int j = 0; j < 4; j++)
        {
            next[i][j] = new Square(ui->show_next);
            next[i][j]->move(90 + 50 * j, 40 + 50 * i);
            next[i][j]->setStyleSheet("background-color: rgb(98, 160, 234);");
            next[i][j]->resize(50, 50);
        }
    }
}

void Tetris::gameStart(void)
{
    printSquare(false);

    showNext(1);

    time_start = new QTimer(this);
    time_start->start(300);

    connect(time_start, &QTimer::timeout, [this]() {
        
        if(this->is_bottom)
        {
            qDebug() << "停在 底部";
            this->row = 0;
            this->col = 0;
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            this->type = qrand() % 7;
            checkScore();
            this->is_bottom = false;
        }
        printSquare(true);
        this->row = this->row + 1;
        printSquare(false);
    });
}

void Tetris::printSquare(bool isMap)
{
    
    qDebug() << "停在打印东西";
    checkPoint();
    if(checkSquare())
    {
        is_bottom = true;
        row = row - 1;
        isMap = false;
    }

    switch (type)
    {
        case 0:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row + 1, this->col + i, isMap);
            }
            setSquareStyle(this->row, this->col + 1, isMap);
            break;
        }
        case 1:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row, this->col + i, isMap);
            }
            setSquareStyle(this->row + 1, this->col + 1, isMap);
            break;
        }
        case 2:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col, isMap);
            }
            setSquareStyle(this->row + 1, this->col + 1, isMap);
            break;
        }

        case 3:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col + 1, isMap);
            }
            setSquareStyle(this->row + 1, this->col + 1, isMap);
            break;
        }
        
        case 4:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                for (int j = 0; j < square_width[type];j++)
                {
                    setSquareStyle(this->row + i, this->col + j, isMap);
                }
            }
            break;
        }

        case 5:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                for (int j = 0; j < square_height[type];j++)
                {
                    setSquareStyle(this->row + i, this->col + j + i, isMap);
                }
            }
            break;
        }

        case 6:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                for (int j = 0; j < square_width[type];j++)
                {
                    setSquareStyle(this->row + i + j, this->col + i, isMap);
                }
            }
            break;
        }

        default:
            break;
    }
}

bool Tetris::checkSquare(void)
{
    qDebug() << "停在 检查方块";

    switch (type)
    {
        case 0:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row + 1][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row][this->col + 1]->flag)
            {
                return true;
            }
            break;
        }
        case 1:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + 1][this->col + 1]->flag)
            {
                return true;
            }
            break;
        }

    

        default:
            break;
    }

    return false;
}

void Tetris::keyPressEvent(QKeyEvent *ev)
{
    if(is_bottom == false)
    {
    qDebug() << "停在 设置键盘输入";

        switch (ev->key())
        {
            case Qt::Key_J:
            {
                this->type = 2;
                break;
            }
            case Qt::Key_Down: //下
            case Qt::Key_S:
                {
                    printSquare(true);
                    this->row = this->row + 1;
                    printSquare(false);
                    break;
                }
                
            case Qt::Key_Left: //左
            case Qt::Key_A: 
                {
                    this->col = this->col - 1;
                    checkPoint();
                    if (checkSquare() == false)
                    {
                        this->col = this->col + 1;
                        printSquare(true);
                        this->col = this->col - 1;
                        printSquare(false);
                    }
                    else
                    {
                        this->col = this->col + 1;
                    }
                    
                    break;
                }
            case Qt::Key_Right: //右
            case Qt::Key_D:
                {
                    this->col = this->col + 1;
                    checkPoint();
                    if (checkSquare() == false)
                    {
                        this->col = this->col - 1;
                        printSquare(true);
                        this->col = this->col + 1;
                        printSquare(false);
                    }
                    else
                    {
                        this->col = this->col + 1;
                    }
                    
                    break;
                }
            default:
                break;
        }
    }
    
}

void Tetris::showNext(int type)
{
    switch (type)
    {
    case 1:
        {
            for (int i = 0; i < 3;i++)
            {
                next[2][1 + i]->setStyleSheet("background-color : red;");
                next[2][1 + i]->setFrameStyle(QFrame::Box | QFrame::Raised);
            }
            next[1][2]->setStyleSheet("background-color : red;");
            next[1][2]->setFrameStyle(QFrame::Box | QFrame::Raised);
            break;
        }
        
    default:
        break;
    }
    
}

void Tetris::checkPoint(void)
{
    qDebug() << "停在 检查点";
    if(this->row + square_height[type] == ui->main_widget->height()/Square(this).height())
    {
        this->is_bottom = true;
    }

    this->col + square_width[type] > ui->main_widget->width() / Square(this).width() ? this->col = this->col - 1 : 1;

    this->row < 0 ? this->row = this->row + 1 : 1;

    this->col < 0 ? this->col = this->col + 1 : 1;
}

void Tetris::checkScore(void)
{
    // time_start->stop();
    qDebug() << "停在 检查分数";
    for (int i = ui->main_widget->height() / Square(this).height() - 1; i > 0; i--)
    {
        bool map = true;
        bool score = true;
        for (int j = 0; j < ui->main_widget->width() / Square(this).width(); j++)
        {
            if(square[i][j]->flag == false)
            {
                score = false;
                break;
            }
            else
            {
                map = false;
            }
        }

        if(map)
        {
            break;
        }

        if(score)
        {
            for (int k = i; k > 0;k--)
            {
                for (int j = 0; j < ui->main_widget->width() / Square(this).width(); j++)
                {
                    square[k][j]->setStyleSheet(square[k - 1][j]->styleSheet());
                    square[k][j]->flag = square[k - 1][j]->flag;
                }
            }
            i++;
        }
    }
    
    // time_start->start();
}


void Tetris::setSquareStyle(int pos_x, int pos_y, bool isMap)
{
    qDebug() << "停在 设置样式";
    tempStyle = isMap ? mapStyle : squareStyle;

    square[pos_x][pos_y]->setStyleSheet(tempStyle);
    square[pos_x][pos_y]->flag = is_bottom;

    qDebug() << "样式结束";

}

Tetris::~Tetris()
{
    delete ui;
}
