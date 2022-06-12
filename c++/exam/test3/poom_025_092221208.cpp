#include <iostream>

class Engine
{
private:
    std::string _type;
    int _power;
public:
    Engine(std::string _type, int _power);
    ~Engine() { std::cout << "调用发动机Engine析构函数\n"; }
    void show(void);
};

Engine::Engine(std::string _type, int _power)
{
    this->_type = _type;
    this->_power = _power;
    std::cout << "调用发动机Engine构造函数\n";
}

void Engine::show(void)
{
    std::cout << "发动机型号：" << _type << "发动机功率：" << _power << "\n";
}

class Vehicle
{
private:
    std::string _name;
public:
    Vehicle(std::string _name);
    ~Vehicle() { std::cout << "调用交通工具Vehicle析构函数\n"; }
    void run(void) { std::cout << _name << "正在行驶中\n"; }
    std::string getName(void) { return _name; }
};

Vehicle::Vehicle(std::string _name)
{
    this->_name = _name;
    std::cout << "调用交通工具Vehicle构造函数\n";
}

class Car : public Vehicle
{
private:
    int _seats;
    std::string _color;
    
public:
    Engine engine;
    Car(int _seats, std::string _color, std::string _type, int _power, std::string _name);
    void brake(void) { std::cout << getName() << "停车\n"; }
    void display(void);
    ~Car() { std::cout << "调用小汽车Car析构函数\n"; }
};

Car::Car(int _seats, std::string _color, std::string _type, int _power, std::string _name) : Vehicle(_name), engine(_type,_power)
{
    this->_seats = _seats;
    this->_color = _color;
    std::cout << "调用小汽车Car构造函数\n";
}

void Car::display(void)
{
    std::cout << getName() << "有" << _seats << "个座位，颜色为" << _color << "\n";
}

int main()
{
    Car car(5,"red","EA113",130,"passat");
    car.run();
    car.brake();
    car.display();
    car.engine.show();
    return 0;
}