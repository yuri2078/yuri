#include <iostream>

class Car
{
private:
    int nSeats;
    const char *pCarName;
public:
    Car();
    Car(const char *CarName,int Seats);
    ~Car();
    int GetSeats(void) { return nSeats; }
    const char *GetCarName(void) { return pCarName; }
    void showInfo(void) { std::cout << pCarName << "共" << nSeats << "座\n"; }
};

Car::Car()
{
    pCarName = "标准车型";
    nSeats = 4;
    std::cout << pCarName << "生产：共" << nSeats << "座\n";
}

Car::Car(const char *CarName,int Seats)
{
    pCarName = CarName;
    nSeats = Seats;
    std::cout << CarName << "生产：共" << Seats << "座\n";
}

Car::~Car()
{
    std::cout << pCarName << "被车辆报废\n";
}

int main()
{
    Car car1;
    Car mynewcar("我的车",7);
    Car tomcar("赵钱的车",11);
    return 0;
}