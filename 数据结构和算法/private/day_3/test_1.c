#include <stdio.h>
#include <stdlib.h>
// 函数maxIncrease：计算销售额增幅
// 参数：s-销售额数组，n-销售额数组长度，n>1
// 返回值：销售额最大增幅
int maxIncrease(int s[], int n);
int main()
{
    int n,a[30],i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",maxIncrease(a,n));
    return 0;
}

int maxIncrease(int s[], int n)
{
    //请在此添加代码，实现函数maxIncrease
    int max = 0, sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(s[i] < s[i + 1]){
            sum += s[i + 1] - s[i];
        }
        else{
            sum = 0;
        }
        if (sum > max){
            max = sum;
        }
    }
    return max;
}
