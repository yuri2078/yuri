/*----------------------------------------------------------------------
��������ա�
------------------------------------------------------------------------
��Ŀ���������ݶ�ά�ַ�������str��N���ַ����ĳ��Ƚ�����ʾ��

�������н�����£�
Relay satellite Queqiao plays key role
Network safety is 5G
The move reflects
as well as a push
major Chinese
technolog

-----------------------------------------------------------------------
ע�⣺��Ҫ����յ�λ��֮�⣬����Ķ������е��������֡�
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
                ��?��;
                p[j]=p[j+1]-p[j];
            }
    }
    for(i=0;i<N;i++)
/**************************SPACE*************************/
        printf("%s\n",��?��);
    return 0;
}

