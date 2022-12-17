#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
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
	}
}

void shellSort(int list[], int n, int dk[], int t)
{
	for (int i = 0; i < t; i++) {
		for (int j = dk[i]; j < n; j++) {
			int k = j - dk[i];
			int x = list[j];
			while (k >= 0 && x < list[k]) {
				list[k + dk[i]] = list[k];
				k = k - dk[i];
			}
			list[k + dk[i]] = x;
		}
	}
}
void shellInsert(int list[], int dk, int n)
{
	for (int j = dk; j < n; j++) {
		int k = j - dk;
		int x = list[j];
		while (k >= 0 && x < list[k]) {
			list[k + dk] = list[k];
			k = k - dk;
		}
		list[k + dk] = x;
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