#include <iostream>
using namespace std;
int main()
{
    void allPrime(int n);
    int prime(int x);
    int n;
    cout  << "请输入所求素数的最大界限值： ";
    cin >> n;
    allPrime(n);
    return 0;
}

int prime(int x)
{
    if(x < 2) 
    {
        return 0;
    }
    for (int i = 2; i <= x / 2;i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void allPrime(int n)
{
    int i, k = 0;
    for (i = 1; i <= n;i++)
    {
        if(prime(i))
        {
            cout.width(6);
            cout << i;
            k++;
            if(k % 10 == 0)
            {
                cout << endl;
            }
        }
    }
}