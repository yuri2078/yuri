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
void insertSort(int list[], int n)
{
	for (int i = 1; i < n; i++) {
		int k = i - 1;
		int x = list[i];
		while (k >= 0 && x < list[k]) {
			list[k + 1] = list[k];
			k--;
		}
		list[k + 1] = x;
		printList(list, n);
    }
}
void selectSort(int list[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[k]) {
				k = j;
            }
		}
		int temp = list[i];
		list[i] = list[k];
		list[k] = temp;
		printList(list, n);
    }
}
void bubbleSort(int list[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				flag = 1;
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
            }
		}
		if (flag == 0) {
			return;
        }
		printList(list, n);
		
	}
	
}
int main()
{
	int i, n;
	int a[MAX];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("insertSort:\n");
	insertSort(a, n);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("selectSort:\n");
	selectSort(a, n);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("bubbleSort:\n");
	bubbleSort(a, n);
	return 0;
}