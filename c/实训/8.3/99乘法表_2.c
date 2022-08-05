#include <stdio.h>

void printTable(void)
{
	int i = 1;
	//打印第一行
	printf("%-3c|",'X');
	while(i < 11)
	{
		printf("%4d",i);
		i++;
	}
	//打印具体内容
	i = 1;
	while(i <= 10)
	{
		int j = 1;
		printf("\n");
		printf("%-3d|",i);
		while(j <= 10)
		{
			printf("%4d", i * j);
			j++;
		}
		i++;
	}
	printf("\n");
}

int main(void)
{
	printTable();
	return 0;
}
