#ifndef SQUARE_H
#define SQUARE_H

#include <QLabel>

class Square : public QLabel
{
private:
    int flag;
    int pos_x;
    int pos_y;

public:
    Square(QWidget *parent);
    Square(QWidget *parent, int flag, int pos_x, int pos_y);
    void printSquare(void);
    ~Square();
};


#endif