#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);
float Coleman(int l, int w, int s);

int main()
{
    string sentence = get_string("Enter the sentence:");
    int l = count_letter(sentence);
    int w = count_word(sentence);
    int s = count_sentence(sentence);
    float index = Coleman(l,w,s);

    if(index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int)round(index));
    }
    return 0;
}

int count_letter(string text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_word(string text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count+1;
}

int count_sentence(string text)
{
    int count = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

float Coleman(int l, int w, int s)
{
    float value = 0;
    float L = 0;
    float S = 0;
    L = 100.0 * ((float)l / (float)w);
    S = 100.0 * ((float)s / (float)w);
    value = 0.0588 * L - 0.296 * S - 15.8;
    return value;
}
