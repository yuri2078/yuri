#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

void dtos(int x)
{
	char temp[20];
	int i = 0;
	while(x)
	{
		temp[i] = x % 10 + 48;
		i++;
		x = x / 10;
	}
	temp[i] = 0;
	cout << "temp == " << temp << endl;
}


int main()
{
	char str[100];
	int x = 666;
	sprintf(str,"%d",x);
	cout << str << endl;
	
	dtos(4545);
	
	return 0;
}