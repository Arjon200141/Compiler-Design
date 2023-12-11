#include <stdio.h>

void genString(int n)
{
    if (n == 0)
    {
        printf("a");
        return;
    }
    printf("a");
    genString(n - 1);
    printf("X");
    return;
}

void genX(int n)
{
    if (n == 0)
    {
        return;
    }
    printf("bb");
    genX(n - 1);
    return;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    genString(n);
    printf("d\n");

    genX(n);
    printf("\n");

    return 0;
}

