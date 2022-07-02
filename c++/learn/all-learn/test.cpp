#include <iostream>
#include <string>
using std::cout;
using std::string;

class Test
{
public:
    Test & operator<<(const string &temp)
    {
        cout << temp << " ";
        return *this;
    }
};

int main(int argc, char **argv)
{
    Test() << "牛逼";
    return 0;
}