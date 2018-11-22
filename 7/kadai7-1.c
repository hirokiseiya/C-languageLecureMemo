#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[10];
    int score;
} Record;

void sort(Record *a, Record *b)
{
    if (a->score > b->score)
    {
        char temp[10];
        strcpy(temp, a->id);
        strcpy(a->id, b->id);
        strcpy(b->id, temp);
        int x = a->score;
        a->score = b->score;
        b->score = x;
    }
}

void BubSort(Record *x, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            sort(&x[j], &x[j + 1]);
        }
    }
}

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

        char *token;
        token = strtok(str, "\t");
        strcpy(records[size].id, token);
        token = strtok(NULL, "\t");
        records[size].score = atoi(token);
        size++;
    }
    BubSort(records, size);

    // int tmp;
    // char tmp2[10];

    // for (int i = 0; i < size; i++) {
    //     for (int j = i; j < size; j++) {
    //         if ( records[i].score > records[j].score) {
    //             tmp = records[i].score;
    //             strcpy(tmp2, records[i].id);
    //             records[i].score = records[j].score;
    //             strcpy(records[i].id, records[j].id);
    //             records[j].score = tmp;
    //             strcpy(records[j].id, tmp2);
    //         }
    //     }
    // }

        for (int i = 0; i < size; i++)
        {
            printf("%s: %d\n", records[i].id, records[i].score);
        }

    fclose(fp);
    return 0;
}