#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *num = (int *)malloc(8 * sizeof(int)); //分配内存但是不重置为0 失败返回NULL
    int *num_2 = (int *)calloc(8, sizeof(int)); //分配n 个size内存 并置为0 失败返回 NULL
    num = realloc(num, 9 * sizeof(int)); //重新分配内存 可大， 可小 原有数据不变
    free(num);
    free(num_2);
    return 0;
}