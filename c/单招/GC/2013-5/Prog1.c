/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ����������У�����sort()�Ĺ����ǽ�����s�д�ŵ�Ӣ�Ķ�
      ���е����е���ȡ�����ֵ������˳�򱣴浽����w�С�

      �������ݣ�microsoft data access technologies.
      ���н����access data microsoft technologies.

����������еĴ���ʹ���ܵó���ȷ�Ľ����

---------------------------------------------------------
ע�⣺�������л�ɾ�У�Ҳ���ø��ĳ���Ľṹ��
--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROW 10
#define COL 20

/*******************FOUND*******************/
char sort(char [],char []);

void main()
{
    char sent[]="microsoft data access technologies.";
    char word[ROW][COL];
    int i,n;
    n=sort(sent,word);
    
    for(i=0;i<n-1;i++) 
        printf("%s ",word[i]);
    printf("%s\n",word[i]);
}

int sort(char s[],char w[][COL])
{
    int i=0,j=0,k=0,wordcount=0;
    char b[COL];
    while(s[i]){
        if(isalpha(s[i]))
/*******************FOUND*******************/
            w[k][++j]=s[i];
        else{
            w[k][j]=0;
            k++;
            j=0;
        }
        i++;
    }
    for(i=0;i<k-1;i++)
        for(j=0;j<k-1-i;j++)
            if(strcmp(w[j],w[j+1])>0){
                strcpy(b,w[j]);
/*******************FOUND*******************/
                strcpy(w[j+1],w[j]);
                strcpy(w[j+1],b);
            }
    wordcount=k;
    return wordcount;
}