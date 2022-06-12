#include <cmath>
#include <iostream>

class Rectangle
{
protected:
    int Left, Top, Right, Bottom;

public:
    Rectangle(int Left, int Top, int Right, int Bottom);
    void Diagonal(void);
};

Rectangle::Rectangle(int left, int top, int right, int bottom)
{
    Left = left;
    Top = top;
    Right = right;
    Bottom = bottom;
    std::cout << "左上角坐标为：(" << left << ',' << top << ")\n";
    std::cout << "左下角坐标为：(" << left << ',' << bottom << ")\n";
    std::cout << "右上角坐标为：(" << right << ',' << top << ")\n";
    std::cout << "右下角坐标为：(" << right << ',' << bottom << ")\n";
    Diagonal();
}

void Rectangle::Diagonal(void)
{
    float diagonal;
    diagonal = sqrt(pow((Right - Left), 2) + pow((Top - Bottom), 2));
    std::cout << "对角线长度为：" << diagonal;
}

int main()
{
    Rectangle r1(10, 10, 20, 5);
    return 0;
}