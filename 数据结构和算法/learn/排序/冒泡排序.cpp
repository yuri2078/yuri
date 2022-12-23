#include <iostream>
#include <vector>
#include <yuri.h>

yuri::Yuri init; //读取数据类

// 冒泡排序： 两两对比 不断上浮较大或者较小的值
void bubbleSort(std::vector<int>& data)
{
	init.cleanLog();
	init.outData();
	const int n = data.size();
	int count = 1;
	// 因为每次上浮1个数，所以需要排n - 1次
	for (int i = 0; i < n - 1; i++) {
		// 每排好一个数，对比的次数就要减一 加上本就需要减一所以
		for (int j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
		init << "第 " << count++ << " 次排序\n";
		init.outData();
	}
}

int main()
{
	std::vector<int>& data = init.getData(true);
	bubbleSort(data);
	return 0;
}