#include <stdio.h>
#include <stdbool.h>

int main()
{
    char c, next_char;
    bool in_s_comment = false;
    bool in_m_comment = false;
    int letterCount = 0;

    printf("Enter the source code :\n");

    while ((c = getchar()) != EOF)
    {
        if (in_s_comment)
        {
            if (c == '\n')
            {
                in_s_comment = false;
                putchar(c);
            }
            else
            {
                letterCount++;
            }
        }
        else if (in_m_comment)
        {
            if (c == '*' && (next_char = getchar()) == '/')
            {
                in_m_comment = false;
            }
            else
            {
                letterCount++;
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
                }
                else if (next_char == '*')
                {
                    in_m_comment = true;
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

    printf("\nTotal letters in comments: %d\n", letterCount);

    return 0;
}

