/*************************************************************

题目：主函数main()中由数字和字母组成的字符串s为测试数据，程序
      主要提取字符串s中由字符'$'分隔的不同八进制数形式的字符串，
      将八进制数形式字符子串所对应的字符生成新的字符串t；然后
      统计字符串t中所有数字子串对应整数的出现频率。

例如：字符串s为"101$062$063$114$066$110$062$063$141$071"，处理
      后字符串t为"A23L6H23a9"，其中"23"对应整数23出现频率为2,
      "6"和"9"对应整数出现频率为1。

编写程序：
    1. 编写函数void GenStr(char s[],char t[]),计算字符串s中不同
       八进制数形式的字符子串，将每个八进制数形式字符子串所对应
       的字符保存在字符数组t中。

    2. 编写函数int CountFreq(char t[],int b[],int Freq[])，统计
       字符数组t中不同数字子串对应整数出现频率，不同整数保存在
       整数数组b中,出现频率保存在整数数组Freq中，函数返回整数个
       数。
     
**************************************************************
注意：请勿改动主程序main()中的任何语句。
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 10

void  GenStr(char s[],char t[])
{
/**********Program**********/




/**********  End  **********/
}

int CountFreq(char t[],int b[],int Freq[])
{
/**********Program**********/




/**********  End  **********/
}

int main()
{
    char s[]="101$062$063$114$066$110$062$063$141$071";
    char t[N]="";
    int b[N]={0},Freq[N]={0};
    int num=0,i=0;

    FILE *fp;
    if((fp=fopen("DATA.TXT","w"))==NULL)
    {
        printf("File open error\n");
        exit(0);
    }

    GenStr(s,t);
    printf("The string t is: %s\n",t);
    fprintf(fp,"The string t is: %s\n",t);

    num=CountFreq(t,b,Freq);
    printf("The different integer and frequency is: ");
    fprintf(fp,"The different integer and frequency is: ");
        
    for(i=0;i<num;i++)
    {
        printf("[%d: %d] ",b[i],Freq[i]);
        fprintf(fp,"[%d: %d] ",b[i],Freq[i]);

    }
    printf("\n");
    fprintf(fp,"\n");

    fclose(fp);
    getch();
    return 0;
}