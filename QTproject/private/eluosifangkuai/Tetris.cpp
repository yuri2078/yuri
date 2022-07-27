#include "Tetris.h"

Tetris::Tetris(QWidget *parent, int spead) : QDialog(parent)
{
    this->spead = spead;

    this->setWindowTitle("俄罗斯方块");

    ui = new Ui::Tetris;
    ui->setupUi(this);

    this->row = 0;
    this->col = 0;
    this->type = 0;
    this->is_bottom = false;
    this->score = 0;

    this->squareStyle = "background-color:red;";
    this->mapStyle = "background-color:rgb(174, 198, 226);";

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
}

void Tetris::gameStart(void)
{
    printSquare(false);

    time_start = new QTimer(this);
    time_start->start(spead);

    connect(time_start, &QTimer::timeout, [this]() {
        if(this->is_bottom)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            this->type = qrand()% 19;
            this->row = 0;
            this->col = 0;
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
    this->type = this->type % 19;
    checkPoint();
    if(checkSquare())
    {
        is_bottom = true;
        row = row - 1;
        isMap = false;
    }
    gameOver();

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
            setSquareStyle(this->row + 1, this->col, isMap);
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
                    setSquareStyle(this->row + i + j, this->col + 1 - i, isMap);
                }
            }
            break;
        }

        case 7:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                for (int j = 0; j < square_height[type];j++)
                {
                    setSquareStyle(this->row + i , this->col + j + 1 - i, isMap);
                }
            }
            break;
        }

        case 8:
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

        case 9:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row, this->col + i, isMap);
            }

            break;
        }

        case 10:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col, isMap);
            }
            
            break;
        }

        case 11:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row + 1, this->col + i, isMap);
            }
            setSquareStyle(this->row, this->col, isMap);
            break;
        }

        case 12:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col, isMap);
            }
            setSquareStyle(this->row, this->col + 1, isMap);
            break;
        }

        case 13:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row, this->col + i, isMap);
            }
            setSquareStyle(this->row + 1, this->col + square_width[type] - 1, isMap);
            break;
        }

        case 14:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col + 1, isMap);
            }
            setSquareStyle(this->row + square_height[type] - 1, this->col, isMap);
            break;
        }

        case 15:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row + 1, this->col + i, isMap);
            }
            setSquareStyle(this->row, this->col + square_width[type] - 1, isMap);
            break;
        }

        case 16:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col, isMap);
            }
            setSquareStyle(this->row + square_height[type] - 1, this->col + 1, isMap);
            break;
        }

        case 17:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                setSquareStyle(this->row, this->col + i, isMap);
            }
            setSquareStyle(this->row + 1, this->col, isMap);
            break;
        }

        case 18:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                setSquareStyle(this->row + i, this->col + 1, isMap);
            }
            setSquareStyle(this->row , this->col, isMap);
            break;
        }

        default:
            break;
    }
}

bool Tetris::checkSquare(void)
{
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

        case 2:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col]->flag)
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

        case 3:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col + 1]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + 1][this->col]->flag)
            {
                return true;
            }
            break;
        }
        
        case 4:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                for (int j = 0; j < square_width[type];j++)
                {
                    if(square[this->row + i][this->col + j]->flag)
                    {
                        return true;
                    }
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
                    if(square[this->row + i][this->col + i + j]->flag)
                    {
                        return true;
                    }
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
                    if(square[this->row + i + j][this->col + 1 - i]->flag)
                    {
                        return true;
                    }
                }
            }
            break;
        }

        case 7:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                for (int j = 0; j < square_height[type];j++)
                {
                    if(square[this->row + i][this->col + j + 1 - i]->flag)
                    {
                        return true;
                    }
                }
            }
            break;
        }

        case 8:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                for (int j = 0; j < square_width[type];j++)
                {
                    if(square[this->row + i + j][this->col + i]->flag)
                    {
                        return true;
                    }
                }
            }
            break;
        }

        case 9:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row][this->col + i]->flag)
                {
                    return true;
                }
            }

            break;
        }

        case 10:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col]->flag)
                {
                    return true;
                }
            }
            
            break;
        }

        case 11:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row + 1][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row][this->col]->flag)
            {
                return true;
            }
            break;
        }

        case 12:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col]->flag)
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

        case 13:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + 1][this->col + square_width[type] - 1]->flag)
            {
                return true;
            }
            break;
        }

        case 14:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col + 1]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + square_height[type] - 1][this->col]->flag)
            {
                return true;
            }
            break;
        }

        case 15:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row + 1][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row][this->col + square_width[type] - 1]->flag)
            {
                return true;
            }
            break;
        }

        case 16:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + square_height[type] - 1][this->col + 1]->flag)
            {
                return true;
            }
            break;
        }

        case 17:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                if(square[this->row][this->col + i]->flag)
                {
                    return true;
                }
            }
            if(square[this->row + 1][this->col]->flag)
            {
                return true;
            }
            break;
        }

        case 18:
        {
            for (int i = 0; i < square_height[type];i++)
            {
                if(square[this->row + i][this->col + 1]->flag)
                {
                    return true;
                }
            }
            if(square[this->row][this->col]->flag)
            {
                return true;
            }
            break;
        }
    

        default:
            break;;
    }

    return false;
}

void Tetris::keyPressEvent(QKeyEvent *ev)
{
    if(is_bottom == false)
    {
        switch (ev->key())
        {
            case Qt::Key_J:
            {
                this->type = 0;
                break;
            }

            case Qt::Key_W:
            {
                printSquare(true);
                switch (type)
                {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    {
                        type = type + 1;
                        type = type % 4;
                        break;
                    }
                    case 5:
                    case 6:
                    {
                        type = type + 1;
                        if(type == 7)
                        {
                            type = 5;
                        }
                        break;
                    }
                    case 7:
                    case 8:
                    {
                        type = type + 1;
                        if(type == 9)
                        {
                            type = 7;
                        }
                        break;
                    }

                    case 9:
                    case 10:
                    {
                        type = type + 1;
                        if(type == 11)
                        {
                            type = 9;
                        }
                        break;
                    }
                    
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    {
                        type = type + 1;
                        if (type == 15)
                        {
                            type = 11;
                        }
                        break;
                    }
                    case 15:
                    case 16:
                    case 17:
                    case 18:
                    {
                        type = type + 1;
                        if (type == 19)
                        {
                            type = 15;
                        }
                        break;
                    }
                    default:
                        break;
                }
                printSquare(false);
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
                    if (checkSquare() == false && is_bottom == false)
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
                    if (checkSquare() == false && is_bottom == false)
                    {
                        this->col = this->col - 1;
                        printSquare(true);
                        this->col = this->col + 1;
                        printSquare(false);
                    }
                    else
                    {
                        this->col = this->col - 1;
                    }
                    
                    break;
                }
            default:
                break;
        }
    }
    
}


void Tetris::checkPoint(void)
{
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
            this->score = this->score + 1;
            ui->score_label->setText("得分 :  " + QString::number(this->score) + " 分");
            for (int k = i; k > 0; k--)
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
    tempStyle = isMap ? mapStyle : squareStyle;
    square[pos_x][pos_y]->setStyleSheet(tempStyle);
    square[pos_x][pos_y]->flag = is_bottom;
}


void Tetris::gameOver(void)
{

    if(row < 0)
    {
        QMessageBox::warning(this, "游戏结束", "game is over!", QMessageBox::Ok, QMessageBox::Cancel);
        row = 0;
        col = 0;
        this->time_start->stop();
        this->is_bottom = true;
    }
}

Tetris::~Tetris()
{
    delete ui;
}
