#include <stdio.h>
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j;
    int x[m][m];
    x[0][0] = n;
    for (i = 1; i < m;i++)
    {
        for (j = 0; j < i;j++)
        {
            x[j][i] = ++n;
        }
        x[i][i] = ++n;
        for (j = i - 1; j >= 0;j--)
        {
            x[i][j] = ++n;
        }
    }
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < m;j++)
        {
            printf("%4d", x[i][j]);
        }
        printf("\n");
    }
        return 0;
}