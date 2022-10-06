#include <stdio.h>
#include <stdlib.h>

//定义顺序表结构体
typedef int ElemType;
typedef struct Sqlist
{
    ElemType *slist; //存放数据的头部指针
    int length; //数据长度
    int size; //顺序表的容量
}Sqlist;

//顺序表插入输入函数
int sqlistInsert(Sqlist *sqlist, int n)
{
    //如果空间满了则重新申请空间
    if(sqlist->length == sqlist->size){
        sqlist->slist = (ElemType *)realloc(sqlist->slist, (sqlist->size +1) * sizeof(ElemType));
    }
    
    //从尾部开始插入
    int i = sqlist->length;
    while(n < sqlist->slist[i - 1])
    {
        sqlist->slist[i] = sqlist->slist[i - 1];
        i--;
    }
    sqlist->slist[i] = n;

    sqlist->length++; //插入一个长度加一
    return i; //返回插入的位置
}

//打印顺序表函数
void printSqlist(Sqlist *sqlist)
{
    for (int i = 0; i < sqlist->length;i++){
        printf("%d   ", sqlist->slist[i]);
    }
    printf("\n");
}

//初始化顺序表函数
Sqlist * sqlistInit(int len)
{
    Sqlist *sqlist = (Sqlist *)malloc(sizeof(Sqlist)); //初始化顺序表结构体指针
    sqlist->slist = (ElemType *)malloc(len * sizeof(ElemType)); //初始化顺序表数据指针

    //初始化长度和容量
    sqlist->size = len;
    sqlist->length = 0;
    return sqlist; //返回创建的结构体指针
}

//顺序表一次性输入大量数据函数
void sqlistInput(Sqlist *sqlist, int len)
{
    //如果顺序表容量小于长度则重新分配内存
    if(len > sqlist->size)
    {
        //释放原来申请的内存
        free(sqlist->slist);
        free(sqlist);

        //重新初始化
        sqlist = sqlistInit(len);
    }
    
    //设置长度
    sqlist->length = len;

    //输入数据
    for (int i = 0; i < len;i++){
        scanf("%d", sqlist->slist + i);
    }
}

int main(void)
{
    int N, M;
    scanf("%d%d", &N, &M);
    Sqlist *sqlist = sqlistInit(M + N); //分配一个长度M + N 的顺序表
    sqlistInput(sqlist, N); //输入N个有序数据

    //插入M个数据
    for (int i = 0; i < M; i++)
    {
        int n;
        scanf("%d", &n);
        sqlistInsert(sqlist, n);
    }

    printSqlist(sqlist); //打印顺序表的内容

    //释放申请的内存
    free(sqlist->slist);
    free(sqlist);
    return 0;
}