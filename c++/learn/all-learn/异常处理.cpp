#include <iostream>
#include <string>
#include <vector>

class Yuri
{
private:
	std::string name;
	
public:
	Yuri() = default;
	Yuri(const std::string& name) noexcept(true)
	{
		this->name = name;
		std::cout << "init is ok!\n";
	}
	
};
int main(int argc, const char *argv[])
{
	std::vector<int> vec;
	std::cout << std::endl;
    return 0;
}