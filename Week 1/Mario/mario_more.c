#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j;
    do
    {
        n = get_int("Enter the height: ");
    }
    while (n < 1 || n > 8);

    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        for (j = 2; j >= 1; j--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
