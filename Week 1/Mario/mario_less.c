#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, i, j;
    do
    {
        n = get_int("Enter a number between 1 to 8:");
        // printf("Stored: %i\n", n);
    }
    while (n < 1 || n > 8);

    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j >= 1; j--) // always focus on INITIALIZATION of for loop in problems like these
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
