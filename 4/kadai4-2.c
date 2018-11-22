#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  int i;
  while (1) {
    printf("Sentence: ");
    char src[256];
    fgets(src, sizeof(src), stdin);
    src[strlen(src) - 1] = '\0';

    int count = 0;
    char alphabets[26] = {
      0,
    };
    for (i = 0; i < strlen(src); i++)
    {
      if (!isalpha(src[i]))
      continue;
      if ((src[i]>= 'A') && (src[i]<= 'Z'))
      continue;
      alphabets[src[i] - 'a']++;
      count++;
    }

    int wcnt = 0;
    char *p = strtok(src, " ");
    wcnt++;
    while (p = strtok(NULL, " "))
    {
      wcnt++;
    }
    printf("Small letters = %d\n", count);
    printf("Words = %d\n", wcnt);
  }

  return 0;
}
