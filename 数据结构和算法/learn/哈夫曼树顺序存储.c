#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct huffmanTree {
	char val;
	int weight;
	int parent;
	int left;
	int right;
} huffmanTree;

// 获取最小的两个权重的下标，赋值给 min_1 和 min_2
void getMinVal(huffmanTree* huffmantree, int n, int* min_1, int* min_2)
{
	int min1 = INT32_MAX, min2 = INT32_MAX; // 将他们设置为最大整形
	for (int i = 0; i < n; i++) {
		// 当出现比min1 还小的值 且 他的父节点为 -1 时
		if (huffmantree[i].weight < min1 && huffmantree[i].parent == -1) {
			// 当最小值不是第一个的时候 需要将旧的最小值给 第二小的值
			if (i) {
				*min_2 = *min_1;
				min2 = min1;
			}
			// 更新最小值的信息
			*min_1 = i;
			min1 = huffmantree[i].weight;

			// 当他不是最小值，但是右比第二小的值小的时候，需要更新第二小的值
		} else if (huffmantree[i].weight < min2 && huffmantree[i].parent == -1) {
			*min_2 = i;
			min2= huffmantree[i].weight;
        }
    }
}

// 生成哈夫曼树
void createHuffTree(huffmanTree* huffmantree, int n)
{
	// 初始化哈夫曼树 的信息
	for (int i = 0; i < n; i++) {
		scanf("%c,%d", &huffmantree[i].val, &huffmantree[i].weight);
        getchar();   
		huffmantree[i].parent = -1; // 将所有父节点设置为 -1
		huffmantree[i].left = -1;
		huffmantree[i].right = -1;
	}

	int min_1, min_2; // 用来存放第一小和第二小的下标
	for (int i = 0; i < n - 1; i++) {
		// 获取权重最小的两个
		// 遍历次数 为 n + i 因为每次添加都会多一个新的节点
		getMinVal(huffmantree, n + i, &min_1, &min_2); 
		huffmantree[min_1].parent = n + i; // 设置第一小的父节点
		huffmantree[min_2].parent = n + i; // 设置第二小的父节点
		huffmantree[n + i].weight = huffmantree[min_1].weight + huffmantree[min_2].weight; // 设置新 节点权重为两个小的权重和
		huffmantree[n + i].val = '0'; // 设置无关节点 val 为 '0'
		huffmantree[n + i].left = min_1; // 设置节点 左孩子为最小权重的下标
		huffmantree[n + i].right = min_2; // 设置节点 右孩子为第二小权重的下标
		huffmantree[n + i].parent = -1; // 设置他的父节点为 -1
    }
}

// 生成哈夫曼编码
void createHuffmanCode(huffmanTree* huffmantree, int n)
{
	printf("HuffCode:\n");
	int code[100]; // 新建数组用来存放哈佛满编码
	for (int i = 0; i < n; i++) { // 一共有 n 个数据需要生成
		int size = 0; // 先设置初始大小为 0
		int k = i; // 设置初始坐标为 i
		while (huffmantree[k].parent != -1) { // 当循环到根节点时退出循环
			int parent = huffmantree[k].parent; // 获取他的父节点坐标
			if (huffmantree[parent].left == k) { // 看看当前节点是父节点的左孩子还是右孩子
				code[size++] = 0; // 左孩子添加 0
			} else {
				code[size++] = 1; // 右孩子添加 1
			}
			k = parent; // 更新当前节点
		}
		printf("%c:",huffmantree[i].val);
		for (int j = size - 1; j >= 0; j--) { // 因为是倒序存储，所以需要倒序打印
			printf("%d",code[j]);
		}
		printf("\n");
    }
}

void printHuffTable(huffmanTree* huffmantree, int n)
{
	printf("HuffTable:\n");
	for (int i = 0; i < 2 * n - 1; i++) {
		printf("%c %d %d %d %d\n",huffmantree[i].val, huffmantree[i].weight,huffmantree[i].parent, huffmantree[i].left, huffmantree[i].right);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	getchar();
	huffmanTree huffmantree[2 * n - 1]; // n个数据 一共需要n + ( n - 1 )个空间来存储
	createHuffTree(huffmantree, n);
	printHuffTable(huffmantree, n);
	createHuffmanCode(huffmantree, n);
    return 0;
}