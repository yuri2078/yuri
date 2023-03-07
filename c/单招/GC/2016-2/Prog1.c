/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：void fun(char s[][N],int n)函数对s数组中的n个字符
      串进行如下处理，将各字符串中不符合下列组成规则的字
      符删除，直至剩余字符完全满足组成规则。
      字符串组成规则：由字母、数字、下划线组成，并且首字符
      不能是数字。
      程序中isalpha()函数是判断参数是否是字母字符，
      isdigit()函数是判断参数是否是数字字符。

例如：数组各字符串为"hPd$1"，"BnrE0"，"66_ks9d"，"*ws*_43"
      经处理后字符串为"hPd1"，"BnrE0"，"_ks9d"，"ws_43"
      

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/
#include<stdio.h>
#include<ctype.h>  
#define M 4
#define N 30
void fun(char str[][N],int n)
{
    int i,j,k,flag;
    for(j=0;j<n;j++)
    {
        i=0;
/***************FOUND****************/
        while(str[i]!='\0')
        {
            flag=0;
/***************FOUND****************/
            if(i==0&&(str[j][i]!='_'&&isalpha(str[j][i]))) 
                flag=1;
            else
                if(str[j][i]!='_'&&!isalpha(str[j][i])&&!isdigit(str[j][i]))
                    flag=1;
            if(flag==1)
            {
/***************FOUND****************/
                for(k=i;str[j][k+1];k++)
                    str[j][k]=str[j][k+1];
            }
            else
                i++;                
        }
    }
}

int main()
{
    char str[M][N]={"hPd$1","BnrE0","66_ks9d","*ws*_43"}; 
    int i;
    printf("处理前的数据: ");
    for(i=0;i<M;i++)
        printf("%-10s",str[i]);
    printf("\n");
    fun(str,M);
    printf("处理后的数据: ");
    for(i=0;i<M;i++)
        printf("%-10s",str[i]);
    printf("\n");
    return 0;
}