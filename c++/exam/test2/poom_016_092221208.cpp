#include <iostream>

class Dog
{
private:
    std::string dogName;
public:
    Dog(std::string);
    void display(void);
    static int DogNumber;
    static int GetDogNumber(void);
};

Dog::Dog(std::string dogName)
{
    this->dogName = dogName;
    DogNumber++;
}

void Dog::display(void)
{
    std::cout << "小狗" << dogName << "进场,";
}

int Dog::GetDogNumber(void)
{
    return DogNumber;
}

int Dog::DogNumber = 0;

int main()
{
    Dog d1("旺财");
    d1.display();
    std::cout << "当前有小狗" << Dog::GetDogNumber() << "条\n";
    Dog d2("进宝");
    d2.display();
    std::cout << "当前有小狗" << Dog::GetDogNumber() << "条\n";
    Dog d3("财源");
    d3.display();
    std::cout << "当前有小狗" << Dog::GetDogNumber() << "条\n";
    return 0;
}