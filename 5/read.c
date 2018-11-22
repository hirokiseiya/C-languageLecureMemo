#include <stdio.h>
#include <string.h>
int main(void){
  FILE *fp = fopen("test.txt", "r");
  if (fp == NULL){
    printf("Can't create file.\n");
    return -1;
  }
  char str[100];
  while ((fgets(str, sizeof(str), fp)) != NULL){
    char *p = strchr(str, (int)'\n');
    if (p != NULL) *p = '\0';
    printf("%s\n", str);
  }
  fclose(fp);
  return 0;
}
