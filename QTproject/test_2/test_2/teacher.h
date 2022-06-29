#ifndef TEACHER_H //如果没有定义则 --
#define TEACHER_H //定义宏 
//这样写防止出现重新定义

#include <qobject.h>
#include <QPushButton>

using std::string;

class Teacher : public QObject
{

    Q_OBJECT //包含qobject宏
private:
    int age;
    QString name;
public:
    Teacher(QObject * parent = nullptr);
    void eat();
    void eat(string food);
    int clean();
signals: 
    //自定义信号
    void hungry();
    void hungry(string food); //重载
public slots: 
    //早期的槽只能定义在这下面，现在可以定义在public 中
    //他的返回值是void 
    //他需要声明也需要实现


};

#endif