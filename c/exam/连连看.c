#include <stdio.h>
int main(void)
{
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    int x[n][m],y[n][m];
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < m;j++)
        {
            scanf("%d", &x[i][j]);
            y[i][j] = x[i][j];
        }
    }
    for (i = 0; i < n;i++)
    {
        for (j = 0; j < m - 2;j++)
        {
            if(x[i][j]==x[i][j+1]&&x[i][j+1]==x[i][j+2])
                y[i][j] = y[i][j + 1] = y[i][j + 2] = 0;
        }
    }
    for (i = 0; i < m ;i++)
    {
        for (j = 0; j < n-2;j++)
        {
            if(x[j][i]==x[j+1][i]&&x[j+1][i]==x[j+2][i])
                y[j][i] = y[j + 1][i] = y[j + 2][i] = 0;
        }
    }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", y[i][j]);
            }
            printf("\n");
        }
    return 0;
}