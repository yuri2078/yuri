/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下面的程序中，函数fun的功能是:从低位开始取出长整型
      变量s中奇数位上的数，依次构成一个新数放在t中。高位
      仍在高位,低位仍在低位。例如，当s中的数为：654321时，
      t中的数为：531。

请改正程序中的错误，使它能得出正确的结果。

---------------------------------------------------------
注意：不得增行或删行，也不得更改程序的结构。
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/***********FOUND***********/ 
void fun (long);
long getnumber();
void main()
{
    long s,t;
    srand((unsigned)time(NULL));    //初始化随机数时间序列
    s=getnumber();                //随机获取一个长整数
    t=fun(s);
    printf("The result is: %ld,%ld\n", s,t);
}
long fun (long s)
{
    long t=0;
/***********FOUND***********/ 
    long step=10;
    while (s > 0)
    {
        t=t+s%10*step;
        step=10*step;
/***********FOUND***********/ 
        s = s/10;
    }
    return t;
}
long getnumber()
{
    int i,k;
    long n=0;
    k=rand()%4+5;
    for(i=0;i<k;i++)
    {
        while(n==0)
            n=10*n+rand()%10;
        n=10*n+rand()%10;
    }
    return n;
}