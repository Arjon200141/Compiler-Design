#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char res[100],arg1[100],op[100],arg2[100],sym[100];
int main()
{
    char c;
    int i=0,j=0;
    printf("Enter expression with $ : ");
    while((c=getchar()) != '$')
    {
        res[i++]=c;
    }

    int n=i-1;
    void *ptr;

    printf("Symbol Table : \n");
    printf("Name\t\tAddress\t\tType\n");

    for(j=0; j<=n; j++)
    {
        c=res[j];
        if(isalpha(toascii(c)))
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t identifier\n",c,ptr);
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t operator\n",c,ptr);
        }
        else if(c=='(' || c==')' || c=='{' || c=='}')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t parentheses\n",c,ptr);
        }
        else if(c==';')
        {
            ptr = malloc(c);
            printf("%c\t\t%d\t\t semicolon\n",c,ptr);
        }

    }

    return 0;
}

/*
ter expression with $ : a+b-c*e;{$
Symbol Table :
Name            Address         Type
a               928208           identifier
+               928320           operator
b               928376           identifier
-               928488           operator
c               928544           identifier
*               926336           operator
e               926392           identifier
;               926504           semicolon
{               926576           parentheses
*/

