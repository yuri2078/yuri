#include <stdio.h>

int fun_1(int deeth)
{
	if (deeth == 1) {
		return 4;
	}
	return 4 + 5 * (deeth - 1);
}

int fun_2(int deeth)
{
	if (deeth == 1) {
		return 2;
	}

	return 1;
}

void drawTree(int deeth)
{
	printf("                    ________________( A )________________\n");
	printf("                   /                                     \\\n");
	printf("          ______( B )______                       ______( C "
	       ")______\n");
	printf("         /                 \\                     /                "
	       " \\\n");
	printf("    __( D )__           __( E )__           __( F )__           "
	       "__( G )__ \n");
	printf("   /         \\         /         \\         /         \\         "
	       "/         \\\n");
	printf("( H )       ( I )   ( J )       ( K )   ( L )       ( M )   ( N )  "
	       "     ( O ) \n");
	for (int i = 0; i < fun_1(3); i++) {
		printf("-");
	}
	printf("$\n");
	for (int i = 0; i < fun_1(2); i++) {
		printf("-");
	}

	printf("$$\n");
	for (int i = 0; i < fun_1(1); i++) {
		printf("-");
	}
	printf("$$\n");
}

int main(void)
{
	drawTree(4);
	return 0;
}