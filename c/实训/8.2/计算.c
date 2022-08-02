#include <stdio.h>

int main(void)
{
	float x, y;
	char c = 32;
	printf("请输入两个操作数和运算符:");
	scanf("%f", &x);
	//循环判断是否是空格，防止输入出现空格 运算符无效
	while(c == 32)
	{
		scanf("%c", &c);
	}
	scanf("%f", &y);

	float temp = 0;
	//通过switch计算结果
	switch(c)
	{
		case '+' : temp = x + y; break;
		case '-' : temp = x - y; break;
		case '*' : temp = x * y; break;
		case '/' : temp = x / y; break;
		case '%' : temp = (int)x % (int)y; break;
		default : printf("输入错误\n");
	}
	//打印结果
	printf("%f %c %f = %f\n", x, c, y, temp);
	return 0;
}
