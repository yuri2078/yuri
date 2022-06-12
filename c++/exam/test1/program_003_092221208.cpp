#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main(void)
{
    int  dice[7] = {0};
    srand((int)time(NULL));
    for(int i = 0; i < 1000;i++)
    {
        dice[rand() % 6+1]++;
    }
    cout << "1-6点的出现概率依次为: ";
    for(int i = 1; i < 7;i++)
    {
        cout << dice[i] / 10000.0  << ",";
    }
    cout << endl;
    return 0;
}