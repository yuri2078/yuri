/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：void sort(char number[][20],char city[][20],char key[][20])
      函数对city数组元素按照key值自定义序列beijing,shanghai,
      guangzhou的顺序排列，对于key值相同的那些元素，按照number
      的值以升序排列。number中的元素表示城市下属各地区的编号。
      int find(char s[],char key[][20])函数查找某个城市s在key
      函数自定义序列中的下标位置并返回。

例如：   排序前的数据:          
         number    city
           2     guangzhou
           1     shanghai
           2     beijing
           3     guangzhou
           1     beijing
           1     guangzhou
         排序后的数据:
         number    city
           1     beijing
           2     beijing
           1     shanghai
           1     guangzhou
           2     guangzhou
           3     guangzhou
      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define N 6
int find(char s[],char key[][20])
{
    int j;
    for(j=0;j<3;j++)
/***************FOUND****************/
        if(strcmp(s,key)==0)
            break;
    return j;
}


void sort(char number[][20],char city[][20],char key[][20])
{
    int i,j,p,n1,n2;
/***************FOUND****************/
    char temp[N][20];
    for(i=0;i<N-1;i++)
    {
        p=i;
        for(j=i+1;j<N;j++)
        {
            n1=find(city[p],key);
            n2=find(city[j],key);
            if(n1>n2) p=j;
/***************FOUND****************/                        
            if(n1==n2&&strcmp(number[p],number[j])) p=j;
        }
        if(p!=i)
        {
            strcpy(temp,number[i]);
            strcpy(number[i],number[p]);
            strcpy(number[p],temp); 
            strcpy(temp,city[i]);
            strcpy(city[i],city[p]);
            strcpy(city[p],temp);
        }
    }
}

int main() 
{
    char number[N][20]={"2","1","2","3","1","1"};
    char city[N][20]={"guangzhou","shanghai","beijing","guangzhou","beijing","guangzhou"};
    char key[3][20]={"beijing","shanghai","guangzhou"};       
    int i;
    printf("排序前的数据:\n");
    printf("number  city\n");
    for(i=0;i<N;i++)
        printf("%4s\t%s\n",number[i],city[i]);
    printf("\n");
    sort(number,city,key);
    printf("排序后的数据:\n");
    printf("number  city\n");
    for(i=0;i<N;i++)
        printf("%4s\t%s\n",number[i],city[i]);
    printf("\n");
    return 0;
}