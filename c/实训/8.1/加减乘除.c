#include <stdio.h>

int main(void)
{
	double x, y;
	printf("请输入两个操作数:");
	scanf("%lf%lf", &x, &y);
	printf("%lf + %lf = %lf\n", x, y, x + y);
	printf("%lf - %lf = %lf\n", x, y, x - y);
	printf("%lf * %lf = %lf\n", x, y, x * y);
	printf("%lf / %lf = %lf\n", x, y, x / y);
	printf("%lf %% %lf = %d\n", x, y, (int)x % (int)y);
	return 0;
}
