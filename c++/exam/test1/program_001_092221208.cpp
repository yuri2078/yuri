#include <iostream>
using namespace std;
int main(void)
{
    char str[80];
    int i = 0;
    while(cin.peek() != '\n')
    {
        cin.get(str[i]);
        if((str[i] >= 'W' && str[i] < 'a' ) || str[i] >= 'w')
        {
            str[i] = str[i] - 22;
        }
        else 
        {
            str[i] = str[i] + 4;
        }
        i++;
    }
    str[i] = '\0';
    cout << str << endl;
    return 0;
}