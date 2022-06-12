#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	std::vector<int>::iterator begin = v.begin();
	while(begin != v.end())
	{
		
		if(*begin == 5)
		{
			v.erase(begin - 1 );
			// begin++;
			continue;
		}
		
		begin++;
	}
	std::cout << "\n";
	begin = v.begin();
	while(begin != v.end())
	{

		std::cout << *begin << " ";
		begin++;
	}
	std::cout << "\n\n\n\n" << v.back();
	return 0;
}