#include <iostream>
#include <cmath>

class  Line
{
private:
    int x1, y1, x2, y2;
public: 
    inline Line(); //inline；设置为内联函数
    inline Line(int x1, int y1, int x2, int y2);
    inline void printPoint(void);
    inline double getDis(void);
};

Line::Line()
{
    x1 = x2 = y1 = y2 = 0; //默认两点为原点
}

Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void Line::printPoint(void)
{
    std::cout << "A:(" << x1 << ',' << y1 << ")\n";
    std::cout << "B:(" << x2 << ',' << y2 << ")\n";
}

double Line::getDis(void)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    Line line(10,68,-5,6);
    line.printPoint();
    std::cout << "两点距离：" << line.getDis();
    return 0;
}