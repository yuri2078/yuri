#include <iomanip>
#include <iostream>
using namespace std;
int main(void)
{
    int n, i,t=0;
    cin >> n;
    int triangle[n][n] = {1};
    for (i = 1; i < n; i++)
    {
        triangle[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
        triangle[i][i] = 1;
    }
    for (i = 0; i < n; i++)
    {
        if(i==0)
        {
            for (int k = 0; k < 6 * (n - i);k++)
            {
                cout << ' ';
            }
        }
        if((i+1)%2 != 0)
        {
            for (int k = 0; k < 6*(n-i+t); k++)
            {
                if (i == 0)
                    break;
                cout << ' ';
            }
            t++;
        }
        else
        {
            for (int k = 0; k < 6*(n-i+t-1); k++)
            {
                cout << ' ';
            }
            cout << ' ' << ' ' << ' ';
        }
        for (int j = 0; j <= i; j++)
        {
            cout << triangle[i][j] << setw(6);
        }
        cout << '\n';
    }
    cout << endl;
    return 0;
}
