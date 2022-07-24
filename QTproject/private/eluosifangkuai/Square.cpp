#include "Square.h"

Square::Square(QWidget *parent) : QLabel(parent)
{

    this->setFrameStyle(QFrame::Box | QFrame::Raised);
    this->resize(25, 25);
    setStyleSheet("background-color : rgb(174, 198, 226);");

    show();
}

Square::Square(QWidget *parent , int flag, int pos_x, int pos_y) : QLabel(parent)
{

    this->flag = flag;
    this->pos_x = pos_x;
    this->pos_y = pos_y;

    switch (flag)
    {
    case 1:
    {
        for (int i = 0; i < 3;i++)
        {
            Square *temp = new Square(parent);
            temp->setStyleSheet("background-color : rgb(12, 100, 126);");
            temp->move(i * 25 + pos_x, 25 + pos_y);
            temp->show();
        }
        Square *temp = new Square(parent);
        temp->setStyleSheet("background-color : rgb(12, 100, 126);");
        temp->move(25 + pos_x, pos_y);
        temp->show();
    }
    break;
    
    default:
        break;
    }

    
    close();
}

void Square::printSquare(void)
{
    if(flag == 1)
    {

    }
}

Square::~Square()
{

}


