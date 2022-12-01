#include <stdio.h>
#include <math.h>

int gys(int x)
{
	if (x <= 2) {
		return 1;
	}
	int flag = 1;
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			flag = 0;
			break;
        }
	}
	return flag;
}

int main(void)
{
	int n;
	double sum = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		sum += 1.0 / (i * i);
	}
	printf("%lf\n", sqrt(6 * sum));
	
    return 0;
}