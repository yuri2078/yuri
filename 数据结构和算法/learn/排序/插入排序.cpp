#include <iostream>
#include <vector>
#include <yuri.h>

yuri::Yuri init; //读取数据类

// 插入排序： 将未排序的数插入进已经排序完的数
// 默认第一个数已经排序完毕，从第二个数开始插入
void insetrSort(std::vector<int>& data)
{
	init.cleanLog();
	init.outData();
	int count = 1;
	const int n = data.size();
	// 除了第一个数都需要插入
	for (int i = 1; i < n; i++) {
		// 保存前一个下标
		int k = i - 1;
		// 保存需要插入数据
		int x = data[i];
		// 如果没有到开头并且 需要插入的数小于这些数（升序）
		// 就不断将后面的数向后移动，直到找到插入位置
		int times = 0;
		while (k >= 0 && x < data[k]) {
			times++;
			data[k + 1] = data[k];
			k--;
		}
		// 找到合适的位置后插入
		data[k + 1] = x;
		init << "第 " << count++ << " 次排序, 待插入数据 " << x << " 比较次数 "
		     << times << "\n";
		init.outData();
	}
}

int main()
{
	std::vector<int>& data = init.getData(true);
	insetrSort(data);
	return 0;
}