#include <stdio.h>
#include <math.h>
void ciFang(int x)
{
    int i=0;
    while(pow(2,i)<x)
        i++;
    if(pow(2,i)==x)
        printf("2(%d)", i);
    else
    {
        printf("2(%d)+", i - 1);
        ciFang(x - pow(2, i-1));
    }
}
int main(void)
{
    int x;
    void ciFang(int x);
    scanf("%d", &x);
    ciFang(x);
    return 0;
}