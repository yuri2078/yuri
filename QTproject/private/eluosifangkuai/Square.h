#ifndef SQUARE_H
#define SQUARE_H

#include <QLabel>

class Square : public QLabel
{
private:
    

public:

    bool flag;
    Square(QWidget *parent);
    void printSquare(void);
    ~Square();
};


#endif