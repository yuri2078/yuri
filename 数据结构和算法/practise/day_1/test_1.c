#include <stdio.h>
#include <stdlib.h>

int difference(int *number, int size)
{
  int min = __INT32_MAX__;
  for(int i = 0; i < size - 1; i++)
  {
    for(int j = i + 1;j < size; j++)
    {
      if(abs(number[i] - number[j]) < min){
        min = abs(number[i] - number[j]);
      }
    }
  }
  return min;
}

int main(void)
{
  int size;
  scanf("%d", &size);
  int *number = (int *)malloc(size * sizeof(int));
  for(int i = 0; i < size; i++){
    scanf("%d", number + i);
  }
  printf("%d\n",difference(number, size));

  return 0;
}
