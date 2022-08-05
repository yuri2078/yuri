#include <stdio.h>

void sort(int *num, int n)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(n < num[i])
		{
			int j;
			for(j = 9; j > i; j--){
				num[j] = num[j-1];
			}
			num[i] = n;
			break;
		}
	}
}

void printNum(int *num)
{
	int i = 0;
	while(i < 10)
	{
		printf("%d  ", num[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	int num[10] = {1,4,6,9,13,16,19,28,40,100};
	int n;
	printf("请输入需要插入的数:");
	scanf("%d", &n);
	printf("原来的数组： ");
	printNum(num);
	printf("插入数字后的数组:  ");
	sort(num, n);
	printNum(num);
	return 0;
}
