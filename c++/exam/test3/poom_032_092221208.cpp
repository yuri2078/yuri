#include <iostream>
class Complex
{
private:
    double real;
    double imag;

public:
    friend std::ostream &operator<<(std::ostream &cout,const Complex &c);
    Complex()
    {
        real = imag = 0;
    }

    Complex(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator+ (const Complex &c2)
    {
        Complex c;
        c.real = this->real + c2.real;
        c.imag = this->imag + c2.imag;
        return c;
    }

    Complex operator- (const Complex &c2)
    {
        Complex c;
        c.real = this->real - c2.real;
        c.imag = this->imag - c2.imag;
        return c;
    }

    Complex operator* (const Complex &c2)
    {
        Complex c;
        c.real = this->real * c2.real - this->imag * c2.imag;
        c.imag = this->imag * c2.real + this->real * c2.imag;
        return c;
    }

    Complex operator/ (const Complex &c2)
    {
        Complex c;
        c.real = (this->real * c2.real + this->imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
        c.imag = (this->imag * c2.real - this->real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
        return c;
    }

};

std::ostream & operator<< (std::ostream &cout,const Complex &c)
{
    std::cout << "(" << c.real << "," << c.imag << "i)\n";
    return std::cout;
}

int main()
{
    double real1, imag1, real2, imag2;
    std::cout << "请输入两个复数的实部，和虚部\n";
    std::cout << "例如 c1=3+4i，c2=5+(-10) 输入 3 4 5 -10\n";
    std::cin >> real1 >> imag1 >> real2 >> imag2;
    Complex c1(real1, imag1), c2(real2, imag2);
    std::cout << "c1+c2=" << c1 + c2;
    std::cout << "c1-c2=" << c1 - c2;
    std::cout << "c1*c2=" << c1 * c2;
    std::cout << "c1/c2=" << c1 / c2;
    return 0;
}