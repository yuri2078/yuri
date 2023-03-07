/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面程序中，函数sort()的功能是将数组s中存放的英文段
      落中的所有单词取出以字典升序的顺序保存到数组w中。

      测试数据：microsoft data access technologies.
      运行结果：access data microsoft technologies.

请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
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