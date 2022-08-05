#include <stdio.h>

void exchange(float *a, float *b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
}	


int main(void)
{
	float a,b;
	printf("请输入两个数:");
	scanf("%f%f", &a, &b);
	printf("交换前: a - %f, b - %f \n", a, b);
	exchange(&a, &b);
	printf("交换后: a - %f, b - %f \n", a, b);
	return 0;
}
