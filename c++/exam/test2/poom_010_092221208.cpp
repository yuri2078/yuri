#include <iostream>

class Sheep
{
private:
    std::string name, color, type;
public:
    Sheep(std::string name, std::string color, std::string type);
    Sheep(const Sheep &s);
    ~Sheep();
    void show(void);
};

Sheep::Sheep(std::string name, std::string color, std::string type)
{
    this->name = name;
    this->color = color;
    this->type = type;
    std::cout << type << "的" << color << name << "出生\n";
}

Sheep::~Sheep()
{
    std::cout << name << "老去\n";
}

Sheep::Sheep(const Sheep &s)
{
    name = s.name;
    color = s.color;
    type = "克隆";
    std::cout << type << "的" << color << name << "出生\n";
}

void Sheep::show(void)
{
    std::cout << "\n生殖克隆开始\n\n";
}

int main()
{
    Sheep s1("多莉", "白色", "样本");
    s1.show();
    Sheep s2(s1);
    return 0;
}