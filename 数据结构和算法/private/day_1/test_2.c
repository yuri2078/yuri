#include <stdio.h>
#include <ctype.h>

void countString()
{
  int alpla_len = 0, space_len = 0;
  char ch = '\0';
  while(ch != '\n')
  {
    if(isalpha(ch)){
      alpla_len++;
    }
    else if(ch == ' '){
      space_len++;
    }
    ch = getchar();
  }
  printf("%d %d\n", alpla_len, space_len);
}

int main(void)
{
  countString();
  return 0;
}
