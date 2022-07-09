#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button_1 = new QPushButton("清空日志", this);
    button_2 = new QPushButton("哈哈哈", this);
    button_time = new QPushButton("暂停", this);

    button_time->move(65, 550);
    QLabel *label_3 = new QLabel("1", this);
    label_3->move(100, 500);
    ui->label->setText("哈哈哈");
    connect(button_1,&QPushButton::clicked,[this](){
        ui->label->clean_log();
    });
//第一种定时器，麻烦
    //区分定时器
    timeid_1 = startTimer(300);
    timeid_2 = startTimer(1000); //设置每多少毫秒执行

//第二种定时器，通过定时器对象创建
    QTimer *timer_1 = new QTimer(this);
    timer_1->start(500); //设置运行时间
    connect(timer_1, &QTimer::timeout, [=]() {
        static int num = 0;
        label_3->setText(QString::number(num++));
    });

    connect(button_time, &QPushButton::clicked, [=]() {
        static int flag = 1;
        if(flag == 1)
        {
            timer_1->stop();
            button_time->setText("开始");
            flag = 0;
        }
        else
        {
            timer_1->start(500);
            button_time->setText("暂停");
            flag = 1;
        }
        
        
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    static int num_1= 0;
    static int num_2= 0;
    if(event->timerId() == timeid_1)
    {
        button_1->move(num_1 * 10 , num_1 * 10);
        num_1++;
    }

    if(event->timerId() == timeid_2)
    {
        num_2++;
        //每次执行该表他的值
        ui->label_2->setText(QString::number(num_2));
        button_2->move(num_2 * 10, num_2 * 10);
    }
}

