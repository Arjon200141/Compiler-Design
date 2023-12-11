#include <stdio.h>

int main()
{
    char code[1000];
    int i, count = 0;

    printf("Enter the code:\n");
    scanf("%[^\n]s", code);

    // Check for unbalanced curly braces
    for (i = 0; code[i] != '\0'; i++)
    {
        if (code[i] == '{')
        {
            count++;
        }
        else if (code[i] == '}')
        {
            count--;
            if (count < 0)
            {
                printf("Error: Unbalanced curly braces.\n");
                return 1;
            }
        }
    }

    if (count == 0)
    {
        printf("No unbalanced curly braces found.\n");
    }
    else
    {
        printf("Error: Unbalanced curly braces.\n");
        return 1;
    }

    return 0;
}
