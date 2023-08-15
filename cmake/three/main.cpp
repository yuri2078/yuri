#include <iostream>
using std::cout;
using std::endl;

void sort(int *number, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(number[i] < number[j])
			{
				int temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}
}

int main()
{
	int number[10] = {11, 3, 45, 33, 2, 3, 55, 5, 8, 2};
	for(int i = 0; i < 10; i++)
	{
		cout << number[i] << "  ";
	}
	cout << endl;
	sort(number, 10);
	for(int i = 0; i < 10; i++){
		cout << number[i] << "  ";
	}
	cout << endl;
	return 0;
}
