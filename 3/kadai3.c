#include <stdio.h>
#include <string.h>

int main(void)
{
 int numberOfWord = 0; //単語数
 int wordCount = 0; //文字数

 char word[256];

 printf("文字入力 :");
 scanf("%[^\n]", word);

 wordCount = strlen(word);

 char *token = strtok(word, " ");
 wordCount = wordCount - 1;
 numberOfWord = numberOfWord + 1;

 while(token = strtok(NULL, " ")){
  wordCount = wordCount - 1;
  numberOfWord = numberOfWord + 1;
 }

 printf("単語数 : %d\n", numberOfWord);
 printf("文字数 : %d\n", wordCount + 1);

    return 0;
}