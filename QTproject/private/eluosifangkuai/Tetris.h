#ifndef TETRIS_H
#define TETRIS_H

#include <QDialog>
#include "ui_Tetris.h"
#include "Square.h"
#include <QThread>


class Tetris : public QDialog
{
private:
    int spead;

    Ui::Tetris *ui;
    Square ***square;

public:
    Tetris(QWidget *parent = nullptr, int spead = 300);
    ~Tetris();
    void setMap(void);
};

#endif