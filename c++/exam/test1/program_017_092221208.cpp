#include <iostream>
int main()
{
    int a[2][3], b[3][2], c[2][2] = {0}, i, j, k;
    std::cout << "输入第一个矩阵" << "\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cin >> a[i][j];
        }
    }
    std::cout << "输入第二个矩阵" << "\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            std::cin >> b[i][j];
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    std::cout << "矩阵相乘的结果是" << "\n";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            std::cout << c[i][j] << ' ';
        }
        std::cout << "\n";
    }
    return 0;
}
