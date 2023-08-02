#include <string.h>
#include <stdio.h>

void fun(char q[][20], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    j = 0;
    while (q[i][j]) {
      j++;
    }
    if (strcmp(q[i], q[i + 1]) > 0) {
      strcat(q[i], q[i + 1]);
    }
    strcpy(q[j], q[i]);
  }
}


int main() {
  char p[][20] = {"abc", "bdefg", "abcd123", "456ace", "#$%"};
  int i;
  fun(p, 5);
  for (i = 0; i < 5; i++) {
    puts(p[i]);
  }
  printf("%lu\n", strlen(p[i - 4]));

  return 0;
}
