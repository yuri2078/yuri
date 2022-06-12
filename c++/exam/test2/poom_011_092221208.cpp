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
    void showInfo(void) { std::cout << pCarName << "��" << nSeats << "��\n"; }
};

Car::Car()
{
    pCarName = "��׼����";
    nSeats = 4;
    std::cout << pCarName << "��������" << nSeats << "��\n";
}

Car::Car(const char *CarName,int Seats)
{
    pCarName = CarName;
    nSeats = Seats;
    std::cout << CarName << "��������" << Seats << "��\n";
}

Car::~Car()
{
    std::cout << pCarName << "����������\n";
}

int main()
{
    Car car1;
    Car mynewcar("�ҵĳ�",7);
    Car tomcar("��Ǯ�ĳ�",11);
    return 0;
}