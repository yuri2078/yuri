#include <iostream>

int gys(int x, int y) //求最大公约数
{
    x = x < 0 ? -x : x;
    y = y < 0 ? -y : y;//防止负数
    int i = x;
    while(x % i || y % i)
    {
        i--;
    }
    return i;
}

class Rational
{
private:
    int x, y;
public:
    Rational();
    Rational(int a, int b);
    Rational Add(Rational r1, Rational r2);
    Rational Sub(Rational r1, Rational r2);
    Rational Mul(Rational r1, Rational r2);
    Rational Div(Rational r1, Rational r2);
    void Print(void); //分式打印本对象数据
    void PrintFloat(void); //浮点数打印数据
};

Rational::Rational()
{
    x = y = 1;
}

Rational::Rational(int a, int b)
{
    x = a / gys(a, b);
    y = b / gys(a, b);
}

Rational Rational::Add(Rational r1, Rational r2) //分式加法
{
    Rational r(r1.x * r2.y + r2.x * r1.y, r1.y * r2.y);
    return r;
}

Rational Rational::Sub(Rational r1, Rational r2) //分式减法
{
    Rational r(r1.x * r2.y - r2.x * r1.y, r1.y * r2.y);
    return r;
}

Rational Rational::Mul(Rational r1, Rational r2) //分式乘法
{
    Rational r(r1.x * r2.x, r1.y * r2.y);
    return r;
}

Rational Rational::Div(Rational r1, Rational r2) //分式除法
{
    Rational r(r1.x * r2.y, r1.y * r2.x);
    return r;
}

void Rational::Print(void)
{
    if(x < 0 && y > 0) //把分子的符号移动到分母
    {
        std::cout << "x/y=" << -x << '/' << -y << '\n';
    }
    else if(x < 0 && y < 0) //把分子分母都有负号的情况转正
    {
        std::cout << "x/y=" << -x << '/' << -y << '\n';
    }
    else
    {
        std::cout << "x/y=" << x << '/' << y << '\n';
    }
}

void Rational::PrintFloat(void)
{
    std::cout << "x/y=" << (double)x/y << '\n';
}
int main()
{
    Rational r1(24, 60), r2(5, 7), r; //r 用来存放计算结果
    r1.Print();
    r2.Print();
    r=r.Add(r1, r2); //计算并存放在r中
    r.Print(); //用分式打印结果
    r=r.Sub(r1, r2);
    r.Print();
    r=r.Mul(r1, r2);
    r.Print();
    r=r.Div(r1, r2);
    r.Print();
    return 0;
}