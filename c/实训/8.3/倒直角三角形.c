#include <stdio.h>

void printTriangle(void)
{
	int i = 0;
	//打印10行数据
	while(i < 10)
	{
		int j = 0;
		//每行 10 - i个
		while(j < 10 - i)
		{
			printf("*");
			j++;
		}
		i++;
		printf("\n");
	}
}

int main(void)
{
	//调用函数打印
	printTriangle();
	return 0;
}
