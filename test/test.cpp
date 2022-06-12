#include <iostream>
int main()
{
   std::cout.fill('$');
   std::cout << std::cout.fill('*');
   return 0;
}