/*------------------------------------------------------------------------
【程序填空】
--------------------------------------------------------------------------
 题目：函数reveStr(char s[])的功能是把字符串s中的字符逆置。
       函数sortStr(char s[])的功能是把字符串s中的字符按照
       其ASCII码值从小到大进行排序。
 
 例如：若原有字符串为“cabde”；则
       调用reveStr(char s[])函数后，字符串为“edbac”；
       调用sortStr(char s[])函数后，字符串为“abcde”。
--------------------------------------------------------------------------
注意：除要求填空的位置之外，请勿改动程序中的其他内容。
--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
void reveStr(char s[])
{
    int len=0,i=0;
    char temp=' ';
/**************************SPACE*************************/
    while(【?】) len++;
    for(;i<len/2;i++)
    {
        temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
}

void sortStr(char s[])
{
   int i,j,len;
   char t='\0';   
   len=strlen(s);
   i=0;
   do
   {
/**************************SPACE*************************/                               
        for(j=0;j<【?】;j++)       
            if (s[j]>s[j+1])
            {
                t=s[j];s[j]=s[j+1];s[j+1]=t;
            }
        i++;
   }while(i<len-1);
}

void main()
{
    char str[]="cabde"; 
    printf("初始字符串是: ");
    printf("%s\n",str);            
    reveStr(str);     
    printf("逆置后的字符串是:"); 
    printf("%s\n",str);
    sortStr(str);
    printf("排序后的字符串是:"); 
    printf("%s\n",str);
}