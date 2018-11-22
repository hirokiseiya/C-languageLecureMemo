#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    /////////////入力関係
    printf("入力してください\n");
    char src[256];                  //入力を格納
    fgets(src, sizeof(src), stdin); //読み込み
    src[strlen(src) - 1] = '\0';    //改行文字を終端文字に変換

    printf("Input:%s\n", src); //インプットを出力

    /////////////小文字に変換
    int i;
    for (i = 0; i < strlen(src); i++)
    {
        src[i] = tolower(src[i]); //小文字に変換
    }

    printf("小文字に変換しました\n");

    ///////////アルファベットカウント
    char alphabets[26] = {
        0,
    };
    for (int i = 0; i < strlen(src); i++)
    {
        if (!isalpha(src[i]))
            continue;
        alphabets[src[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        int max_index = 0;
        int max_count = 0;
        for (int j = 0; j < 26; j++)
        {
            if (alphabets[j] > max_count)
            {
                max_index = j;
                max_count = alphabets[j];
            }
        }
        if (max_count < 1)
            break;
        printf("%c(%c): %d\n", (char)max_index + 'a', toupper((char)max_index + 'a'),
               max_count);
        alphabets[max_index] = 0;
        max_index = 0;
        max_count = 0;
    }

    /////////語数を数える
    int wcnt = 0;
    char *p = strtok(src, ",. ");
    wcnt++;
    while (p = strtok(NULL, ",. "))
    {
        wcnt++;
    }
    printf("Word count:%d\n", wcnt); //語数を表示

    return 0;
}