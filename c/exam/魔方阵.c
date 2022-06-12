#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int i, j, k, t;
    k = 2 * n - 1;
    int x[k][k];
    for (i = 0; i < n;i++)
    {       
        for (j = i; j < k-i; j++)
        {
            for (t=i; t < k-i; t++)
            {
                x[i][t] = x[k - i-1][t] = x[t][i] = x[t][k - i-1] = i + 1;
            }
        }
    }
    for (i = 0; i < k;i++)
    {
        for (j = 0; j < k;j++)
        {
            printf("%d", x[i][j]);
        }
        printf("\n");
    }
    return 0;
}