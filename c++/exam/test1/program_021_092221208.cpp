#include <iostream>

class animal
{
protected:
    std::string name;
    int age;
    std::string sex;
public:
    animal(std::string name, int age, std::string sex);
    ~animal();
    void eat(void);
    void display(void);
};

animal::animal(std::string name, int age, std::string sex) 
{
    this->name=name;
    this->age = age;
    this->sex = sex;
    std::cout << name << "出生了\n";
}

animal::~animal()
{
    std::cout << name << "去世了\n";
}

void animal::display(void)
{
    std::cout << "姓名:" << name << "  年龄:" << age << "   性别:" << sex << "\n";
}

void animal::eat(void)
{
    std::cout << name << "正在吃东西\n";
}
class score
{
protected:
    int chinese;
public:
    score(int c){chinese = c;}
};
class people :public animal
{
private:
    std::string food;
public:
    people(std::string name, int age, std::string sex, std::string food);
    ~people();
    void eat(void);
};

people::people(std::string name, int age, std::string sex, std::string food) : animal (name,age,sex)
{
    this->food = food;
    std::cout << "人类" << name << "出生了" << "\n";
}

people::~people()
{
    std::cout << "人类" << name << "死去了\n";
} 

void people::eat(void)
{
    std::cout << name << "正在吃" << food << "\n";
}

class student : public people,public score
{
private:
    int num;
public:
    student(int num, std::string name, int age, std::string sex, std::string food, int chinese);
    ~student();
    void ddisplay(void);
    void fun1(void);
};
student::student(int num, std::string name, int age, std::string sex, std::string food, int chinese) : people (name,age,sex,food),score(chinese)
{
    this->num = num;
    std::cout << "学生 " << name << "出生了\n";
}

void student::fun1(void)
{
    std::cout << name << "\n";
}

student::~student()
{
    std::cout << "学生 " << name << "死掉了\n";
}

void student::ddisplay(void) 
{
    std::cout << "学号：" << num << "姓名:" << name << "  年龄:" << age << "   性别:" << sex << " 分数：" << chinese << "\n";
}


int main()
{
    animal a1("旺财", 11, "公");
    a1.display();
    a1.eat();
    people p1("张三", 18, "男", "苹果");
    p1.display();
    p1.eat();
    student s1(1001, "李梅", 17, "女", "上等食物",66);
    s1.display();
    s1.eat();
    s1.fun1();
    return 0;
}