#include <iostream>
#include <vector>
#include <yuri.h>

yuri::Yuri init; //读取数据类


// 选择排序： 每次选择一个数放入正确的位置
void chooseSort(std::vector<int>& data)
{
	init.cleanLog();
	init.outData();
	const int n = data.size();
	// 因为每次选择1个数，所以需要排n - 1次
	for (int i = 0; i < n - 1; i++) {
		int max_val = i;
		for (int j = i + 1; j < n; j++) {
			if (data[max_val] > data[j]) {
				max_val = j;
            }
		}
		// 将找到的数与正确的位置进行交换
		int temp = data[i];
		data[i] = data[max_val];
		data[max_val] = temp;
		init << "第 " << i + 1 << " 次排序\n";
		init.outData();
    }
}

int main()
{
	std::vector<int>& data = init.getData(true);
	chooseSort(data);
	return 0;
}