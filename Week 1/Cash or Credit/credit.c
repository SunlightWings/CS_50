#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool Luhn(long n);
int main()
{
    long int number;
    number = get_long("Enter the card number: ");

    int amex = number / pow(10, 13);
    int master = number / pow(10, 14);
    int visa1 = number / pow(10, 12);
    int visa2 = number / pow(10, 15);

    if (Luhn(number) == true)
    {
        if (amex == 34 || amex == 37)
        {
            printf("AMEX\n");
        }
        else if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (visa1 == 4 || visa2 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

bool Luhn(long n)
{
    int counter = 0;
    int sum = 0;
    int digit = 0;

    while (n > 0)
    {
        digit = n % 10;
        n /= 10;
        counter++;

        if (counter % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        // if (sum % 10 == 0)
        // {
        //     return true;
        // }
    }
    return (sum % 10 == 0);
}
