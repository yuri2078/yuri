#include "Square.h"

Square::Square(QWidget *parent) : QLabel(parent)
{
    this->flag = false; //表示这是地图

    this->setFrameStyle(QFrame::Box | QFrame::Raised);
    this->resize(25, 25);
    setStyleSheet("background-color : rgb(174, 198, 226);");
    show();
}


Square::~Square()
{

}


