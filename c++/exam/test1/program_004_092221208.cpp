#include <iostream>
using namespace std;
int main(void)
{
    cout << "从!、*、/、%、+、-、=运算符中选择三个参与算数运算";
    char def[7] = {'!', '*', '/', '%', '+', '-', '='}, ch;
    int sort[7] = {0};
    while (cin.peek() != '\n')
    {
        cin.get(ch);
        for (int j = 0; j < 7; j++)
        {
            if (ch == def[j])
            {
                sort[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (sort[i] != 0)
        {
            cout << def[i] << '\n';
        }
    }
    cout << endl;
    return 0;
}
