#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string ciphertext(string plaintext, int key);
bool is_numeric(string str);

int main(int argc, string argv[])
{
    if ((argc != 2) || atoi(argv[1]) < 1 || !is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plain = get_string("Enter the pain text:");
    // printf("plaintext:%s  ",plain);

    string cipher = ciphertext(plain, key);
    printf("ciphertext: %s\n", cipher);
    return 0;
}

string ciphertext(string plaintext, int key)
{
    int len = strlen(plaintext);
    int alpha = 0, shifted = 0;
    for (int i = 0; i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            alpha = plaintext[i] - 65;
            shifted = (alpha + key) % 26;
            // printf("%c\n",shifted+65);
            plaintext[i] = (char) (shifted + 65);
        }
        else if (islower(plaintext[i]))
        {
            alpha = plaintext[i] - 97;
            shifted = (alpha + key) % 26;
            // printf("%c\n",shifted+97);
            plaintext[i] = (char) (shifted + 97);
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }
    return plaintext;
}
bool is_numeric(string str)
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
