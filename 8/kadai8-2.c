#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[255];
    char country[255];
    double shortP;
    double freeP;
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
        // printf("%lf %lf\n",records[size].shortP,records[size].freeP );
        size++;
    }
    char str2[255];

    printf("Country: ");
    scanf("%s", str2);
    int i;
    for (i = 0; i < size; i++) {
        if (!strcmp(records[i].country, str2)) {
            printf("%s\n", records[i].name);
        }
    }

    fclose(fp);
    return 0;
}
