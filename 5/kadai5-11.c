#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p, const void *q);

int main(void)
{
    //comment 読み込み設定
    FILE *fp = fopen("Lesson5.txt", "r");
    if (fp == NULL)
    {
        printf("ないよ");
        return -1;
    }

    char str[512];
    int array[512];
    double ave = 0;
    int length = 0;

    //comment 読み込み
    fgets(str, sizeof(str), fp);
    char *p = strchr(str, (int)'\n');
    if (p != NULL)
        *p = '\0';

    //comment 分解一回目
    char *token = strtok(str, "\t");
    //comment 文字列をintに変換
    array[length] = atoi(token);
    //comment 配列に代入
    ave += array[length];
    length++;

    //comment 分解二回目以降
    while (token = strtok(NULL, "\t"))
    {
        //comment 文字列をintに変換
        array[length] = atoi(token);
        //comment 配列に代入
        ave += array[length];
        length++;
    }

    //comment ソート
    qsort(array, length, sizeof(int), cmp);

    //comment 書き出し
    printf("配列要素数%d\n", length);
    printf("平均(少数第三位四捨五入)%.2f\n", (ave / length + 1) + 0.005);
    printf("中央値%d\n", array[(length - 1) / 2]);

    return 0;
}

//comment ソートに使用する関数
int cmp(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}
