#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	for (int i = -2; i <= 2; i++) {
		for (int j = 0; j < abs(i); j++) {
			printf(" ");
		}
		int j;
		for (j = 0; j < 3 - abs(i); j++) {
			printf("%c",'A' + j);
		}
		
		j = j - 2;
		while(j >= 0) {
			printf("%c", 'A' + j);
			j--;
		}
		printf("\n");
	}
	return 0;
}