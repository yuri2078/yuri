#include <stdio.h>
void daYing(int x,char ch)
{
    if(x>1)
    {
        for (int i = 0; i < 2 * x - 1;i++)
        {
            printf("%c", ch);
        }
        printf("\n");
        daYing(x - 1, ch);
        for (int i = 0; i < 2 * x - 1;i++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    else
        printf("%c\n",ch);
}
int main(void)
{
    int x;
    void daYing(int x,char ch);
    scanf("%d",&x);
    daYing(x,'*');
    return 0;
}