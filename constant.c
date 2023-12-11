#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isConstant(char *str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    while (isdigit(str[i]))
        i++;

    return str[i] == '\0';
}

int main()
{
    char a[100];
    printf("Enter a string: ");
    scanf("%s", a);

    if (isConstant(a))
    {
        printf("'%s' is an integer constant.\n", a);
    }
    else
    {
        printf("'%s' is not an integer constant.\n", a);
    }

    return 0;
}
