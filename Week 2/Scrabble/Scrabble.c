#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_score(string word);

int main()
{
    string word1, word2;
    int score1, score2;

    word1 = get_string("Player1: ");
    word2 = get_string("Player2: ");

    score1 = count_score(word1);
    score2 = count_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int count_score(string word)
{
    int value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            sum += value[word[i] - 'A'];
        }
        else
        {
            sum += value[word[i] - 'a'];
        }
    }
    return sum;
}
