#include <iostream>
#include <vector>
#include <array>

using std::cout;
using std::vector;


int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    vector<int> dp(n, 1);
    for (int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    std::cout << dp[n - 1] << std::endl;

    return 0;
}


