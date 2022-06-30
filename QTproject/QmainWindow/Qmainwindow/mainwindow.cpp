#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qpushbutton.h>
#include <qstatusbar.h>
#include <qlabel.h>
#include <QDockWidget>
#include <qtextedit.h>
#include <qdialog.h>
#include <qmessagebox.h>
#include <qcolordialog.h>
#include <qfiledialog.h>
#include <qinputdialog.h>
#include "log.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //总结
    //菜单栏 中心部件 只能有一个 所以用 set 添加 用 函数生成
    //工具栏 浮动窗口 菜单选项 能有多个，所以需要new 和 add
    

    //菜单栏
    QMenuBar *menu = menuBar(); //新建菜单栏 只能存在一个
    setMenuBar(menu); //为窗口设置菜单栏
    QMenu *file = menu->addMenu("文件"); //新建菜单
    file->setIcon(QIcon(":/icon/icon-24.png"));
    QMenu *edit = menu->addMenu("编辑"); //新建菜单
    edit->setIcon(QIcon(":/icon/icon-48.png"));
    QAction *action_1 = file->addAction("新建"); //新建 菜单选项
    action_1->setIcon(QIcon(":/icon/icon-24.png"));
    file->addSeparator(); //新建分隔线
    QAction *action_2 = file->addAction("编辑");
    action_2->setIcon(QIcon(":/icon/icon-24.png"));

    //工具栏
    QToolBar *tool = new QToolBar(this); //新建工具栏并让他归附于窗口
    addToolBar(Qt::TopToolBarArea,tool); //在窗口添加工具栏,并设置默认上面显示
    tool->setAllowedAreas(Qt::TopToolBarArea | Qt::RightToolBarArea); //设置只允许上面或者右面显示
    tool->setFloatable(false); //禁止浮动
    tool->setMovable(false); //禁止移动

    tool->addAction(action_1);
    tool->addSeparator(); //添加分割线
    tool->addAction(action_2); //通过Qaction 公用一个字
    tool->addSeparator();

    QPushButton *button_1 = new QPushButton("清除日志", this);
    tool->addWidget(button_1); //添加控件

    connect(button_1, &QPushButton::clicked, this, []() {
        m_log.clean();
    });

    //状态栏 只能有一个
    QStatusBar *statusbar = statusBar(); //新建状态栏
    setStatusBar(statusbar);
    QLabel *label_1 = new QLabel("提示信息", this);
    QLabel *label_3 = new QLabel("提示信息", this);
    QLabel *label_2 = new QLabel("右侧提示信息", this);
    statusbar->addWidget(label_1); //在左侧设置状态
    statusbar->addWidget(label_3); //在左侧设置状态
    statusbar->addPermanentWidget(label_2); //在右侧设置提示

    //浮动窗口 连接部件 能有多个
    //依附在中心部件周围
    QDockWidget *dock_1 = new QDockWidget("这是标题", this);
    QDockWidget *dock_2 = new QDockWidget("这是标题", this);
    addDockWidget(Qt::BottomDockWidgetArea, dock_1); //添加浮动窗口
    addDockWidget(Qt::TopDockWidgetArea, dock_2);
    dock_1->setAllowedAreas(Qt::BottomDockWidgetArea); //设置仅仅允许在下面

    //中心部件 只能有一个
    QTextEdit *textEdit = new  QTextEdit(this); //添加文本输入框，将他设置成中心部件
    setCentralWidget(textEdit); //只能设置一次

    // 对话框
    QMenu *textBox = menu->addMenu("各种对话框");
    QAction *model = textBox->addAction("模态对话框");
    QAction *not_model = textBox->addAction("非模态对话框");
    QAction *critical = textBox->addAction("错误对话框");
    QAction *information = textBox->addAction("信息对话框");
    QAction *question = textBox->addAction("问题对话框");
    QAction *warning = textBox->addAction("危险对话框");
    QAction *my_color = textBox->addAction("选择颜色");
    QAction *my_file = textBox->addAction("选择文件");
    QAction *my_input = textBox->addAction("输入数据");
    connect(model, &QAction::triggered, [this]() {
        // 模态对话框 不可以进行别的操作
        QDialog *dialog = new QDialog(this);
        dialog->exec(); //阻塞程序，不叉掉就无法继续执行 这样执行显示 就是模态对话框
        dialog->resize(200, 100); //重新指定大小
        dialog->setAttribute(Qt::WA_DeleteOnClose); //设置关闭时就删除对象
        
    });

    connect(not_model, &QAction::triggered, [this]() {
        // 非模态对话框 可以进行别的操作
        QDialog *dialog = new QDialog(this);
        dialog->show();
        dialog->resize(200, 100); //重新指定大小
        dialog->setAttribute(Qt::WA_DeleteOnClose); //设置关闭时就删除对象
        
    });

    connect(critical, &QAction::triggered, [this]() {
        // 错误提示框 默认是模态对话框
        QMessageBox::critical(this, "标题", "错误！");
        
    });

    connect(information, &QAction::triggered, [this]() {
        // 信息提示框 默认是模态对话框
        QMessageBox::information(this, "标题", "信息！");
        
    });

    connect(question, &QAction::triggered, [this]() {
        // 问题提示框 默认是模态对话框
        if(QMessageBox::Save == QMessageBox::question(this, "标题", "需要保存日志吗？",QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        {
            m_log << "由提问框发出的日志";
        }
        
         //设置按钮类型 和默认类型
        
    });
   
   connect(warning, &QAction::triggered, [this]() {
        // 危险提示框 默认是模态对话框
        QMessageBox::warning(this, "标题", "危险");
        
    });

    connect(my_color, &QAction::triggered, [this]() {
        QColor color = QColorDialog::getColor(QColor(0,222,3,200));
        m_log << color.red() << color.green() << color.blue();
    });

    connect(my_file, &QAction::triggered, [this]() {
        QString str =  QFileDialog::getOpenFileName(this,"默认提示","E:\\vscode","(*.md)"); //后面默认路径 过滤文件
        m_log << str.toStdString();
        //返回值是路径
    });

    connect(my_input, &QAction::triggered, [this](){
        QLabel label;
        
        char temp[100];
        sprintf(temp, "您的年龄是: %d", QInputDialog::getInt(this, "年龄", "请输入你的年龄", 18));
        m_log << temp; 
        });
    //其他对话框
    // QColorDialog 选择颜色 QColorDialog::Getcolor();
    // QFileDialog 选择目录
    // QFontDialog 选择字体
    // QInputDialog 输入一个数据并且返回
    // QProgressDialog 输入操作过程
}

MainWindow::~MainWindow()
{
    delete ui;
}

