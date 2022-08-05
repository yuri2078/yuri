#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *num, i, n;
    num = (int *)malloc(sizeof(int) * 5);
    printf("请输入五个数: ");
    for (i = 0; i < 5;i++){
        scanf("%d", &num[i]);
    }
    while (1)
    {
        printf("请输入你想找的数字");
        scanf("%d", &n);
        i = 0;
        while (i < 5)
        {
            if(num[i] == n){
                printf("你已经找到了，他的下标是: %d\n", i);
                break;
            }
            i++;
        }
        if(i == 5)
        {
            char c = 0;
            c = getchar();
            while (c != '\n')
            {
                c = getchar();
            }
            printf("还没找到捏， 是否继续? Y/ N ？ ：");
            c = getchar();
            if (c == 'n' || c == 'N')
            {
                break;
            }
        }
        else{
            break;
        }
    }

    free(num);
    return 0;
}