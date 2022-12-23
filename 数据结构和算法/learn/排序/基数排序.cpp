#include <yuri.h>

yuri::Yuri init; //读取数据类

// 获取最大元素的数据长度
int getMaxVal(std::vector<int>& data)
{
	int max_val = 0, size = data.size();
	for (int i = 1; i < size; i++) {
		if (data[i] > data[max_val]) {
			max_val = i;
        }
	}
	int res = 0, x = data[max_val];
	while (x) {
		res++;
		x = x / 10;
	}
	return res;
}

// 基数排序: 先按照个位排序然后按照个位排好的顺序按照十位排
// 知道排到最大的数的位数
void radix(std::vector<int>& data)
{
	init.cleanLog();
	init.outData();
	int n = getMaxVal(data), size = data.size(), rad = 1;
	std::vector<int> tmp(size); // 临时数组
	std::vector<int> count(10); // 计数数组
	// 一共有几位就循环几次
	for (int i = 0; i < n; i++) {
		init << "第 " << i + 1 << " 次排序当前基数 " << rad << " \n";
		// 将计数器重置
		for (int j = 0; j < 10; j++) {
			count[j] = 0;
		}

		// 获取每位元素都是几个数
		for (int j = 0; j < size; j++) {
			count[data[j] / rad % 10]++;
		}

		// 将计数器更改为每个元素应当存放的位置
		// 位数为9 的直接从末尾减去个数就是他应当开始存放的下标的数值
		count[9] = size - count[9];
		for (int j = 8; j >= 0; j--) {
			count[j] = count[j + 1] - count[j];
		}

		// 遍历每个元素在相应的位置存放起来就行了
		for (int j = 0; j < size; j++) {
			int k = data[j] / rad % 10;
			tmp[count[k]++] = data[j];
		}

		// 将更新好的临时数组里的值，复制到原来的数组
		for (int j = 0; j < size; j++) {
			data[j] = tmp[j];
		}
		// rad 不断乘10 用来求每一位的值
		rad = rad * 10;
		init.outData();
    }
}

int main()
{
	std::vector<int>& data = init.getData(true);
	radix(data);
	return 0;
}