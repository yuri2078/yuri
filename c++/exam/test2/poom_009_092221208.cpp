#include <iostream>
class Rabit
{
private:
    std::string *name;
    std::string *food;
public:
    Rabit(std::string name,std::string food);
    ~Rabit();
    void eat(void);
};

Rabit::Rabit(std::string name,std::string food)
{
    this->name = new std::string(name);
    this->food = new std::string(food);
    std::cout << "兔子" << *this->name << "出生\n";
}

Rabit::~Rabit()
{
    std::cout << "兔子" << *name << "死亡\n";
    delete name;
    delete food;
}

void Rabit::eat(void)
{
    std::cout  << *name << " 正在吃 " << *food << " \n";
}

int main()
{
    Rabit lan("蓝莓", "萝卜");
    lan.eat();
    Rabit dou("豆豆", "白菜");
    dou.eat();
    return 0;
}