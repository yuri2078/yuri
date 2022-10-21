#include <stdio.h>
#include "mytool.h"

int main(void)
{
    Queue q;
    SqStack s;
    ElemType e = 0;
    int n;

    //初始化数据类型
    initQueue(&q);
    initSqStack(&s);

    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&e);
        enQueue(&q,e);
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&e);
        pushSqStack(&s,e);
    }

    int flag = 0, number = n;
    while (!isQueueEmpty(&q))
    {
        ElemType data_s,data_q;
        getTop(&s,&data_s);
        deQueue(&q,&data_q);

        if(data_q == data_s)
        {
            flag = 0; //有同学拿到玩具，重新开始计数
            number--; //没拿到玩具的同学减一
            popSqStack(&s,&data_s);
        }else{
            flag++;
            enQueue(&q,data_q);
        }

        //当没拿到玩具的同学等于重新入队人数时，退出循环
        if(flag == number){
            break;
        }
    }
    printf("%d\n",number);
    return 0;
}