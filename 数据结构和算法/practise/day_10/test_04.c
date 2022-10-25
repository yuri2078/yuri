#include <stdio.h>
#include <stdlib.h>


int my_gets(char* s)
{
	char ch;
	int len = 0;
	while ((scanf("%c",&ch) && ch != '\n')) {
		s[len++] = ch;
	}
	s[len] = 0;
	return len;
}

void stringCheck(char* s, char* t)
{
	char *temp_s, *temp_t;
	int flag = 0;
	while (*s || *t) {
		if (*s == *t || *s == '?') {
			s++;
			t++;
		} else if (*s == '*') {
		label:
			temp_s = s++;
			flag = 1;
			while (*t && *s != *t) {
				putchar(*t);
				t++;
			}
			if (!*t) {
				break;
			}
			temp_t = t + 1;
			puts("*匹配中");
		} else {
			if (flag) {
				s = temp_s;
				t = temp_t;
				goto label;
            }
			break;
		}
		// if(*s == '?' )
	}
	if (!*s && !*t) {
		printf("yes\n");
    }else {
		printf("no\n");
	}
}

int main(int argc, const char *argv[])
{
	char* s = (char*)calloc(200, sizeof(char));
	char* t = (char*)calloc(200, sizeof(char));
	my_gets(s);
	my_gets(t);

	stringCheck(s, t);
	free(s);
	free(t);
    return 0;
}