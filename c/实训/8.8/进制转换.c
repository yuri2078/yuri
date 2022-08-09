#include <stdio.h>

//递归调用函数实现转换
void decimalToBinary(int x)
{
	if(x > 0)
	{
		decimalToBinary(x / 2);
		printf("%d",x % 2);
	}
}


void decimalToOctal(int x)
{
	if(x > 0)
	{
		decimalToOctal(x / 8);
		printf("%d",x % 8);
	}
}

void decimalToHex(int x)
{
	if(x > 0)
	{
		decimalToHex(x / 16);
		if(x % 16 > 9){
			printf("%c", x % 16 + 55);
		}
		else{
			printf("%d", x % 16);
		}
	}
}

int main(void)
{
	printf("1. 十进制转二进制\n2. 十进制转八进制\n3. 十进制转16进制\n请选择你的目的:");
	int flag, x;
	scanf("%d", &flag);
	printf("请输入一个十进制操作数:");
	scanf("%d", &x);
	if(x < 0)
	{
		printf("-");
		x = -x;
	}
	switch(flag)
	{
		case 1 : decimalToBinary(x); break;
		case 2 : decimalToOctal(x); break;
		case 3 : decimalToHex(x); break;
		default : printf("指令错误捏\n");
	}
	printf("\n");
	return 0;
}
