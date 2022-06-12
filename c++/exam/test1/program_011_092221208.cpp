#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    int x, i=0, k=0;
    int number[21] = {0};
    char s[80];
    cin.getline(s, 80);
    while(s[i])
    {
        if(isdigit(s[i]))
        {
            x = 0;
            k++;
            while(isdigit(s[i]))
            {
                x = x * 10 + s[i] - 48;
                i++;
            }
            number[x]++;
        }
        else 
        {
            i++;
        }
    }
    cout << k << endl;
    for (i = 0; i < 21;i++)
    {
        if(number[i])
        {
            cout << '[' << i << "]=" << number[i] <<' ';
        }
    }
    return 0;
}