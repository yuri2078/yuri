#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void printList(int list[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d  ", list[i]);
	}
	printf("\n");
}

void heapAdjust(int list[], int u, int v)
{
	for (int k = v / 2 - 1; k >= 0; k--) {
		int parent = k;
		while (parent * 2 + 1 < v) {
			int lchild = 2 * parent + 1;
			int rchild = 2 * parent + 2;
			int next = 0;
			if (rchild >= v || list[lchild] > list[rchild]) {
				next = lchild;
			} else {
				next = rchild;
			}

			if (list[parent] < list[next]) {
				int temp = list[parent];
				list[parent] = list[next];
				list[next] = temp;
				parent = next;
			} else {
				break;
            }
        }
	}
	printList(list, u);
	int temp = list[0];
	list[0] = list[v - 1];
	list[v - 1] = temp;
}

void heapSort(int list[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		heapAdjust(list, n, n - i);
	}
	printList(list, n);
}

int main()
{
	int i, n;
	int a[MAX];
	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		printf("heapSort:\n");
		heapSort(a, n);
	}
	return 0;
}