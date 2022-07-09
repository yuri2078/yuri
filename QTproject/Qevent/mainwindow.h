#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylabel.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_time;
    int timeid_1;
    int timeid_2;
};
#endif // MAINWINDOW_H
