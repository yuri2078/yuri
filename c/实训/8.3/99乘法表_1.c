#include <stdio.h>

void printTable(void)
{
	int i = 1;
	//一共10行
	while(i < 10)
	{
		int j = 1;
		//每行i个数据
		while(j <= i)
		{
			//打印数据 
			printf("%d * %d = %-2d   ", j, i, i * j);
			j++;
		}
		i++;
		printf("\n");
	}
}

int main(void)
{
	printTable();
	return 0;
}
