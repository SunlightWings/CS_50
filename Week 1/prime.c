#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    for (int j = 2; j < number; j++)
    {
        if (number % j == 0) /// if no remainder, maybe composite. but loop throgh all j to see if its really composite
        {
            return false;
        }
    }
    if (number == 1)
    {
        return false; /// for loop doesn't check for 1, so we create a special case for 1
    }
    return true; /// if the number passes the loop (to test composite) and passes check for 1, then we are really sure its prime.
}
