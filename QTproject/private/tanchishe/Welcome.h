#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "ui_Welcome.h"
#include "Snake.h"
#include <QPainter>
#include <QImage>
#include <QDesktopWidget>

class Welcome : public QDialog
{

    Q_OBJECT
private:
    Ui::Welcome *ui;

public:
    Welcome(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *ev);
    ~Welcome();
};


#endif