#include <iostream>
class Vehicle
{
public:
    virtual void run()
    {
        std::cout << "运输工具::开始运行\n";
    }
    virtual void stop()
    {
        std::cout << "运输工具::被停止\n";
    }
};

class Motorcar : virtual public Vehicle
{
public:
    void run()
    {
        std::cout << "摩托车::开始运行\n";
    }
    void stop()
    {
        std::cout << "摩托车::刹车\n";
    }
};

class Bicycle : virtual public Vehicle
{
public:
    void run()
    {
        std::cout << "自行车::开始骑行\n";
    }
    void stop()
    {
        std::cout << "自行车::刹车\n";
    }
};

class Motorcycle : public Motorcar , public Bicycle
{
public:
    void run()
    {
        std::cout << "电动自行车::开始骑行\n";
    }
    void stop()
    {
        std::cout << "电动自行车::刹车\n";
    }
};

void running(Vehicle &v)
{
    v.run();
    v.stop();
}

int main()
{
    Vehicle v1;
    Bicycle b1;
    Motorcar m1;
    Motorcycle mc1;
    running(v1);
    running(b1);
    running(m1);
    running(mc1);
    return 0;
}