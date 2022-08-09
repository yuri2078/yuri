#include "test.h"
#include <QPushButton>
test::test(QWidget* parent)
    : QMainWindow(parent)
{
    resize(800, 800);
    QPushButton *button = new QPushButton("点击关闭窗口",this);
    button->move(300,300);
    button->resize(200,80);

}

test::~test()
{
}
