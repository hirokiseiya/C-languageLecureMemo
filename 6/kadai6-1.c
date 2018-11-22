#include <stdio.h>

typedef struct {
    char id[10];
    int score;
} Record;

int main(void) {
    FILE *fp = fopen("Lesson6.txt", "r");
    if (fp == NULL) {
        printf("cannot open file\n");
        return -1;
    }

    Record records[100];
    int size = 0;
    char str[20];
    while (fgets(str, sizeof(str), fp) != NULL) {
        char *p = strchr(str, (int)'\n');
        if (p != NULL)
            *p = '\0';
        // printf("%s\n", str);

        char *token;
        token = strtok(str, "\t");
        strcpy(records[size].id, token);
        token = strtok(NULL, "\t");
        records[size].score = atoi(token);
        size++;
    }
    char str2[10];

    while(1) {
        printf("ID: ");
        scanf("%s", str2);
        for (int i = 0; i < size; i++) {
            if (!strcmp(records[i].id, str2)) {
                printf("Score: %d\n", records[i].score);
                break;
            }
        }
    }

    fclose(fp);
    return 0;
}