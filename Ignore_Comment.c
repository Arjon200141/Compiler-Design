#include <stdio.h>

int main()
{
    char c, next;
    int in_comment = 0;

    printf("Enter C source code:\n");

    while ((c = getchar()) != EOF)
    {
        if (in_comment == 0)
        {
            if (c == '/')
            {
                next = getchar();
                if (next == '/')
                {
                    in_comment = 1;
                }
                else if (next == '*')
                {
                    in_comment = 2;
                }
                else
                {
                    putchar(c);
                    putchar(next);
                }
            }
            else
            {
                putchar(c);
            }
        }
        else if (in_comment == 1)
        {
            if (c == '\n')
            {
                in_comment = 0;
                putchar(c);
            }
        }
        else if (in_comment == 2)
        {
            if (c == '*')
            {
                next = getchar();
                if (next == '/')
                {
                    in_comment = 0;
                }
            }
        }
    }

    return 0;
}

