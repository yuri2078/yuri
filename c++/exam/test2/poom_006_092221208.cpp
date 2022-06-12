#include <iostream>

class Complex
{
private:
    int Real, Image;
public:
    Complex(int Real, int Image); //构造函数
    Complex(const Complex &c); //拷贝构造函数
    void display(void);
};

Complex::Complex(int Real, int Image)
{
    this->Real = Real;
    this->Image = Image;
}

Complex::Complex(const Complex &c)
{
    Real = c.Real;
    Image = c.Image;
}

void Complex::display(void)
{
    std::cout << Real << "+" << Image << "i\n";
}

int main()
{
    Complex c1(11,15),c2(5,7);
    Complex c3(c1);
    std::cout << "c1=";
    c1.display();
    std::cout << "c2=";
    c2.display();
    std::cout << "c3=";
    c3.display();
    return 0;
}