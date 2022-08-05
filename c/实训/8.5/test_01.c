#include <stdio.h>

int matrix(int num[3][3])
{
	int i, sum = 0;
	for(i = 0; i < 3; i++){
		sum = sum  + num[i][i] + num[i][2-i];
	}
	return sum;
}


int main(void)
{
	int num[3][3] = {
		{12, 3, 5},
		{6, 8, 17},
		{1, 9, 10}};
	printf("对角线之和是: %d\n",matrix(num));
	return 0;
}
