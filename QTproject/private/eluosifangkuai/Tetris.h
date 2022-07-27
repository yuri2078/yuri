#ifndef TETRIS_H
#define TETRIS_H

#include <QDialog>
#include "ui_Tetris.h"
#include "Square.h"
#include <QThread>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QMessageBox>


class Tetris : public QDialog
{
private:
    int spead;
    int row;
    int col;
    int type;
    int score;

    QString squareStyle;
    QString mapStyle;
    QString tempStyle;

    int square_width[19] = {3,3,2,2,2,3,2,3,2,4,1,4,2,4,2,4,2,4,2};
    int square_height[19] = {2,2,3,3,2,2,3,2,3,1,4,2,4,2,4,2,4,2,4};
    // 梯    1     1 1 1  1         1
    // 形  1 1 1     1    1 1     1 1 
    // 形                 1         1

    // 方  1 1
    // 块  1 1

    // 梯  1 1        1
    // 子    1 1    1 1
    // 一           1 

    // 梯    1 1     1
    // 子  1 1       1 1
    // 二              1

    // 直 1 1 1 1    1
    // 线            1
    // 直            1
    // 线            1

    // L  1               1  1      1 1 1 1        1
    // L  1 1 1 1         1               1        1
    // L                  1                        1
    // L                  1                      1 1

    // L        1         1        1 1 1 1       1 1
    // L  1 1 1 1         1        1               1
    // L                  1                        1
    // L                  1  1                     1
 
    bool is_bottom;

    Ui::Tetris *ui;
    Square ***square;

    QTimer *time_start;

public:
    Tetris(QWidget *parent = nullptr, int spead = 300);
    ~Tetris();
    void keyPressEvent(QKeyEvent * ev);
    void setMap(void);
    void gameStart(void);
    void printSquare(bool isMap);
    void checkPoint(void);
    bool checkSquare(void);
    void checkScore(void);
    void setSquareStyle(int pos_x, int pos_y, bool isMap);
    void gameOver(void);
};

#endif