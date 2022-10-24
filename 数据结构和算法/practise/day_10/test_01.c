#include <stdlib.h>
#include <stdio.h>

int my_gets(char* s)
{
	char ch;
	int i;
	for (i = 0;( ch = getchar() )!= '\n'; i++) {
        s[i] = ch;
	}
	s[i] = 0;
	return i;
}

int indexKMP(char* s, char* t, int *next)
{
	int i = 0, j = 0;
	while (s[i] && j < t[j]) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		}else {
            j = next[j];
        }
	}
	if (!t[j]) {
		int k = i - j;
		while (s[k + j]) {
			s[k] = s[k + j];
			k++;
		}
		s[k] = 0;
		indexKMP(s, t, next);
		return i - j + 1;
    }
	return 0;
}
//求取模式串next值
void getNext(char* t, int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (t[i]) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
            j = next[j];
        }
	}
}

int main(int argc, const char *argv[])
{
	char* s = (char*)calloc(200, sizeof(char));
	char* t = (char*)calloc(200, sizeof(char));

    //输入数据
	my_gets(s);
	int len = my_gets(t);
	int* next = (int*)calloc(len, sizeof(int));
	getNext(t, next);
	// for (int i = 0; i < len; i++) {
	//     printf("%d ",next[i]);
	// }
	// printf("\n");
	// printf("kmp : %d\n", indexKMP(s, t, next));
	indexKMP(s, t, next);

	puts(s);
    return 0;
}