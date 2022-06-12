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
    std::cout << "С��" << dogName << "����,";
}

int Dog::GetDogNumber(void)
{
    return DogNumber;
}

int Dog::DogNumber = 0;

int main()
{
    Dog d1("����");
    d1.display();
    std::cout << "��ǰ��С��" << Dog::GetDogNumber() << "��\n";
    Dog d2("����");
    d2.display();
    std::cout << "��ǰ��С��" << Dog::GetDogNumber() << "��\n";
    Dog d3("��Դ");
    d3.display();
    std::cout << "��ǰ��С��" << Dog::GetDogNumber() << "��\n";
    return 0;
}