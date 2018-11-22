#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{

  char str[256];
  int sum, index, num;
  while (1)
  {
    sum = 0;
    index = 0;
    num = 0;
    printf("N = ");
    fgets(str, 256, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmp(str, "Q") == 0)
    {
      puts("BYE");
      return 0;
    }
    if (is_number(str) == 0)
    {
      printf("IOERROR: Input only numbers.\n");
      continue;
    }
    num = atoi(str);
    double ans = (sin(M_PI / num)) * num;
    printf("L: %.2f\n", ans);
  }
}

int is_number(char *token)
{
  int digit = 1;
  int i;
  for (i = 0; i < strlen(token); i++)
  {
    if (isdigit(token[i]) == 0)
    {
      digit = 0;
      break;
    }
  }
  return digit;
}
