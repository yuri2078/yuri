#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 66;
    int &y = x;
    cout << "sizeof y = " << sizeof(66) << endl;

    return 0;
}
