#include <iostream>

//定义基类
class Animal
{
public :
    std::string name;
    virtual ~Animal(); //如果基类里面有虚方法，则需要把析构定义成虚方法，不然释放内存的时候他之后析构基类的，不会去析构派生类
    Animal(std::string youname);
    void sleep(void);
    // virtual void eat(void) = 0; 抽象方法告诉编译器不用找他的实现，因为没有定义。
    virtual void play(void);//加上virtual 变成虚方法
};
Animal::~Animal()
{

}

void Animal::play(void)
{
    std::cout << name << "正在玩\n";
}
Animal::Animal(std::string youname)
{
    name = youname;
}

class people : public Animal //继承基类
{
public:
    std::string pname;
    people(std::string youname);
    void play(void); //重新定义eat方法，称之为覆盖。
    int sex;
};

void people::play(void) //对原来的play进行覆盖
{
    std::cout << pname << "正在玩游戏\n";
}

people::people(std::string youname) : Animal(youname) //默认会先初始化基类；这样会将基类初始化继承到animal
{
    pname = "人名:" + youname;
}

int main()
{
    people *p1 = new people("小明");
    Animal *a1 = new Animal("tom");
    //std::cout << "people 的名字是:" << p1->pname << '\n';
    std::cout << "Animal 的名字是:" << p1->pname << '\n';
    std::cout << "people 玩：";
    p1->play(); //当你指定的指针的类型为基类，定义一个派生类时,覆盖的方法会失效，需要在基类加上virtual 这样后面的子类默认也是virtual
    std::cout << "Animale 的名字是:" << a1->name << '\n';
    std::cout << "Animal 玩: ";
    a1->play();
    delete p1;
    delete a1;
    return 0;
}