#include <iostream>
class Animal
{
public:
    void respire(void) { std::cout << "���Ժ���\n"; }
    void eat(void) { std::cout << "���ԳԶ���\n"; }
    Animal(){}
    ~Animal(){}
};

class Ape : public Animal
{
public:
    void move(void) { std::cout << "��������\n"; }
    void makingTools(void) { std::cout << "�������칤��\n"; }
    Ape() {}
    ~Ape() {}
};

class Human : public Ape
{
public:
    void miss(void) { std::cout << "����˼��\n"; }
    Human() {}
    ~Human() {}
};


int main()
{
    Human human;
    std::cout << "����߱�����������:\n";
    human.respire();
    human.eat();
    human.move();
    human.makingTools();
    human.miss();
    return 0;
}