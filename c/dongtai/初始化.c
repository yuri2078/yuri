#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int *p;
    p = (int *)calloc(1,sizeof(int));
    if(p == 0)
    {
        printf("p  的值是0   \n");
    }
    free(p);
    return 0;
}