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
// 希尔排序: 插入是一个一个往前比较，希尔就是按照一定的序列比较
// 比如 5 3 1 : 从第六个开始逐个与隔五个比较也就是下标5 和 0比较
// 如果是第十一个个那么就是下标10 5 0 比较，然后按照普通插入法插入
// 接着按照下一个序列比较，直到 1 也就是说，最后一轮是普通插入排序
void shellSort(std::vector<int>& data)
{
	init.cleanLog();
	init.outData();
	const int n = data.size();
	// 设置序列
	for (int dk = n / 2; dk > 0; dk = dk / 2) {
		init << "当前序列为 --------- " << dk << " \n";
		// 从dk 位置开始进行插入（比较间隔 dk个）


		// 下面的代码和插入排序一模一样
		for (int i = dk; i < n; i++) {
			// 获取待比较的第一个下标
			int k = i - dk;
			// 保存待插入的数据
			int x = data[i];
			while (k >= 0 && x < data[k]) {
				data[k + dk] = data[k];
				// 向左移动 [序列] 个数据
				k = k - dk;
			}
			// 插入数据
			data[k + dk] = x;
			init << "第 " << i << " 次排序\n";
			init.outData();
		}
	}
}

int main()
{
	std::vector<int>& data = init.getData(true);
	shellSort(data);
	return 0;
}