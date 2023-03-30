#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replace_char(const char *str, int len, char target, const char *replacement)
{
    int i;
    int replace_len = strlen(replacement);
    int new_len = len;

    for (i = 0; i < len; i++)
    {
        if (str[i] == target)
        {
            new_len += replace_len - 1;
        }
    }

    char *new_str = (char *)malloc(new_len + 1);

    if (new_str)
    {
        int j = 0;

        for (i = 0; i < len; i++)
        {
            if (str[i] == target)
            {
                memcpy(new_str + j, replacement, replace_len);
                j += replace_len;
            }
            else
            {
                new_str[j++] = str[i];
            }
        }

        new_str[j] = '\0';
    }

    return new_str;
}

int main()
{
    char str[] = "This is a string";
    printf("Before: %s\n", str);

    char *new_str = replace_char(str, strlen(str), 's', "th");

    if (new_str)
    {
        printf("After: %s\n", new_str);
        free(new_str);
    }

    return 0;
}