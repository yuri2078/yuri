/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：有一个两位正整数，它的3次方和4次方分别是4位数和6位
      数，这十位数字恰好由数字0-9 构成。求这个两位数。

请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
int check(int n){
    long four,six;
    int i,a[10]={0};
    four=(long)n*n*n;
/*******************FOUND*******************/
    six=four*four;
/*******************FOUND*******************/
    while(four)
    {
        if(four)
        {
            a[four%10]+=1;
            four/=10;
        }
        a[six%10]+=1;
        six/=10;
    }
    for(i=0;i<10;i++)
/*******************FOUND*******************/
        if(a[i]!=0)
            return 0;
    return 1;
}
int main(){
    int n;
    for(n=11;n<100;n++)
        if(check(n)==1)
            printf("%d\n",n);
    return 0;
}