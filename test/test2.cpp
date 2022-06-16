#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

char * fun1(const char *w)
{
    char * str = new char[strlen(w)];
    strcpy(str, w);
    return str;
}


int main()
{
    char * a = fun1("wocao");
    cout << *a << endl;
    return 0;
}