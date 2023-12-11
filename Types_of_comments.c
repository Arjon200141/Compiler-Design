#include <stdio.h>
#include <stdbool.h>
int main()
{
    char c, next_char;
    bool in_s_comment = false;
    bool in_m_comment = false;

    printf("Enter the source code:\n");

    while ((c = getchar()) != EOF)
    {
        if (in_s_comment)
        {
            if (c == '\n')
            {
                in_s_comment = false;
                putchar(c);
                printf(" (Single-line comment)\n");
            }
            else
            {
                putchar(c);
            }
        }
        else if (in_m_comment)
        {
            if (c == '*' && (next_char = getchar()) == '/')
            {
                in_m_comment = false;
                putchar(c);
                putchar(next_char);
                printf(" (Multi-line comment)\n");
            }
            else
            {
                putchar(c);
            }
        }
        else
        {
            if (c == '/')
            {
                next_char = getchar();
                if (next_char == '/')
                {
                    in_s_comment = true;
                    putchar(c);
                    putchar(next_char);
                }
                else if (next_char == '*')
                {
                    in_m_comment = true;
                    putchar(c);
                    putchar(next_char);
                }
                else
                {
                    putchar(c);
                    putchar(next_char);
                }
            }
            else
            {
                putchar(c);
            }
        }
    }

    return 0;
}
