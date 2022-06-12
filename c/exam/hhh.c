#include <stdio.h>
int main()
{
    int a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        i = i + 2;
        a[i] = i + 5;
        printf("hello \n");
    }

    return 0;
}