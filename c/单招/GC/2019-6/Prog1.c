/*------------------------------------------------------------------------
【程序改错】
--------------------------------------------------------------------------

题目：对存储在string数组内的所有以字符‘a’开始并以字符‘e’结尾的单词做
      加密处理。

加密规则：若单词长度为偶数个字符，则将组成单词的所有字母循环左移一次；否则
          循环右移一次。

例如：单词able经循环左移一次后变为blea；单词abide经循环右移一次后变为eabid。
数组原数据：she is able to abide her.
加密后数据：she is blea to eabid her.

--------------------------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
------------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
void wordchange(char str[])
{  
    int i,j,k,m;  
    char c;
    for(i=0;str[i];i++)
    {
        for(j=i,k=i;isalpha(str[k]);k++);    
        /***********FOUND***********/
        if(str[j]=='a'||str[k-1]=='e')         
        {
        /***********FOUND***********/
            if((k-j)%2=0)                    
            {
                c=str[j];
                for(m=j;m<k-1;m++)           
                    str[m]=str[m+1];
                str[k-1]=c;
            }
            else
            {
                c=str[k-1];
                /***********FOUND***********/
                for(m=k;m>j;m--)                  
                    str[m]=str[m-1];
                str[j]=c;
            }
        }
        i=k;                                  
    }
}

int main()
{ 
    char string[80]="she is able to abide her.";
    puts(string);
    wordchange(string);
    puts(string);
    return 0;
}
