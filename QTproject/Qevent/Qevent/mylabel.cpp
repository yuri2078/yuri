#include "mylabel.h"
#include <QMouseEvent>
#include "log.hpp"

myLabel::myLabel(QWidget *parent) : QLabel{parent}
{
    setMouseTracking(true); //设置鼠标追踪
}

void myLabel::enterEvent(QEnterEvent *enter)
{
    cout("我进来拉");

}

void myLabel::leaveEvent(QEvent *event)
{
    cout("我又出去拉！");
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //这种方式对移动不管用 因为移动需要确定原来的坐标和新的坐标
    // if(ev->button() == Qt::LeftButton) //设置按下左键才执行
    // {
    //     cout("鼠标移动");
    // }

    //通过buttons设置移动操作
    if(ev->buttons() & Qt::LeftButton)
    {
        cout("鼠标移动");
    }
    cout("相对于窗口 坐标是： x -- ", ev->position().x(), " y -- ", ev->position().y()); //打印坐标
    cout("相对于屏幕 坐标是： x -- ", ev->globalPosition().x(), " y -- ", ev->globalPosition().y());

} //鼠标移动

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton) //设置按下左键才执行
    {
        cout("鼠标按下");
        cout("相对于窗口 坐标是： x -- ", ev->position().x(), " y -- ", ev->position().y()); //打印坐标
        cout("相对于屏幕 坐标是： x -- ", ev->globalPosition().x(), " y -- ", ev->globalPosition().y());
    }
    
} //鼠标按下

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    cout("鼠标释放");
} //鼠标释放

void myLabel::clean_log()
{
    cleanLog();
} //鼠标释放

//当发生事件的时候，事件收发器 enevt 函数 会判断寻找哪个事件，如果返回true 则用户自己处理
bool myLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress) //检测是否是鼠标摁下
    {
        QMouseEvent *mouse_1 = static_cast<QMouseEvent *> (e);
        cout("鼠标按下事件被拦截 位置 x -- ",mouse_1->position().x(),"  y --- ",mouse_1->position().y());
        return true;
    }
    return QLabel::event(e); //其他事件返回给父类处理
}
