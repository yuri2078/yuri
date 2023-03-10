#include <iostream>
#include <vector>

void createMartx(int start, int k)
{
	std::vector<std::vector<int>> martix(k, std::vector<int>(k));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			martix[j][i] = start++;
		}

		for (int j = i - 1; j >= 0; j--) {
			martix[i][j] = start++;
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			std::cout.width(4);
			std::cout << martix[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	int start, k;
	std::cin >> start >> k;
	createMartx(start, k);
	return 0;
}