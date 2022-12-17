#include  <stdio.h>
#include  <stdlib.h>
#define  MAX  1000

void  bubbleSort(int  list[],  int  n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				int t = list[j];
				list[j] = list[j + 1];
				list[j + 1] = t;
			}
		}
	}
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
	list[left] = key;
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


void printList(int list[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ",list[i]);
	}
	printf("\n");
}

int  main()
{
	int n = 0;
	scanf("%d", &n);
	int list_bubble[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", list_bubble + i);
	}
	bubbleSort(list_bubble, n);
	printf("bubbleSort:\n");
	printList(list_bubble, n);

	scanf("%d", &n);
	int list_quick[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", list_quick + i);
	}
	quickSort(list_quick, 0, n - 1);
	printf("quickSort:\n");
	printList(list_quick, n);
	return 0;
}