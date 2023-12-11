#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_valid(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return false;
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char iden[50];

    printf("Enter an identifier: ");
    scanf("%s", iden);

    if (is_valid(iden))
    {
        printf("'%s' is a valid identifier.\n", iden);
    }
    else
    {
        printf("'%s' is not a valid identifier.\n", iden);
    }

    return 0;
}
