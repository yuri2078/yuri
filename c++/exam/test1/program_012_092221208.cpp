#include <iostream>
using namespace std;
int main()
{
    void sort(int number[], int n);
    void print(int number[], int n);
    int n;
    cout << "��������������������: ";
    cin >> n;
    int number[n];
    for (int i = 0; i < n; i++)
    {
        cout << "�������" << i + 1 << "����";
        cin >> number[i];
    }
    sort(number, n);
    cout << "������" << endl;
    print(number, n);
    return 0;
}
void sort(int number[], int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (number[j] > number[j + 1])
            {
                t = number[j];
                number[j] = number[j + 1];
                number[j + 1] = t;
            }
        }
    }
}

void print(int number[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << number[i] << ' ';
    }
}