#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int n = 0;
void printList(int list[])
{
	for (int i = 0; i < n; i++) {
		printf("%d ",list[i]);
	}
	printf("\n");
}

int Partition(int list[], int left, int right)
{
	int key = list[left];
	int flag = right;
    while (left != right) {
		if (key < list[flag]) {
			list[right] = list[flag];
			flag = --right;
		} else {
			list[left] = list[flag];
			flag = ++left;
        }
	}
	printf("pivotkey=%d:\n", key);
	list[left] = key;
	printList(list);
	return left;
}

void quickSort(int list[], int low, int high)
{
	if (low < high) {
		int k = Partition(list, low, high);
		quickSort(list, low, k - 1);
		quickSort(list, k + 1, high);
    }
}

int main()
{
	scanf("%d", &n);
	int list[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", list + i);
	}
	quickSort(list, 0, n - 1);
	return 0;
}