#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//方法1 ： 暴力循环
int search_1(int *number, int n)
{
    int max = INT_MIN; //设置max初值，让他为最小值
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += number[j]; //不断相加判断是不是最大值
            //如果比最大值还要大则直接赋值给max
            if(max < sum){
                max = sum;
            }
        }
    }
    //返回最大值
    return max;
}

//方法2 从头相加 当小于0时则重新寻找起点
int search_2(int *number, int n)
{
    //设置最小值
    int max = INT_MIN, sum = 0;
    for (int i = 0; i < n;i++)
    {
        //如果出现比max大的就赋值给max
        //设置或运算防止出现都是负数无法赋值的情况
        if(((sum += number[i]) > 0 && max < sum) || max < sum){
            max = sum;
        }
        //放结果小于0时 重置sum为0
        if(sum < 0){
            sum = 0;
        }
    }
    return max;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *number = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n;i++){
        scanf("%d", number + i);
    }
    malloc(8 * sizeof(int));
    calloc(8, sizeof(int));
    realloc(number, sizeof(int));
    printf("%d\n", search_2(number, n));
    return 0;
}