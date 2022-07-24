#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "ui_Welcome.h"
#include <QPainter>
#include <QImage>
#include <QDesktopWidget>
#include "Tetris.h"
#include <QThread>

class Welcome : public QDialog
{

    Q_OBJECT
private:
    Ui::Welcome *ui;
    Tetris *tetris;

public:
    Welcome(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *ev);
    ~Welcome();
};


#endif