#include <stdio.h>

int sum(int x)
{
  int s = 0;
  while(x)
  {
    s += x %10;
    x = x / 10;
  }
  return s;
}

int main(void)
{
  int x;
  scanf("%d", &x);
  printf("%d\n", sum(x));
  return 0;
}
