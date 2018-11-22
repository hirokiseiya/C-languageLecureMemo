#include <stdio.h>
#include <string.h>

int cmp(const void *p, const void *q);

int main(void){
  FILE *fp = fopen("Lesson5.txt", "r");
  if (fp == NULL){
    printf("Can't open file.\n");
    return -1;
  }
  char str[255];
  int num[255];
  int count = 0;
  double sum = 0;
  double med;

  // ファイル読み取り
  fgets(str, sizeof(str), fp);
  char *p = strchr(str, (int)'\n');
  if(p != NULL)
    *p = '\0';

  // 1回目
  char *token = strtok(str, "\t");
  num[count] = atoi(token);
  sum += num[count];
  count++;

  // 2回目
  while (token = strtok(NULL, "\t")) {
    num[count] = atoi(token);
    sum += num[count];
    count++;
  }
  // if (token != NULL) *p = '\0';
  fclose(fp);

  qsort(num, count, sizeof(int), cmp);

   if(count % 2 == 0) {
     med = (double)(num[count/2]+num[(count/2)+1])/2;
   } else {
        med = num[count / 2];
   }

   printf("平均: %.3lf\n", (sum/count));
   printf("中央値: %.3lf\n", med);



  return 0;
}

int cmp(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}
