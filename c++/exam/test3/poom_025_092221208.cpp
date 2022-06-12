#include <iostream>

class Engine
{
private:
    std::string _type;
    int _power;
public:
    Engine(std::string _type, int _power);
    ~Engine() { std::cout << "���÷�����Engine��������\n"; }
    void show(void);
};

Engine::Engine(std::string _type, int _power)
{
    this->_type = _type;
    this->_power = _power;
    std::cout << "���÷�����Engine���캯��\n";
}

void Engine::show(void)
{
    std::cout << "�������ͺţ�" << _type << "���������ʣ�" << _power << "\n";
}

class Vehicle
{
private:
    std::string _name;
public:
    Vehicle(std::string _name);
    ~Vehicle() { std::cout << "���ý�ͨ����Vehicle��������\n"; }
    void run(void) { std::cout << _name << "������ʻ��\n"; }
    std::string getName(void) { return _name; }
};

Vehicle::Vehicle(std::string _name)
{
    this->_name = _name;
    std::cout << "���ý�ͨ����Vehicle���캯��\n";
}

class Car : public Vehicle
{
private:
    int _seats;
    std::string _color;
    
public:
    Engine engine;
    Car(int _seats, std::string _color, std::string _type, int _power, std::string _name);
    void brake(void) { std::cout << getName() << "ͣ��\n"; }
    void display(void);
    ~Car() { std::cout << "����С����Car��������\n"; }
};

Car::Car(int _seats, std::string _color, std::string _type, int _power, std::string _name) : Vehicle(_name), engine(_type,_power)
{
    this->_seats = _seats;
    this->_color = _color;
    std::cout << "����С����Car���캯��\n";
}

void Car::display(void)
{
    std::cout << getName() << "��" << _seats << "����λ����ɫΪ" << _color << "\n";
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