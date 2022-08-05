#include <stdio.h>
#include <stdlib.h>

void printDiamond(int n, char c)
{
	//是偶数则加一
	n%2 ? n : n++;
	int i;
	for(i = - n/2; i <= n/2; i++)
	{
		int j;
		//打印空格
		for(j = 0; j < 2 * abs(i); j++)
		{
			printf(" ");
		}
		//打印符号
		for(j = 0; j < n - 2 * abs(i); j++)
		{
			printf("%c",c);
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	char c = 0;
	printf("请输入最大个数:");
	scanf("%d",&n);
	//接收多余的回车字符
	printf("请输入图案:");
	do
	{
		c = getchar();
	}while(c == '\n');

	printDiamond(n, c);
	return 0;
}
