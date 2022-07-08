#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>   
#include <QFileDialog>
#include <QLineEdit> 
#include <QTextEdit>    
#include <QFile>  
#include <QFileInfo>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("文件处理");
    this->resize(450, 550);
    
    //新建控件

    QLineEdit *edit_1 = new QLineEdit(this);
    QPushButton *button_1 = new QPushButton("打开文件", this);
    QPushButton *button_2 = new QPushButton("查看信息", this);
    QTextEdit *edit_2 = new QTextEdit(this);

    //文本框初始化
    edit_1->resize(220, 30);
    edit_1->move(10, 10);
    edit_1->setReadOnly(true);

    //按钮初始化
    button_1->resize(80, 30);
    button_1->move(250, 10);
    button_2->resize(80, 30);
    button_2->move(360, 10);

    //大的文本框初始化
    edit_2->resize(440, 480);
    edit_2->move(5, 50);

//第一个按钮
    connect(button_1, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,"打开文件");
        edit_1->setText(fileName);

        QFile file(fileName, this);
        file.open(QFile::ReadOnly); //设置读取方法
        QByteArray array =  file.readAll(); //读取所有
        edit_2->setText(array);
        file.close(); //关闭文件
        // file_2.write("卧槽太好了"); //写文件

    });

//第二个按钮
    connect(button_2, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this,"打开文件");
        edit_1->setText(fileName);

        QFileInfo info(fileName);
        QString temp;
        temp = temp + "文件的名字是 --- " + info.fileName() + "\n";
        temp = temp + "文件的路径是 --- " + info.filePath() + "\n";
        temp = temp + "文件的创建日期是 --- " + info.birthTime().toString("yyyy/MM/dd hh:mm:ss") + "\n";
        temp = temp + "文件的后缀是 --- " + info.suffix() + "\n";
        temp = temp + "文件的大小是 --- " + QString::number(info.size()) + "B\n";
        edit_2->setText(temp);

    });

    
}

MainWindow::~MainWindow()
{
    delete ui;
}

