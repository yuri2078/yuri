#include <iostream>

int main(int argc, char **argv)
{
    int x = 88;
    (sizeof(int), [=](int x)
     { std::cout << x << std::endl; }()
     );

    return 0;
}