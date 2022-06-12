#include <stdio.h>
int main(void)
{
    float x = 1.0;
    int i;
    for (i = 0; i < 365 * 3 / 5;i++)
    {
        x = x * 1.01 * 1.01 * 1.01 * 0.99 * 0.99;

    }
    printf("%f", x - 1);
}