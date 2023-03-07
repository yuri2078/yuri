/*----------------------------------------------------------------------
【程序填空】
------------------------------------------------------------------------
题目：程序依据二维字符型数组str中N个字符串的长度降序显示。

程序运行结果如下：
Relay satellite Queqiao plays key role
Network safety is 5G
The move reflects
as well as a push
major Chinese
technolog

-----------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他部分。
---------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define N 6
int main(){
    char str[N][100]={
        "technolog",
        "Relay satellite Queqiao plays key role",
        "The move reflects",
        "as well as a push",
        "Network safety is 5G",
        "major Chinese "};
    int i,j,k,p[N];
    for(i=0;i<N;i++)
        p[i]=i;
    for(i=0;i<N-1;i++)
    {
        for(j=0;j<N-1-i;j++)
            if(strlen(str[p[j]])<strlen(str[p[j+1]]))
            {
                p[j]-=p[j+1];
/**************************SPACE*************************/
                【?】;
                p[j]=p[j+1]-p[j];
            }
    }
    for(i=0;i<N;i++)
/**************************SPACE*************************/
        printf("%s\n",【?】);
    return 0;
}

