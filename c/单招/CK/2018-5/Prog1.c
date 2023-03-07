/*-----------------------------------------------------------------------
【程序填空】
-------------------------------------------------------------------------
题目：f函数的功能是在母串中查找子串（子串长度不超过母串长度）。若认为
      "efab"也是母串"abcdef"的子串时，那么f函数的处理方法是在母串"abcdef"
      尾部再连接一次该串，成为"abcdefabcdef"，则可以在该串中查找到"efab"。

程序运行结果是
                ef      是   abcdef  子串
                deg     不是 abcdef  子串
                abcdefa 不是 abcdef  子串
                efab    是   abcdef  子串
                efb     不是 abcdef  子串

-------------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他部分。
------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define N 5
int f(char s[],char t[])
{
    int i,j;
    int ls=strlen(s);
    int lt=strlen(t);
    char p[30];
/*******************SPACE*******************/
    if(【?】)
        return 0;
/*******************SPACE*******************/
    strcat(【?】,s);
    i=0;
    while(i<ls)
    {
        j=0;
        while(p[i+j]==t[j])
            j++;
        if(t[j]==0)
            return 1;
        ++i;
    }
    return 0;
}
int main()
{
    char s[]="abcdef",t[5][10]={"ef","deg","abcdefa","efab","efb"};
    int i;
    for(i=0;i<N;i++)
        if(f(s,t[i]))
            printf("%-8s 是   %-8s 子串\n", t[i],s  );
        else
            printf("%-8s 不是 %-8s 子串\n", t[i] , s);
    return 0;
}
