#include "widget.h"
#include "./ui_widget.h"
Widget::Widget(QWidget *parent) : QWidget(parent) //初始化窗口类
{
    ui = new Ui::Widget; //
    ui->setupUi(this);

    //按钮
    QPushButton * button_1;
    button_1 = new QPushButton;
    button_1->setText("按钮"); //设置按钮文本
    button_1->setParent(this); //设置依赖于哪个窗口 设置对象树，最最基础的类 Qobject 添加到这个类中，就可以在析构函数中，自动析构所有对象树中的东西
    button_1->show(); //在顶点显示一个按钮，默认新开一个窗口

    QPushButton * button_2 = new QPushButton("点击关闭窗口", this); //直接指定依附的窗口和文字 并且直接显示
    button_2->move(230, 230); //移动按钮
    button_2->resize(100, 100); //重新指定按钮大小
    resize(800, 800); //刷新窗口
    setWindowTitle("第一个窗口!"); //设置窗口标题
    setFixedSize(500, 500); //固定窗口大小

    connect(button_2, &QPushButton::clicked, this, &Widget::close); //点击关闭窗口
    this->t1 = new Teacher(this);
    // connect(t1, &Teacher::hungry, t1, &Teacher::eat); 不发生重载的写法
    //发生重载需要修改这句话，不然报错

    void (Teacher::*hungry)(string) = &Teacher::hungry;
    void (Teacher::*eat)(string) = &Teacher::eat;

    connect(t1, hungry, t1, eat); //执行hungry 函数时，执行 eat函数
    emit t1->hungry("吃棒槌"); //emit 无意义 表示信号的发送

    QPushButton *button_3 = new QPushButton("清空日志", this);
    button_3->move(200, 200);
    connect(button_3, &QPushButton::clicked, t1,&Teacher::clean);

    // disconnect(button_3, &QPushButton::clicked, t1, &Teacher::clean); //取消信号连接 
    // 信号可以连接信号
    // 信号的个数 必须大于等于 槽的个数    但是参数 类型要一一对应
    // 信号可以连接多个槽

    // lambda 匿名函数
    // []()->int mutable 修改的是拷贝而不是本体
    // {
    //     [ = ] 使用函数的所有局部变量 值传递
    //     [ & ] 使用函数的所有局部变量 引用传递
    //     [this] 使用类里的所有变量
    //     [ a ] 将a按值进行传递
    //     [ &a ] 默认是 const 不可以进行修改的，想要修改可以使用 mutable 修饰
    //     [ &a, b] a引用， b 值传递
    //     [ a, &b] a值传递， b引用
    //     [&, a, b] 除a b 值传递，其他引用
    //     [= , &a, &b] 除a b 应用 其他值传递
    //     return 666;0

    //    在connect中连接的时候尽量使用 赋值连接 用应用容易出问题
    
    // } () //加括号调用

    QPushButton *button_4 = new QPushButton("点我变小狗", this);
    button_4->move(140, 140);
    connect(button_4, &QPushButton::clicked,this, [button_4]() { 
        button_4->setText("小狗"); 
        });
}


Widget::~Widget()
{
    delete ui;
}

