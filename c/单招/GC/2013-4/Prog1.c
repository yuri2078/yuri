/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面程序的功能是：将一维字符数组中以空格为分隔符的
      单词转存到二维字符数组中，使二维数组的每一行以字符
      串的形式保存一个单词，然后将二维字符数组中的单词以
      每行一个的方式输出到屏幕上。其正确的输出是：
      Microsoft
      data
      access
      technologies

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define W_LEN 15    //单词长度，即单词中所允许包含字母的最大个数
#define W_COUNT 20    //字符串中所允许包含单词的最大个数

int changeStr(char [],char [][W_LEN]);

void main()
{
    char text[]="  Microsoft data  access technologies";
    char word[W_COUNT][W_LEN];
    int wcount=0;    //统计字符串中所含单词的个数
    int i;
/*******************FOUND*******************/
    wcount=changeStr(text[0],word);
    
    for(i=0;i<wcount;i++)
    {
        puts(word[i]);        
    }    

}

int changeStr(char str[],char word[][W_LEN])
{
    int i=0,j=0,k=0,newword=1;
    do{
        if(str[k]==32)    //32为空格字符的ASCII码
        {
            if(!newword)
            {
                newword=1;
/*******************FOUND*******************/                
                word[i][j]='';
                j=0;
                i++;
            }
            k++;
        }
        else
        {
            if(newword)    newword=0;
            word[i][j]=str[k];
            k++;
            j++;
        }
            
    }while(str[k]);    
/*******************FOUND*******************/    
    if(str[k]=32)
        return i;
    else
    {
        word[i][j]='\0';
        return i+1;
    }
}