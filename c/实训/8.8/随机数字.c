#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createNumber(int *number)
{
    int i;
    //利用时间更改随机数种子
    srand((unsigned)time(NULL));
    for (i = 0; i < 20;i++)
    {
        number[i] = rand() % 10;
        printf("%d  ", number[i]);
    }
    printf("\n");
}

int searchNumber(int *number, int x)
{
    int i, num = 0;
    for (i = 0; i < 20; i++)
    {
        if(x == number[i]){
            num++;
        }
    }
    return num;
}

int main(void)
{
    int number[20], x;
    printf("生成了以下岁随机数:");
    createNumber(number);
    printf("请输入你想要查找的数字:");
    scanf("%d", &x);
    printf("你输入的数字一共出现了%d次捏!\n", searchNumber(number, x));
    return 0;
}