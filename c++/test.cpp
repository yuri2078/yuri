#include <iostream>
using namespace std;

bool fun(int x)
{
	if (x <= 2) {
		return true;
	}

	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
        }
	}
	return true;
}

template <typename T, typename ...Args>
clock_t used_time(T cp, Args&& ...args)
{
    clock_t start, end;
    start = clock();
    cp(args...);
    end = clock();
    return end - start;
}


int main()
{
    cout << used_time(fun, 23232232111) << "  ms\n";
    return 0;
}