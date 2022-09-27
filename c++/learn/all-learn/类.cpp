#include <iostream>

//可以直接调用car中的函数 比如。 Car::runging();

//this指针，指向当前正在操作的类
/* 比如这样 在类中定义了一个car；

Car car;
Car::Car(char car)
{
    this->car = car; 我们用this指向类中的car
}
*/

union mima //只允许存放一个数据类型
{
    int x; //给x赋值后再给y赋值会自动丢掉x
    int y;
};

enum today{taday1,taday2}; //定义枚举类型.从左到右 值是0 - n
// today = taday1; 直接赋值

class Car
{
protected:
    int baohu; //保护的成员

private: 
    int siyou; //私有成员，只有这类可以使用

public: //公共的类成员，大家都可以访问
    std::string name; //车车的名字
    unsigned int oil; //车车的油量,默认满是100
    unsigned int tank; //车车每小时的油耗
    unsigned int add; //给车车加油
    Car(); //构造函数
    Car(Car &);//定义拷贝构造函数
    Car(const Car &&c); //定义移动构造函数
    Car(int y);
    ~Car(); //析构函数
    void run(void);
    void addOil(void);
};

Car::Car() 
//如果有参数还可以：Car::Car(int x) : oil(x)
{
    name = "miku";
    oil = 100;
    tank = 11;
    std::cin >> add;
}

Car::Car(int y)
{
    std::cout << "hello world\n";
}

Car::~Car()
{
    //先调用的类最后调用析构函数，后调用的类先调用析构函数
}

void Car::run(void)
{
    
    std::cout << "你的车车：" << name << "已经跑起来啦！ 当前油耗：" << tank << '\n';
    std::cout << "嘟嘟嘟已经跑了一小时了\n";
    if(tank > oil)
    {
        oil = 0;
    }
    else
    {
        oil = oil - tank;
    }
    std::cout << "爱车的还有" << oil << "的油\n";
}

void Car::addOil(void)
{
    oil = oil + add;
}

Car::Car(const Car &&c)
{
    this->oil = c.oil;
    this->baohu = c.baohu;
    std::cout << "调用移动构造函数\n";
} //定义移动构造函数
int main()
{
    //Car car(6);
    Car car;
    while(car.oil > 0)
    {
        car.run();
        std::cout << "给你的车车加油 :";
        std::cin >> car.add;
        car.addOil();
    }
    std::cout << "你的爱车没有油辣！";

    Car hello(std::move(car));
    return 0;
}