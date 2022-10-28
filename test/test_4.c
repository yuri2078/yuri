#include <stdio.h>

typedef struct Date{
	int year;
	int month;
	int day;
}Date;

int main(int argc, const char *argv[])
{
	Date date = {3,.day = 5};

	printf("%d\n",date.month);
    return 0;
}