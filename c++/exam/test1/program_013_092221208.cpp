#include <iostream>
using namespace std;
int main()
{
    int x, y, t, i;
    x = 1;
    y = 1;
    cout << "----------ÍÃ×Ó·±Ö³ÎÊÌâ----------" << endl << endl;
    for (i = 1; i <= 30; i++)
    {
        cout.width(8);
        cout.setf(ios_base::left);
        cout << x ;
        if(i % 5 == 0)
        {
            cout << endl;
        }
        t = x + y;
        x = y;
        y = t;
    }
    return 0;
}