#include <iostream>
#include <string>
template <class T>
void sort(T *array, int num)
{
    for (int i = 0; i < num-1;i++)
    {
        for (int j = 0; j < num - 1 - i;j++)
        {
            if(array[j] > array[j+1])
            {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

template <class T>
void display(const T *array, int num)
{
    for (int i = 0; i < num;i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << "\n";
}

int main()
{
    std::string Str[10]={"Zhang","Li","Wang","Qian","Zhao","Wu","Xu","Tang","Shen","Liang"};
    int Int[8]={20,12,0,-5,9,-18,6,11};
    double Dou[7] = {3.07, 8.12, -0.45, 6, 10, -9, 7.29};
    sort(Str, 10);
    display(Str, 10);
    sort(Int,8);
    display(Int, 8);
    sort(Dou, 7);
    display(Dou, 7);
    return 0;
}