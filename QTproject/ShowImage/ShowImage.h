#ifndef SHOWIMAGE_H
#define SHOWIMAGE_H

#include <QDialog>
#include "ui_ShowImage.h"

class ShowImage : public QDialog
{
public:
    ShowImage(QWidget *parent = nullptr);
    ~ShowImage();

    void paintEvent(QPaintEvent *);
    void on_before_clicked();
    void on_next_clicked();

private:
    Ui::ShowImage *ui;
    int img_index;

signals:

public slots:
};

#endif