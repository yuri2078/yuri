#include <iostream>
class Shape
{
public:
    virtual double GetArea() = 0;
    virtual double GetPerim() = 0;
    Shape()
    {

    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    double GetArea()
    {
        return 3.14 * radius * radius;
    }
    double GetPerim()
    {
        return  3.14 * 2 * radius;
    }
};

class Rectangle : public Shape
{
protected:
    double len;
    double wid;

public:
    Rectangle(double len, double wid)
    {
        this->len = len;
        this->wid = wid;
    }
    double GetArea()
    {
        return len * wid ;
    }
    double GetPerim()
    {
        return (len + wid) * 2;
    }
};

class Square : public Rectangle
{
public:
    Square(double len, double wid) : Rectangle(len, len)
    {
        
    }
};

double output_area(Shape &s)
{
    return s.GetArea();
}

double output_perim(Shape &s)
{
    return s.GetPerim();
}

int main()
{
    double len, wid, radius;
    std::cout << "请输入长度、宽度和半径的值：\n";
    std::cin >> len >> wid >> radius;
    Rectangle r1(len, wid);
    Circle c1(radius);
    Square s1(len, wid);
    std::cout<<"矩形面积是:" << output_area(r1) << "\n";
    std::cout << "矩形周长是:" << output_perim(r1) << "\n";
    std::cout<<"圆形面积是:" << output_area(c1) << "\n";
    std::cout << "圆形周长是:" << output_perim(c1) << "\n";
    std::cout<<"正方形面积是:" << output_area(s1) << "\n";
    std::cout << "正方形周长是:" << output_perim(s1) << "\n";
    return 0;
}