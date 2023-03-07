/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：以下程序将5个字符串从小到大进行排序。字符串比较的规
      则为：将两个字符串自左至右逐个字符按ASCII码值大小进
      行比较，直到出现不同的字符或遇到'\0'为止。
      如果全部字符相同，则认为相等；若出现不相同的字符，
      则以第一个不相同字符的比较结果为准。

---------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
      且不能使用C语言的库函数进行填空。
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#define N 5
#define MAXLEN 100

/*函数compstr(char str1[],char str2[])实现字符串str1和
  字符串str2的比较，若str1等于str2,则返回0；若str1小于
  str2,则返回-1；若str1大于str2,则返回1*/

int compstr(char str1[],char str2[]){
    int flag=0;
    int i=0;
    while (str1[i]&&str2[i]&&!flag)
    {
/***************SPACE***************/
        if (【?】) flag=1;                        
        else if (str1[i]<str2[i]) flag=-1;
        i++;
    }
        
    if(!str1[i] && str2[i]) flag=-1;
    else if(str1[i] && !str2[i]) flag=1;
    return flag;
}

void main(){     
    char ls[N][MAXLEN]={"china","beijing","guangzhou","changchun","jiangsu"};
    char t[MAXLEN];
    int i, j;        

    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-1;j++)
/***************SPACE***************/
            if(【?】>0){ 
                strcpy(t,ls[j]);
                strcpy(ls[j],ls[j+1]);
                strcpy(ls[j+1],t);
            }
    printf("\n\n");
    for(i=0; i<N; i++) printf("%s ",ls[i]);
    printf("\n\n");
}