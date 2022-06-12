#include <stdio.h>
int prime(int x)
{
    int i;
    for (i = 2; i <= x / 2;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
void zhiYinZi(int x)
{
    int i;
    if(prime(x))
        printf("%d", x);
    else{
        for (i = 2; i <= x / 2;i++)
        {
            if(prime(i))
            {
                if(x%i==0)
                {
                    printf("%d*", i);
                    zhiYinZi(x / i);
                    break;
                }
            }
        }
    }
}
int main(void)
{
    int x;
    void zhiYinZi(int x);
    int prime(int x);
    scanf("%d", &x);
    zhiYinZi(x);
    return 0;
}