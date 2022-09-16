#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> number(n, 0);
    for (int i = 0; i < n;i++){
        std::cin >> number[i];
    }
    std::sort(number.begin(), number.end());
    int start = 0, end = n - 1;
    int min = number[end] - number[start];
    
    for (int i = 0; i < k && start + end != n - 2; i++)
    {
        if(min > number[end-1] - number[start])
        {
            std::cout << "1\n";
            std::cout << "min" << min << std::endl;
            min = number[end - 1] - number[start];
            end--;
        }

        if (min > number[end] - number[start + 1])
        {
            std::cout << "2\n";
            std::cout << "min" << min << std::endl;
            min = number[end] - number[start + 1];
            start++;
        }
    }
    std::cout << min << std::endl;
    return 0;
}