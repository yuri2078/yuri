#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void insertSort(int list[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++) {
		list[0] = list[i];
		j = i - 1;
		while (j > 0 && list[0] < list[j]) {
			list[j + 1] = list[j];
			--j;
		}
		list[j + 1] = list[0];
	}
}
int shellInert(int list[], int dk, int n);

void shellSort(int list[], int n, int dk[], int t)
{
	int i, k;
	for (k = 0; k < t; k++)
		shellInsert(list, dk[k], n);
}
void shellInsert(int list[], int dk, int n)
{
	int i, j;
	for (i = dk + 1; i <= n; ++i)
		if (list[i] < list[i - dk]) {
			list[0] = list[i];
			for (j = i - dk; j > 0 && list[0] < list[j]; j -= dk)
				list[j + dk] = list[j];
			list[j + dk] = list[0];
		}
}
void printList(int list[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d  ", list[i]);
	}
	printf("\n");
}
int main()
{
	int i, n;
	int a[MAX];
	int dk[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("insertSort:\n");
	insertSort(a, n);
	printList(a, n);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("shellSort:\n");
	dk[0] = 5;
	dk[1] = 3;
	dk[2] = 1;
	shellSort(a, n, dk, 3);
	printList(a, n);
	return 0;
}