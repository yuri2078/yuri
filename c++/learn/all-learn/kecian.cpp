#include <iostream>
using std::cout;
using std::ostream;


template <class T, class ...rest>
ostream & print(ostream &cout,const T &temp, const rest& ...w)
{
    cout << temp << "----print打印\n";
    print(cout, w...)
    return cout;
}


int main()
{
    print(cout, 66,77,77);
    return 0;
}