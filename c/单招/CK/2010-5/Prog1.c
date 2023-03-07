/*-------------------------------------------------------
【程序填空】
---------------------------------------------------------

题目：统计字符串str中单词的数量、最长单词的字母数、最短单
      词字母数。单词之间至少有一个空格。假设str中最长单词
      不超过20个字母。程序中isalpha函数功能是判断参数是否
      是字母字符，如果是字母字符，函数返回真，否则函数返
      回假。

---------------------------------------------------------
注意：请勿改动主函数main()中的其他内容。
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>
void main(){
    int i,len=0;
    int numofword,maxlen,minlen;
    char str[1000]="Robots can feel happy, sad,  angry, drowsy,  hungry or fearful.  They also have various personalities.";
/***********SPACE***********/
    numofword=【?】;
    maxlen=0;
    minlen=20;
    for(i=0;str[i];i++){
    if(!(isalpha(str[i])) && isalpha(str[i-1])){
        maxlen=len>maxlen? len: maxlen;
        minlen=len<minlen? len: minlen;
        len=0;
        numofword++;
    }
    else if(isalpha(str[i]))
/***********SPACE***********/
        【?】;
    }
    printf("单词数=%d,最长单词字母数=%d,最短单词字母数=%d\n",numofword,maxlen,minlen);
}