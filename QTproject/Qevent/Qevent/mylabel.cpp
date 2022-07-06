#include "mylabel.h"
#include "log.hpp"
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel{parent}
{

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
    cout("鼠标移动");
    
} //鼠标移动

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    cout("鼠标按下");
    cout("相对于窗口 坐标是： x -- ", ev->position().x(), " y -- ", ev->position().y()); //打印坐标
    cout("相对于屏幕 坐标是： x -- ", ev->globalPosition().x(), " y -- ", ev->globalPosition().y());
} //鼠标按下

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    cout("鼠标释放");
} //鼠标释放

void myLabel::clean_log()
{
    logClean();
}