#ifndef WIDGET_H
#define WIDGET_H

//如果没有头文件则则包含头文件
#include <QWidget> //包含窗口类头文件

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT //允许类中使用信号和槽的机制

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui; //
};
#endif // WIDGET_H
