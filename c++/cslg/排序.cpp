#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> number(n, 0);
    for (int i = 0; i < n;i++){
        std::cin >> number[i];
    }
    std::sort(number.begin(), number.end());
    for (int i = n - 1; i >= 0;i--){
        std::cout << number[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}