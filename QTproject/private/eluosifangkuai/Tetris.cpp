#include "Tetris.h"

Tetris::Tetris(QWidget *parent, int spead) : QDialog(parent)
{
    this->spead = spead;

    ui = new Ui::Tetris;
    ui->setupUi(this);

    this->row = 0;
    this->col = 0;
    this->type = 1;
    this->is_bottom = false;
    this->is_touch = false;
    this->all_height = 0;

    square_width[1] = 3;
    square_height[1] = 2;

    setMap();
    gameStart();
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
    printSquare(this->type,false);

    showNext(1);

    QTimer *time_start = new QTimer(this);
    time_start->start(700);

    connect(time_start, &QTimer::timeout, [this]() {
        
        if(this->is_bottom)
        {
            this->row = 0;
            this->col = 0;
            this->is_bottom = false;
            this->all_height = this->square_height[this->type];
        }
        printSquare(this->type, true);
        this->row = this->row + 1;
        printSquare(this->type, false);
    });
}

void Tetris::printSquare(int type, bool isMap)
{
    QString squareStyle = "background-color:red;";
    QString mapStyle = "background-color:rgb(174, 198, 226);";
    QString tempStyle;
    
    tempStyle = isMap ? mapStyle : squareStyle;

    checkPoint();
    checkSquare();
    switch (type)
    {
    case 1:
        {
            for (int i = 0; i < square_width[type];i++)
            {
                square[this->row + 1][this->col + i]->setStyleSheet(tempStyle);
                square[this->row + 1][this->col + i]->flag = is_bottom;
            }
            square[this->row][this->col + 1]->setStyleSheet(tempStyle);
            square[this->row][this->col + 1]->flag = is_bottom;
            break;
        }
        
    default:
        break;
    }
}

bool Tetris::checkSquare(void)
{
    for (int i = 0; i < square_height[type];i++)
    {
        for (int j = 0; j < square_width[type];j++)
        {
            if(square[row + i][col+j]->flag)
            {
                is_touch = true;
                is_bottom = true;
                qDebug() << "发生碰撞";
                this->row = this->row - 1;
                qDebug() << "打印测试方格数量" << i << " -- " << j ;
                return true;
            }
            
        }
    }
    
    return false;
}

void Tetris::keyPressEvent(QKeyEvent *ev)
{
    if(is_bottom == false)
    {
        switch (ev->key())
        {
        case Qt::Key_Down: //下
        case Qt::Key_S:
            {
                printSquare(this->type, true);
                this->row = this->row + 1;
                printSquare(this->type, false);
                break;
            }
            
        case Qt::Key_Left: //左
        case Qt::Key_A: 
            {
                printSquare(this->type, true);
                this->col = this->col - 1;
                printSquare(this->type, false);
                break;
            }
        case Qt::Key_Right: //右
        case Qt::Key_D:
            {
                printSquare(this->type, true);
                this->col = this->col + 1;
                printSquare(this->type, false);
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
    if(this->row + 2 >= ui->main_widget->height()/Square(this).height())
    {
        this->is_bottom = true;
    }

    this->col + 3 > ui->main_widget->width() / Square(this).width() ? this->col = this->col - 1 : 1;

    this->row < 0 ? this->row = this->row + 1 : 1;

    this->col < 0 ? this->col = this->col + 1 : 1;
}

Tetris::~Tetris()
{
    delete ui;
}
