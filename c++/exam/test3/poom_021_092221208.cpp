#include <iostream>
class Animal
{
public:
    void respire(void) { std::cout << "可以呼吸\n"; }
    void eat(void) { std::cout << "可以吃东西\n"; }
    Animal(){}
    ~Animal(){}
};

class Ape : public Animal
{
public:
    void move(void) { std::cout << "可以行走\n"; }
    void makingTools(void) { std::cout << "可以制造工具\n"; }
    Ape() {}
    ~Ape() {}
};

class Human : public Ape
{
public:
    void miss(void) { std::cout << "可以思考\n"; }
    Human() {}
    ~Human() {}
};


int main()
{
    Human human;
    std::cout << "人类具备的能力如下:\n";
    human.respire();
    human.eat();
    human.move();
    human.makingTools();
    human.miss();
    return 0;
}