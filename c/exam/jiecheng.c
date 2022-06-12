#include <stdio.h>
int main(void)
{
    int i, j, len=1, jw, a[1000]={1},x;
    int n;
    scanf("%d", &n);
    for (i = 1; i <= n;i++)
    {
        for (jw = 0, j = 0; j < len;j++)
        {
            x = a[j] * i + jw;
            a[j] = x % 10;
            jw = x / 10;
        }
        while(jw)
        {
            len++;
            a[len - 1] = jw % 10;
            jw = jw / 10;
        }
    }
        for (j = len-1; j >= 0;j--)
        {
            printf("%d", a[j]);
        }
        return 0;
}