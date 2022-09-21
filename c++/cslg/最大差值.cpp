#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> number(n, 0);
    for (int i = 0; i < n; i++){
        std::cin >> number[i];
    }

    std::sort(number.begin(), number.end());
    int start = 0, end = n - 1;
    int min = number[end] - number[start];
    for (int i = 0; i < n; i++)
    {
        std::cout << number[i] << "  ";
    }

    std::cout << std::endl; 

    for (int i = 0; i < k; i++)
    {
        std::cout << number[end - 1] - number[start] << " -- " << number[end] - number[start + 1] << "  " << std::endl;
        if ((start < end - 1) && ((number[end - 1] - number[start]) < min) && ((number[end] - number[start + 1]) >= (number[end - 1] - number[start])))
        {
            min = number[end - 1] - number[start];
            end--;
        }
        else if ((start < end - 1) && ((number[end] - number[start + 1]) < min) && ((number[end - 1] - number[start]) >= (number[end] - number[start + 1])))
        {
            min = number[end] - number[start + 1];
            start++;
        }
    }

    std::cout << min << std::endl;
    return 0;
}