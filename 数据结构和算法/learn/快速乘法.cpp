#include <cstdint>
#include <iostream>

int results(int x, int y)
{
	int ans = 0;
	while (y) {
		if (y & 1) {
			if (x < INT32_MIN - ans) {
				std::cout << "x -> " << x << " ans -> " << INT32_MIN - ans
				          << " 相减溢出\n";
				return 1;
			}
			ans += x;
		}
		y = y >> 1;
		if (y && x < INT32_MIN >> 1) {
			std::cout << "移位溢出\n";
			return 1;
		}
		x = x << 1;
	}

	return ans;
}

int divide(int dividend, int divisor)
	{
	    bool flag = false;
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
			flag = true;
		}
	    std::cout << "flag -> " << flag << std::endl;
		return flag;
	}

int main()
{
	// std::cout << results(-1423, 1921942) << std::endl;
	divide(-10, 10);
	return 0;
}