#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp( const void *p, const void *q );

typedef struct {
	char id[10];
	int score;
}Record;

int main(void) {
	//comment 読み込み設定
	FILE *fp = fopen("Lesson6.txt", "r");
	if(fp == NULL){
		printf("ないよ");
		return -1;
	}

	char str[512];
	Record student[512];
	int length = 0;

	//comment 読み込み
	while(fgets(str, sizeof(str), fp) != NULL){
		char *p = strchr(str, (int)'\n');
		if(p != NULL) *p = '\0';

		//comment 文字列分解一回目
		char *token = strtok(str, "\t");
		//comment 学籍番号代入
		strcpy(student[length].id, token);

		//comment 文字列分解二回目
		token = strtok(NULL, "\t");
		//comment スコア代入
		student[length].score = atoi(token);

		length++;
	}
	//comment 代入終了

	//comment ソート
	qsort(student, length, sizeof(Record), cmp);

	//comment 書き出し
	int i;
	for(i = 0; i < length; i++){
		printf("%s\t%d\n", student[i].id, student[i].score);
	}

	return 0;
}

//comment ソートに使用する関数
int cmp( const void *p, const void *q ) {
    return ((Record*)p)->score - ((Record*)q)->score;
}

