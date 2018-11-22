#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[255];
  char country[255];
  double shortP;
  double freeP;
  double total;
} Record;

int main(void) {
  FILE *fp = fopen("Lesson08.txt", "r");
  if (fp == NULL) {
    printf("cannot open file\n");
    return -1;
  }

  Record records[100];
  int size = 0;
  char str[255];
  int flag;
  while (fgets(str, sizeof(str), fp) != NULL) {
    char *p = strchr(str, (int)'\n');
    if (p != NULL)
    *p = '\0';
    // printf("%s\n", str);
    // 1行目はスキップする
    if (!flag) {
      flag = !flag;
      continue;
    }

    char *token;
    token = strtok(str, ",");
    strcpy(records[size].name, token);
    token = strtok(NULL, ",");
    strcpy(records[size].country, token);
    token = strtok(NULL, ",");
    records[size].shortP = atof(token);
    token = strtok(NULL, ",");
    records[size].freeP = atof(token);
    records[size].total = records[size].shortP + records[size].freeP;
    // printf("%lf %lf\n",records[size].shortP,records[size].total );
    size++;
  }

  double tmp;
  char tmp2[255];
  int i,j;

  for (i = 0; i < size; i++) {
    for (j = i; j < size; j++) {
      if ( records[i].total < records[j].total) {
        tmp = records[i].total;
        strcpy(tmp2, records[i].name);
        records[i].total = records[j].total;
        strcpy(records[i].name, records[j].name);
        records[j].total = tmp;
        strcpy(records[j].name, tmp2);
      }
    }
  }

  for (i = 0; i < size; i++)
  {
    printf("%s %.2lf\n", records[i].name, records[i].total);
  }

  fclose(fp);
  return 0;
}
