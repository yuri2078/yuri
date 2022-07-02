#include "widget.h"
#include "./ui_widget.h"
#include <qlistwidget.h>
#include <qstringlist.h>
#include <qtreewidget.h>
#include <qtablewidget.h>

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    QListWidget *listWidget = new QListWidget(this); //新建列表窗口
    QListWidgetItem *listItem_1 = new QListWidgetItem("我的爱宛如孤岛之花！", listWidget); //新建列表项并且添加进列表中
    listItem_1->setFont(QFont("微软雅黑"));
    // item_1->setTextAlignment(Qt::AlignCenter);
    this->resize(1000, 1000);
    listWidget->resize(400, 400);
    listWidget->move(0, 0);

    QStringList list_1; //新建string 列表
    list_1.push_back("我的爱宛如孤岛之花！");
    list_1.push_back("不为人知的绽放");
    list_1.push_back("不为人知的凋零!");
    list_1 << "轻声密语" << "\n" ; //重载了《《 运算符
    listWidget->addItems(list_1); //添加多个列表项

    QTreeWidget *tree_1 = new QTreeWidget(this); //新建树
    tree_1->resize(200, 200);
    tree_1->move(400, 400);

    QTreeWidgetItem * title_1 = new QTreeWidgetItem(QStringList() << "动漫"); //添加大的选项
    QTreeWidgetItem * title_2 = new QTreeWidgetItem(QStringList() << "小说");
    QTreeWidgetItem * item_1 = new QTreeWidgetItem(QStringList() << "终将成为你"); //新建小项目
    QTreeWidgetItem * item_2 = new QTreeWidgetItem(QStringList() << "安达与岛村");
    QTreeWidgetItem * item_3 = new QTreeWidgetItem(QStringList() << "轻声密语");
    tree_1->setHeaderLabels(QStringList() << "漫画" << "小说");
    tree_1->addTopLevelItem(title_1);
    title_1->addChild(item_1);
    title_1->addChild(item_2);
    title_1->addChild(item_3);
    //每个item 只能添加一次不能多个添加
    tree_1->addTopLevelItem(title_2);
    title_2->addChild(new QTreeWidgetItem(QStringList() << "安达与岛村"));
    title_2->addChild(new QTreeWidgetItem(QStringList() << "她的山，她的海"));
    title_2->addChild(new QTreeWidgetItem(QStringList() << "砰然为你"));
    
//表格

    QTableWidget *table_1 = new QTableWidget(this);
    table_1->setColumnCount(3); //设置列数
    table_1->setHorizontalHeaderLabels(QStringList() << "你好" << "谢谢" << "小笼包");
    table_1->setRowCount(4); //设置行数
    for (int i = 0; i < 4;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            table_1->setItem(i, j, new QTableWidgetItem("哈哈哈")); //添加正文
        }
    }
    table_1->move(0, 400);
    table_1->resize(400, 400);
}

widget::~widget()
{
    delete ui;
}

