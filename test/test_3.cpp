#include <iostream>

template <typename T>
int add(T a, T b)
{
	return a + b;
}

template <typename T,typename... Args>
int add(T a, T b, Args... args)
{
	return add(a + b, args...);
}

bool result(char ch, bool b_1, bool b_2)
{
    switch (ch) {
    case '|':
        return b_1 || b_2;
    case '&':
        return b_1 && b_2;
    }
    return true;
}

template <class... Args>
bool result(char ch, bool b_1, bool b_2, Args... args)
{
    switch (ch) {
    case '|':
        return result(ch, b_1 || b_2, args...);
    case '&':
        return result(ch, b_1 && b_2, args...);
	}
	return true;
}



int main(int argc, const char **argv)
{
	std::cout << add(4, 5, 6, 7, 8) << std::endl;
	std::cout << result('&',true,true,false,true) << std::endl;
    return 0;
}