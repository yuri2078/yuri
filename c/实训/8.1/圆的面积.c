#include <stdio.h>
#define PI 3.14159 //宏定义 圆周率

int main(void)
{
	float r; //半径
	printf("请输入圆的半径:");
	scanf("%f", &r); //接收数据
	if(r < 0)
	{
		printf("输入的半径小于 0");
	}
	else
	{
		printf("园的面积是: %f \n",r * r * PI);
	}
	return 0;
}
