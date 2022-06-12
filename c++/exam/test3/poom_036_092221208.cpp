#include <iostream>

template<class T>
class Number
{
private:
    T number[4];

public:
    Number(const T *number)
    {
        for (int i = 0; i < 4;i++)
        {
            this->number[i] = number[i];
        }
    }

    T Get_average()
    {
        return (number[0] + number[1] + number[2] + number[3]) / 4;
    }

    T Get_max()
    {
        T max = number[0];
        for (int i = 1; i < 4;i++)
        {
            if(max < number[i])
            {
                max = number[i];
            }
        }
        return max;
    }
};

int main()
{
    int number_int[4];
    float number_float[4];
    std::cout << "请输入4个整数：\n";
    for (int i = 0; i < 4;i++)
    {
        std::cin >> number_int[i];
    }
    Number<int> num_1(number_int);
    std::cout << "四个整数中的均值是：" << num_1.Get_average() << "\n";
    std::cout << "四个数中的最大值是：" << num_1.Get_max() << "\n";

    std::cout << "请输入4个实数：\n";
    for (int i = 0; i < 4;i++)
    {
        std::cin >> number_float[i];
    }
    Number<float> num_2(number_float);
    std::cout << "四个整数中的均值是：" << num_2.Get_average() << "\n";
    std::cout << "四个数中的最大值是：" << num_2.Get_max() << "\n";
    return 0;
}