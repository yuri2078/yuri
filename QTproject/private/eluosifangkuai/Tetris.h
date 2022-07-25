#ifndef TETRIS_H
#define TETRIS_H

#include <QDialog>
#include "ui_Tetris.h"
#include "Square.h"
#include <QThread>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>


class Tetris : public QDialog
{
private:
    int spead;
    int row;
    int col;
    int type;
    int square_width[10];
    int square_height[10];
    int all_height;

    bool is_bottom;
    bool is_touch;

    Ui::Tetris *ui;
    Square ***square;
    Square ***next;

public:
    Tetris(QWidget *parent = nullptr, int spead = 300);
    ~Tetris();
    void keyPressEvent(QKeyEvent * ev);
    void setMap(void);
    void gameStart(void);
    void printSquare(int type, bool isMap);
    void checkPoint(void);
    bool checkSquare(void);
    void showNext(int type);
};

#endif