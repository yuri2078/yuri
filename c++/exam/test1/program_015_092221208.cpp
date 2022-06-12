#include <iostream>
using namespace std;
int main()
{
    freopen("p15_092221208.out", "w", stdout);
    int i, j;
    int prime[10000] = {1, 1};
    for (i = 2; i*i < 10000; i++)
    {
        if (prime[i] == 0)
        {
            for (j = 2; i * j < 10000; j++)
            {
                prime[i * j] = 1;
            }
        }
    }
    for (i = 0; i < 10000; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << ' ';
        }
    }
    return 0;
}