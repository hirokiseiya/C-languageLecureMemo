#include <stdio.h>
int main(void){
  FILE *fp = fopen("test.txt", "w");
  if (fp == NULL){
    printf("Can't create file.\n");
    return -1;
  }
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int size = sizeof(array) / sizeof(array[0]);
  int i;
  for (i = 0; i < size; i++){
    fprintf(fp, "%d\n", array[i]);
  }
  fclose(fp);
  return 0;
}
