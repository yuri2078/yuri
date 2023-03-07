/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：int find(char a[],char b[],int c[])统计字符串a中出
      现字符串b的次数，并将字符串b每次在字符串a中出现的起
      始下标依次保存在数组c中。

例如：若字符串a为"You are a P.R.C citizen or other P.R.C person"
      字符串b为"P.R.C" ，字符串b在a中出现2次，起始下标依
      次为10，33。若字符串a为"bcde aeeeq mneec",字符串b为
      "ee" ，字符串b在a中出现3次，起始下标依次为6，7，13。

      请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
int find(char a[],char b[],int c[])
{
    int i,j,n=0; 
    i=0;
    while(a[i])
    {
        j=0;
        while(a[i]==b[j]&&a[i]&&b[j])
        {
            i++;j++;
        }
        if(b[j]=='\0')
        {
/*******************FOUND*******************/
            c[n]=i;
            n++;
        }
/*******************FOUND*******************/
        i=j;
    }
/*******************FOUND*******************/
    return n-1;
}

int main()
{
    char a[80]="You are a P.R.C citizen or other P.R.C person";
    char b[10]="P.R.C";
    int  c[80];
    int i,n;
    printf("String a:\n");
    puts(a);
    printf("Substring b:\n");
    puts(b);
    n=find(a,b,c);
    if(n)
    {
        printf("\nAfter counting:\n%d times\n",n);
        printf("Location:\n");
        for(i=0;i<n;i++) printf("%d\t",c[i]);
        printf("\n");
    }
    else
        printf("\nCan not find substring.\n");
    return 0;
}