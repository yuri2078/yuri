#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qpushbutton.h>
#include "log.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *menu = menuBar(); //新建菜单栏 只能存在一个
    setMenuBar(menu); //为窗口设置菜单栏
    QMenu *file = menu->addMenu("文件"); //新建菜单
    QMenu *edit = menu->addMenu("编辑"); //新建菜单
    QAction *action_1 = file->addAction("新建"); //新建 菜单选项
    file->addSeparator(); //新建分隔线
    QAction *action_2 = file->addAction("编辑");

    QToolBar *tool = new QToolBar(this); //新建工具栏并让他归附于窗口
    addToolBar(Qt::TopToolBarArea,tool); //在窗口添加工具栏,并设置默认上面显示
    tool->setAllowedAreas(Qt::TopToolBarArea | Qt::RightToolBarArea); //设置只允许上面或者右面显示
    tool->setFloatable(false); //禁止浮动
    tool->setMovable(false); //禁止移动

    tool->addAction(action_1);
    tool->addSeparator(); //添加分割线
    tool->addAction(action_2); //通过Qaction 公用一个字

    QPushButton *button_1 = new QPushButton("清除日志", this);
    tool->addWidget(button_1); //添加控件

    connect(button_1, &QPushButton::clicked, this, []() {
        m_log.clean();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

