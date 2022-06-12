#include <stdio.h>
int main(void)
{
    int n, k,sum=0,j=0;
    scanf("%d%d", &n, &k);
    int a[n], i;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
        if(sum>=k)
        {
            j++;
            sum = 0;
        }
    }
    if(sum)
        j++;
    printf("%d", j);
    return 0;
}