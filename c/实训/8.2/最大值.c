#include <stdio.h>

int main()
{
	float x, y, z, max;
	printf("请输入三个数:");
	scanf("%f%f%f",&x, &y, &z);
	if(x > y)
	{
		max = x;
	}
	else
	{
		max = y;
	}
	//比较max 和 z
	if(max < z)
	{
		max = z;
	}

	printf("他们中的最大值是:%f\n", max);
	return 0;
}

