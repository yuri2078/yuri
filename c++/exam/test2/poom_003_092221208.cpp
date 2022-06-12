#include <iostream>

class Circle
{
public:
    float r; //定义半径
    Circle(); //构造函数进行初始化
    void area(void); //求值函数
};

Circle::Circle()
{
    std::cout << "输入半径:";
    std::cin >> r;
    area();
}

void Circle::area(void)
{
    std::cout << "圆的面积=" << r * r * 3.14;
}

class Rectangle
{
public:
    float x,y;
    Rectangle();
    void area(void);
};

Rectangle::Rectangle()
{
    std::cout << "输入长和宽:";
    std::cin >> x >> y;
    area();
}

void Rectangle::area(void)
{
    std::cout << "矩形面积=" << x * y;
}

class Square
{
public:
    float x;
    Square();
    void area(void);
};

Square::Square()
{
    std::cout << "输入边长:";
    std::cin >> x;
    area();
}

void Square::area(void)
{
    std::cout << "正方形面积=" << x * x;
}

int main()
{
    char ch;
    std::cout << "请输入选择\n";
    std::cout << "圆形-c，矩形-r，正方式-s:";
    std::cin >> ch;
    switch(ch)
    {
        case 'c' :
        {
            Circle c1;
            break;
        }
            
        case 'r':
        {
            Rectangle r1;
            break;
        }
            
        case 's':
        {
            Square s1;
            break;
        }
            
        default:
            std::cout << "输入错误！";
    }
    return 0;
}