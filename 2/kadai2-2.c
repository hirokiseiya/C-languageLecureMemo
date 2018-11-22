#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{

    char str[256];
    int sum, index, num;
    while (1)
    {
        sum = 0;
        index = 0;
        num = 0;
        printf("Input numbers :");
        fgets(str, 256, stdin);
        str[strlen(str) - 1] = '\0';
        char *token = strtok(str, ", ");
        if (strcmp(token, "Q") == 0)
        {
            puts("BYE");
            return 0;
        }
        if (is_number(token) == 0)
        {
            printf("IOERROR: Input only numbers. Ex)1,2,3\n");
            continue;
        }
        num = atoi(token);
        // printf("%d\n", num);
        index++;
        sum += num;

        while (token = strtok(NULL, ", "))
        {
            num = atoi(token);
            // printf("%d\n", num);
            index++;
            sum += num;
        }

        printf("Sum: %d\n", sum);
        printf("Average: %.1f\n", (double)sum / (double)index);

        // return 0;
    }
}

int is_number(char *token)
{
    int digit = 1;
    for (int i = 0; i < strlen(token); i++)
    {
        if (isdigit(token[i]) == 0)
        {
            digit = 0;
            break;
        }
    }
    return digit;
}
