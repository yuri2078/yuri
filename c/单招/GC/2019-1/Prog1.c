/*------------------------------------------------------------------------
【程序改错】
--------------------------------------------------------------------------

题目：将长度为n的字符串str看成一个首尾相连的环，这样从str的n个位置开始向后取n个
      字符，可以得到n个长度为n的字符串。程序找出这n个字符串中最小字符串。

例如：将长度为10的字符串"CBSTIBSTUO"看成一个首尾相连的环。因此可以分别得到
"CBSTIBSTUO"、"BSTIBSTUOC"、"STIBSTUOCB"…"OCBSTIBSTU"等10个字符串，
 这10个字符串中最小的字符串为"BSTIBSTUOC"。

程序运行结果如下：
CBSTIBSTUO起始位置为1的字符串BSTIBSTUOC是最小字符串
FJMQFJMPQS起始位置为4的字符串FJMPQSFJMQ是最小字符串

--------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define N 10
int comp(char str[], int p, int q) {
    int i ;
    for(i = 0; i < N; i++)
/***********FOUND***********/
        if(str[(p+i)%N] == str[(q+i)%N])
            return str[(p+i)%N] > str[(q+i)%N]; 
    return 0; 
}
int main() {
    char str[2][N+1]={"CBSTIBSTUO","FJMQFJMPQS"};
    int i,j,min;
    for(i = 0; i<2; i++)
    {
        min=0;
        for(j=1;j<N;j++)
/***********FOUND***********/
            if(comp(str[i], j, min)) 
                min = j;
        printf("%s起始位置为%d的字符串",str[i],min);
        for(j = 0; j < N; j++)
/***********FOUND***********/
            putchar(str[i][min+j]);
        printf("是最小字符串\n");
    }
    return 0;
}